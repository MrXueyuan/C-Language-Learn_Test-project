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
	printf("输入阶乘数值:");
	scanf ("%d",&num);
	printf("\n阶乘值为:%d.\n",factorial(num));
	return 0;
}