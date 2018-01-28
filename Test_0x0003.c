#include "stdio.h"
#include "conio.h"
//#include "curses.h"

int main (void){
	char ch;
	while (1){
		ch=getch();
		if (ch==8)	printf	("\b ");
		if (ch==13)	printf	("\n");
		if (ch==27)	break;
		putchar(ch);
	}
}

