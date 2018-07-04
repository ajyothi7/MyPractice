#include <stdio.h>
int bit_pattern(int, int *);
int showbits(int);

//#pragma pack(1)
//#pragma pack(2)

#if 0
struct stu {
	char a;
    short int b;
	int c;
	char d;//short int d;
	char e;
	short int f;
	char v;

}s={127,127,127,127,127,127,127};
#endif
//////////////////////////////
#if 0
struct stu {
	float a;
	double b;
	int c;
	short int d;
	char e;
	char f;
}s={1,1,1,1,1,1};
#endif
//////////////////////////////
#if 0
struct stu {
	int c;
	char g;
	struct tag {
		char c1;
//		int d1;
		char g1;
	}__attribute__((packed, aligned(1)))r;
	short int d;
	char a;
}s = {1,1,{1,1},1,1};

//__attribute__((packed, aligned(1)))s3={1,1,{1,1,1},1,1};
#endif
/////////////////////////////////
#if 0
struct stu {
	char a1;//int a1;
    char c;
    short int g;
//	char g;
    struct tag {
        char c1;
        char d1;
		char g2;
       //	int g1;//this struct member alignment dominent to other member alignment of parent structure
    }r;
    char d;
    char a;//int a;
}s={1,1,1,{1,1,1},1,1};
#endif
//////////////////////////

//#pragma pack(push,1)
#if 0
struct stu{
	int a;
	short int b;
	char c;
	union {
		char d;
		char e;
		struct{
			int f;
			int g;
			union{
				char h;
			}i;
		}j;
	}k;
	
	}s;
#endif
//#pragma pack(pop)
///////////////////////////
#if 0
struct stu {
      char a1;//int a1;
      char c;
      int g;
      struct {
          char c1;
      }t;
      char d;
      char a;//int a;
}s = {1,1,1,{1},1,1};
#endif
////////////////////////////

#if 0
#pragma pack(push,1)
struct{
    short int a;
    char b;
    short int c;
    }d = {127,127,1000};
#pragma pack(pop)

struct{
    short int a;
    char b;
    short int c;
    }e = {127,127,127};
#endif

#if 0
struct stu{
//	char a;
	double b;
//	int c;
	char e;
/*	struct str{
		int a;
		}t;*/
	}s;
#endif

//#pragma pack(2)
#if 0
struct stu{
	char a;
	//short int b;
	int b;
	char c;
	}s = {127,127,127};
#endif

///////////////////////////////////////////////`
int showbits(int p)
{
    int i = 0;

    for(i = 31;i >= 0; i--){
		printf("%d", p >> i & 1);
		if(i % 8 == 0)
			printf("\t");
    }
    printf("\n");

    return p;
}



int bit_pattern(int size, int *p)
{
	printf("\n---------    SIZE OF STRUCTURE : %d  -----------\n",size);
	printf("\nstructure base addr: %p\n",p);

	if (size > 24 && size <= 28) {
		printf("\n 28 Bytes:\t");
		printf("\n%p\t",(p+6));
         
		showbits(*(p+6));

		printf("\n 24 Bytes:\t");
		printf("\n%p\t",(p+5));		

		showbits(*(p+5));	

		printf("\n 20 Bytes:\t");
		printf("\n%p\t",(p+4));

        showbits(*(p+4));

        printf("\n 16 Bytes:\t");
		printf("\n%p\t",(p+3));

        showbits(*(p+3));

        printf("\n 12 Bytes:\t");
		printf("\n%p\t",(p+2));

        showbits(*(p+2));

        printf("\n 8  Bytes:\t");
		printf("\n%p\t",(p+1));

        showbits (*(p+1));

        printf("\n 4  Bytes:\t");
		printf("\n%p\t",(p));

        showbits(*p);
	}
      
	else if (size > 20 && size <= 24) {
		printf("\n 24 Bytes:\t");
		printf("\n%p\t",(p+5));		

		showbits(*(p+5));	

		printf("\n 20 Bytes:\t");
		printf("\n%p\t",(p+4));

        showbits(*(p+4));

        printf("\n 16 Bytes:\t");
		printf("\n%p\t",(p+3));

        showbits(*(p+3));

        printf("\n 12 Bytes:\t");
		printf("\n%p\t",(p+2));

        showbits(*(p+2));

        printf("\n 8  Bytes:\t");
		printf("\n%p\t",(p+1));

        showbits (*(p+1));

        printf("\n 4  Bytes:\t");
		printf("\n%p\t",(p));

        showbits(*p);
    }
	else if (size > 16 && size <= 20) {
    	printf("\n 20 Bytes:\t");
		printf("\n%p\t",(p+4));

        showbits(*(p+4));

        printf("\n 16 Bytes:\t");
		printf("\n%p\t",(p+3));

        showbits(*(p+3));

        printf("\n 12 Bytes:\t");
		printf("\n%p\t",(p+2));

        showbits(*(p+2));

        printf("\n 8  Bytes:\t");
		printf("\n%p\t",(p+1));

        showbits (*(p+1));

        printf("\n 4  Bytes:\t");
		printf("\n%p\t",(p));

        showbits(*p);
	}
	else if (size > 12 && size <= 16) {
		printf("\n 16 Bytes:\t"); 
//		printf("\n%d\n",*(p+3));
		printf("\n%p\t",p+3);

	    showbits(*(p+3));

        printf("\n 12 Bytes:\t");
//		printf("\n%d\n",*(p+2));
		printf("\n%p\t",p+2);

	    showbits(*(p+2));

		printf("\n 8  Bytes:\t");
//		printf("\n%d\n",*(p+1));
		printf("\n%p\t",p+1);

        showbits (*(p+1));

		printf("\n 4  Bytes:\t");
//		printf("\n%d\n",*(p));
		printf("\n%p\t",p);

	    showbits(*p);
	}
	else if (size > 8 && size <= 12) {
   		printf("\n 12 Bytes:\t");
		printf("\n%p\t",(p+2));

        showbits(*(p+2));

        printf("\n 8  Bytes:\t");
		printf("\n%p\t",(p+1));

        showbits (*(p+1));

        printf("\n 4  Bytes:\t");
		printf("\n%p\t",(p));

        showbits(*p);
	}
	else if(size > 4 && size <= 8) {
		printf("\n 8  Bytes:\t");
		printf("\n%p\t",(p+1));

        showbits (*(p+1));

        printf("\n 4  Bytes:\t");
		printf("\n%p\t",(p));

        showbits(*p);
   	}

	else if(size <= 4) {
		printf("\n 4  Bytes:\t"); 
		printf("\n%p\t",(p));

		showbits(*p);
   	}
	else
		printf("\nYour structure size more than 28bytes");


	printf("\t\t|\t\t|\t\t|\t\t|\t|\n");
	printf("\t\t31\t\t23\t\t15\t\t7\t0\n");

	return 0;
}

int main(void)
{
	struct stu a;

	printf("%u\n",sizeof(a));
	bit_pattern(sizeof(s), &s);

//	for push and pop	
/*    printf("sizeof %u\n",sizeof(d));
	bit_pattern(sizeof(d),&d);

    printf("sizeof %u\n",sizeof(e));
	bit_pattern(sizeof(e),&e);
*/
//	end push and pop

	return 0;

}




