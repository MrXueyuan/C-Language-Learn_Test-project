#include "stdio.h"

long factorial (int number){
	int i , product = 1 ;
	for (i=1;i<=number;i++){
		product*=i;
	}
	return product;
}

int main (){
	int num;
	printf("����׳���ֵ:");
	scanf ("%d",&num);
	printf("\n�׳�ֵΪ:%d.\n",factorial(num));
	return 0;
}