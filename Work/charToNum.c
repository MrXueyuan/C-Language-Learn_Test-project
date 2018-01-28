/**This program example applies to numeric characters converted to numeric values**/
/*
The program was written by ÀîË¸å«(17207080110)
*/

#include "stdio.h"

int main (){
	
	//Initialization
	char ch;
	
	//OutHead
	printf ("This program example applies to numeric characters converted to numeric values.\n\n");
	printf ("Program was written by ÀîË¸å«(17207080110)\n\n");
	printf ("-------------------------\n\n");
	
	//Tip
RE:	printf (">>Please enter a numeric character.\n");
	printf (">>");
	
	//In Put
	ch = getchar();
	getchar();
	
	//Judgment Information
	if (ch>='0'&&ch<='9'){
		
		//Out Put
		printf ("\n>>The decimal character represented by the character is:\n\t>>>%d\n",ch-48);
		printf ("\n-------------------------\n");
		printf ("     !!!One more time!!!     ");
		printf ("\n-------------------------\n\n\n");
	
	}
	else {
		printf ("\n!!!Please enter the number character!!!\n\n");
		printf ("\n-------------------------\n");
		goto RE;
	}
	
	//more
	goto RE;
	
	return 0;
}