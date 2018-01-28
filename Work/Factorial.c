#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "assert.h"
#include "windows.h"

int main(int argc,char *argv[])
{
	int i,j=1,n;
	long long l=0;
	printf("Input n: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		j*=i;
	}
	printf("Factorial=%ld\n",j);
	
	return 0;
}

