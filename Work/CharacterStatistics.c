/**This program example applies to Character statistics**/
/*
The program will count English characters, numeric characters, spaces, and other characters separately.
*/

//include Head File
#include "stdio.h"
#include "string.h"

/***Main***/
int main (){
	
	//Initialization var
	char *str;
	int length=0;
	
	//Counter
	int	letter=0,digital=0,spaces=0,other_ch=0;
	
	//OutHead
	printf 	("This program example applies to Character statistics.\n\n");
	printf 	("Program was written by ÀîË¸å«(17207080110)\n");
	printf	("\n-------------------------\n");
	
	//IO
RE:	printf	("\nPlease enter a string:\n");
	gets(str);
	
	//Initialize
	letter=0,digital=0,spaces=0,other_ch=0;
	
	//Judgment Information
	length=strlen(str);		//Length
	for	(int i=0;i<=length;i++){
		if	(str[i]>='0'&&str[i]<='9'){
			digital++;
		}
		else if	(str[i]>='A'&&str[i]<='Z'||str[i]>='a'&&str[i]<='z'){
			letter++;
		}
		else if	(str[i]==' '){
			spaces++;
		}
	}
	other_ch = length - (digital + letter + spaces);
	
	//IO
	printf	("\nYou entered the total characters is: %d.\n",length);
	printf	("Letter number is :%d.\tDigital number is :%d.\tSpaces number is :%d.\tAnd Other Char number is :%d.\t\n",letter,digital,spaces,other_ch);
	printf	("\n-------------------------\n");
	
	//return
	goto RE;
}
