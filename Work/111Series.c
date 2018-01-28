//南春中学极客科技社C语言快速模板
//ncgeek.cn	Join us
//build by Mr_Xueyuan 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "assert.h"

int main(int argc,char *argv[])
{
	int i,n,k=0,s=0,c=0;
	printf("Input n: ");
	scanf("%d",&n);
	printf("\nInput c: ");
	scanf("%d",&c);
	for(i=0;i<n;i++)
	{
		k=k*10+c;
		s+=k;
	}
	printf("sum=%d\n",s);
	return 0;
}

