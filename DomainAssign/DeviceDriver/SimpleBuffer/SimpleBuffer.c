#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/version.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/kernel.h>	//printk
#include <linux/slab.h> 	//kmalloc
#include <linux/fs.h>
#include <linux/errno.h>	//error codes
#include <linux/types.h>	//size_t
#include <linux/fcntl.h>
#include <asm/uaccess.h>
#include <linux/vmalloc.h>
#include <linux/uaccess.h>

#define ZERO 0
#define ONE 1
#define TWO 2
#define MEM_MAJOR 243
#define BUF_SIZE (1024 * 1024) 

MODULE_LICENSE("Dual BSD/GPL");

int mem_open(struct inode *inode, struct file *filp);
int mem_release(struct inode *inode, struct file *filp);
ssize_t mem_read(struct file *filp, char *buf, size_t count, loff_t *offset);
ssize_t mem_write(struct file *filp, const char *buf, size_t count, loff_t *offset);
static void __exit mem_exit(void);
loff_t mem_llseek(struct file *filp, loff_t off, int whence); 
static int __init mem_init(void);

static dev_t dev;
static struct cdev c_dev;
static struct class *cls;
//static char mem_buf[BUF_SIZE];

int openCount = ZERO;
int closeCount = ZERO;
int placeholder = ZERO;
static char *kmem_buf;

struct file_operations m_fops = {
  .owner = THIS_MODULE,
  .llseek = mem_llseek,
  .read	= mem_read,
  .open	= mem_open,
  .release = mem_release,
  .write = mem_write
};

int mem_open( struct inode *inode, struct file *filp) {
	
	openCount++;
	printk(KERN_INFO "Opening \"mem\" %d times\n", openCount);
	return ZERO;	

}
	
int mem_release( struct inode *inode, struct file *filp) {
	closeCount++;
	printk(KERN_INFO "Closing \"mem\" %d times\n",closeCount);
	return ZERO;	
}

loff_t mem_llseek(struct file *filp, loff_t off, int whence) {
   loff_t newpos;

   switch(whence) {
   case ZERO: /* SEEK_SET */
      newpos = off;
      break;

   case ONE: /* SEEK_CUR */
      newpos = filp->f_pos + off;
      break;

   case TWO: /* SEEK_END */
      newpos = BUF_SIZE - off;
      break;

   default: /* can't happen */
      return -EINVAL;
   }
   if (newpos < ZERO) return -EINVAL;
   filp->f_pos = newpos;
   return newpos;
}




ssize_t mem_read(struct file *filp, char __user *buf, size_t count, loff_t *offset)
{
	int bytesRead;
	int bytesToRead = count;
	char *data;

	if ((bytesToRead == ZERO)||(*offset >= BUF_SIZE)) {
		printk(KERN_INFO "Reached the end of the file\n");
		return ZERO; 
	}

	if( count + *offset >  BUF_SIZE)
		bytesToRead = BUF_SIZE - *offset;

	if( ZERO == (data = kmalloc( bytesToRead, GFP_KERNEL))) 
		return -ENOMEM;
		
	memcpy(data, kmem_buf + *offset, bytesToRead);

	
	bytesRead = bytesToRead - copy_to_user(buf, data, bytesToRead);
	printk(KERN_INFO "Reading %d bytes from mem %d offset\n", bytesToRead, (int)*offset);
	
	*offset += bytesRead;

	kfree(data);

	return bytesRead;	

}
 

ssize_t mem_write(struct file *filp, const char __user *buf, size_t count, loff_t *offset)
{
	int bytesTowrite;
	int byteswritten;
	int bytesavailable;
	char *data;	

	placeholder = ZERO;
	bytesavailable  = BUF_SIZE - *offset - placeholder ;

	if (bytesavailable > count)	{
		bytesTowrite = count;
	}
	else {
		bytesTowrite = bytesavailable;
	}
	
	if(ZERO == (data = kmalloc(bytesTowrite, GFP_KERNEL)))
		return -ENOMEM;


	byteswritten = bytesTowrite - copy_from_user( (void *) data, buf, bytesTowrite);

		
	
	if(byteswritten == ZERO) {
		printk(KERN_INFO "Mem is out of space\n");
	}
	else {
		
		memcpy(kmem_buf + *offset + placeholder, data, byteswritten);	
		printk(KERN_INFO "written %d bytes %d offset\n", byteswritten, (int)*offset);
		*offset += byteswritten;
		placeholder += byteswritten;
		

	}		

	kfree(data);
	return byteswritten;
}


static int __init  mem_init( void ) {
	int res;
	struct device *dev_res;	

	printk(KERN_INFO"allocating %d bytes of internal buffer. \n", BUF_SIZE);
	
	if( NULL == ( kmem_buf = vmalloc(BUF_SIZE))) {
		printk(KERN_ERR" ERROR : cannot allocate memmory!!!\n");
		return ONE;
	}
	
	memset((void *) kmem_buf, ZERO, BUF_SIZE);


	if( (res = alloc_chrdev_region(&dev, ZERO, ONE, "simple_driver")) < ZERO) {
		printk(KERN_INFO "simple_driver error in alloc_char_region\n");
		return res;
	}
	
	cdev_init(&c_dev, &m_fops);
	if( (res = cdev_add(&c_dev, dev, ONE)) < ZERO) {
		unregister_chrdev_region(dev, ONE);
		return (res);
	}
	
	if ( IS_ERR( cls = class_create(THIS_MODULE, "chardev"))) {
		cdev_del(&c_dev);	
		unregister_chrdev_region(dev,ONE);
		return PTR_ERR(cls);
	}
	
	if( IS_ERR(dev_res = device_create(cls, NULL, dev, NULL, "simple_driver"))) {
		class_destroy(cls);
		cdev_del(&c_dev);	
		unregister_chrdev_region(dev,ONE);
		return PTR_ERR(dev_res);
	}

	printk(KERN_INFO "registering module\n");
	return ZERO;
}

static void __exit mem_exit( void ) {
	
	device_destroy(cls, dev);
	class_destroy(cls);
	cdev_del(&c_dev);	
	unregister_chrdev_region(dev, ONE);
	
	vfree(kmem_buf);	

	printk(KERN_INFO "module unregistered\n");
	
}


module_init( mem_init);
module_exit(mem_exit);
