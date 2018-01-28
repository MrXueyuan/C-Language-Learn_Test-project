/**This program example applies to 1000 square root operation**/
/*
The program was written by ÀîË¸å«(17207080110)
*/

//include Head File
#include "stdio.h"
#include "math.h"
#include "string.h"

/***Main***/
int main (){
	
	//Initialization var
	char num[4];
	int length;
	int con_num;
	double root_num;
	
	//OutHead
	printf 	("This program example applies to 1000 square root operation.\n\n");
	printf 	("Program was written by ÀîË¸å«(17207080110)\n");
	
	//Sign
RE:	;
	
	//Initialize
	memset(num,0,4);
	con_num = 0;
	root_num = 0;
	
	//IO
	printf	("\n-------------------------\n");
	printf	("\n");
	printf 	("Please enter a positive integer within 1000 £º");
	gets(num);
	
	//Judgment Information
	length=strlen(num);		//Length
	for	(int i=0;i<length;i++){
		if	(num[i]>='0'&&num[i]<='9');
		else{
			printf	("\n!!!\tError:Input contains illegal characters.\n");
			printf	("\tPlease re-enter!\n\n");
			goto RE;
		}
	}
	
	// Conversion
	sscanf	(num,"%d",&con_num);
	
	//Operation
	if	(con_num>=1000){
		printf	("\n!!!\tError:This is not a valid numeric input.\n");
		printf	("\tThe value is greater than 1000.\n");
		printf	("\tPlease re-enter!\n\n");
		goto RE;
	}
	else if	(con_num<=0){
		printf	("\n!!!\tError:The input value is not a non-0 positive integer.\n");
		printf	("\tThe value is less than or equal to ZERO.\n");
		printf	("\tPlease re-enter!\n\n");
		goto RE;
	}
	
	//Calculation
	root_num = sqrt(con_num);
	
	//IO
	printf	("\n>>>\tThe number you have entered is: %d .",con_num);
	printf	("\n>>>\tThe arithmetic square root of this number is: %g .",root_num);
	printf	("\n\n-------------------------\n");
	printf	("\n!!! Ctrl+C End Program !!!");
	
	//Cycle
	goto RE;
	
	return 0;
}