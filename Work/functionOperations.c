#include "stdio.h"

int add_ (int a,int b){
	int c =a+b;
	return c;
}

int main (void){
	int a,b;
	scanf ("%d %d",&a,&b);
	printf ("sum is :%d.\n",add_(a,b));
	return 0;
}
