#include "stdio.h"
#include "conio.h"

int main (){
	char ch;
	while (1){
		ch = getch();
		if(ch=='~')
			break;
		putchar('!');
	}
}