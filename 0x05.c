#include "stdio.h"

int main (){
	int i =1,j = 1;
	double snum=0;
	while (j<=19){
		snum += i/(double)j;
		i+=1;
		j+=2;
	}
	printf	("%f\n",snum);
	return 0;
}
