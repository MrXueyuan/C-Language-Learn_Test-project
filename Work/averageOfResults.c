/**This program example applies to the average of Results**/
/*
The program was written by 李烁瀚(17207080110)
*/

/*清除本行
	printf ("\33[2K\r");
*/


#include "stdio.h"
#include "string.h"

/***Main***/
int main (){
	
	//Initialization
	char Snum[11];
	int length,counter;
	int a,b,c;
	counter = 0;
	
	//OutHead
	printf ("This program example applies to the average of Results.\n\n");
	printf ("Program was written by 李烁瀚(17207080110)\n\n");
	printf ("-------------------------\n\n");
	
	//Tip 1
RC:	printf ("Please enter your student's school number:");
	
	//input 1
	gets(Snum);
	
	//Judgment Information
	length=strlen(Snum);		//Length
	for(int i=0;i<length;i++){
		if(Snum[i]>='0'&&Snum[i]<='9');
		else {
			printf ("\n\n!Please enter a number consisting of 11 digits!\n\n");
			printf ("\n-------------------------\n");
			goto RC;
		}
	}
	
	printf ("\nPlease input Chinese, maths and English in three subjects:");
	
	printf ("\n\tChinese:");
	scanf  ("%d",&a);
	
	printf ("\n\tmaths:");
	scanf  ("%d",&b);

	printf ("\n\tEnglish:");
	scanf  ("%d",&c);
	
	//output 1
	printf ("Your student's school number is :");
	for (int i = 0;i<length;i++){
		printf ("%c",Snum[i]);
	}
	
	//output 
	printf ("\n\tYour average score is %d \n",(a+b+c)/3);
	
	return 0;
}