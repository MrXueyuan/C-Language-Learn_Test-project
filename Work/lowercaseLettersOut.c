/**This program example applies to English letter Case Conversion and ASCII code**/
/*
The program was written by ÀîË¸å«(17207080110)
*/

/*Program source code encoded in ANSI format to achieve Chinese output.*/

#include "stdio.h"

/***Main***/
int main (){
	
	//Initialization
	char ch;
	char cho;
	
	//OutHead
	printf ("This program example applies to English letter Case Conversion and ASCII code.\n\n");
	printf ("Program was written by ÀîË¸å«(17207080110)\n\n");
	printf ("-------------------------\n\n");
	
	//Interaction
RE:	printf ("Please enter the English case or number:");
	ch = getchar();
	
	//Operation
	if (ch >= 65&&ch<90){
		cho = ch + 32;
	}
	else if (ch >= 97&&ch < 122){
		cho = ch - 32;
	}
	else if (ch >= 48&&ch < 57){
		cho = ch;
	}
	else {
		printf ("!!!Please enter the correct numeric value (in English case or number)!!!\n\n");
		goto RE;
	}
	
	//Basic output
	printf ("\nYou have entered:%c.\n\tIts decimal ASCII value is:%d,\n\tIts hexadecimal ASCII value is:%x.",cho,cho,cho);
	printf ("\n-------------------------\n\n");
	

	return 0 ;
}