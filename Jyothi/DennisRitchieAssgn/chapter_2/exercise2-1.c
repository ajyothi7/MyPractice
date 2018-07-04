#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main(void)
{
	//values from standard headers
	printf("range of signed char : %d to %d\n",SCHAR_MIN,SCHAR_MAX);
	printf("range of unsigned char : %d to %d\n",0,UCHAR_MAX);
	printf("range of signed short int : %d to %d\n",SHRT_MIN,SHRT_MAX);
	printf("range of unsigned short int : %d to %d\n",0,USHRT_MAX);
	printf("range of signed int : %d to %d\n",INT_MIN,INT_MAX);
	printf("range of unsigned int : %u to %u\n",0,UINT_MAX);
	printf("range of signed long int : %ld to %ld\n",LONG_MIN,LONG_MAX);
	printf("range of unsigned long int : %d to %lu\n",0,ULONG_MAX);

	printf("range of float :%e to %e\n",FLT_MIN,FLT_MAX);
	printf("range of double :%g to %g\n",DBL_MIN,DBL_MAX);

	printf("\n\n\n");

	//values by direct computation	
	printf("range of signed char : %d to %d\n",(int)-(pow(2,7)),(int)(pow(2,7) - 1));
	printf("range of unsigned char : %d to %d\n",0,(int)pow(2,8)-1);
	printf("range of signed short int : %d to %d\n",(int)-(pow(2,15)),(int)(pow(2,15)-1));
	printf("range of unsigned short int : %d to %d\n",0,(int)pow(2,16)-1);
	printf("range of signed int : %d to %d\n",(int)-(pow(2,31)),(int)(pow(2,31)-1));
	printf("range of unsigned int : %u to %u\n",0,(unsigned int)(pow(2,32)-1));
	printf("range of signed long int : %ld to %ld\n",(long int)-(pow(2,31)),(long int)(pow(2,31)-1));
	printf("range of unsigned long int : %d to %lu\n",0,(unsigned long)(pow(2,32)-1));

	printf("range of float :%e to %e\n",pow(2,-127),pow(2,127));
	return 0;
}
