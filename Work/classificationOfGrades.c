/**This program example applies to classification of grades**/
/*
The program was written by ÀîË¸å«(17207080110)
*/

//include Head File
#include "stdio.h"
#include "string.h"

/***Main***/
int main (){
	
	//Initialization var
	char num[3];
	int o_num,length;
	char o_ch;
	
	//OutHead
	printf 	("This program example applies to classification of grades.\n\n");
	printf 	("Program was written by ÀîË¸å«(17207080110)\n");
	printf	("\n-------------------------\n");
	
	//Sign
RE:	;
	
	//Initialize
	memset(num,0,4);
	o_num = 0;
	
	//IO
	printf	("Please enter your grades:");
	gets(num);
	
	//Judgment Information
	length=strlen(num);		//Length
	for	(int i=0;i<length;i++){
		if	(num[i]>='0'&&num[i]<='9');
		else{
			printf	("\n!!!\tError:Input contains illegal characters.\n");
			printf	("\tPlease re-enter!\n\n");
			printf	("\n-------------------------\n");
			goto RE;
		}
	}
	
	// Conversion
	sscanf	(num,"%d",&o_num);
	
	//Operation
	if	(o_num>100){
		printf	("\n!!!\tError:This is not a valid numeric input.\n");
		printf	("\tThe value is greater than 100.\n");
		printf	("\tPlease re-enter!\n\n");
		printf	("\n-------------------------\n");
		goto RE;
	}
	else if	(o_num<=0){
		printf	("\n!!!\tError:The input value is not a non-0 positive integer.\n");
		printf	("\tThe value is less than or equal to ZERO.\n");
		printf	("\tPlease re-enter!\n\n");
		printf	("\n-------------------------\n");
		goto RE;
	}
	else if	(o_num>=90){
		o_ch = 'A';
	}
	else if	(o_num>=80){
		o_ch = 'B';
	}
	else if	(o_num>=70){
		o_ch = 'C';
	}
	else if	(o_num>=60){
		o_ch = 'D';
	}
	else{
		o_ch = 'E';
	}
	
	//IO
	printf	("Grades level is: %c.",o_ch);
	printf	("\n-------------------------\n");
	goto RE;
	
	return 0;
}
