/*****�����ַ����ASCII*****/
/*
#include "stdio.h"
int main (){
	char ch;
	
	printf ("Input you char:");
	
	ch = getchar();
	
	printf ("The char is:%c.\n",ch);
	printf ("The char ASCII namber is:%d.\n",ch);
	printf ("The char ASCII Hex is:%x.\n\a\a\a",ch);
	
	return 0;
	}
*/


/*****�����д�ַ�ת��Сд*****/
/*
#include "stdio.h"
int main (){
	char ch[5];
	char chr[5];
	
	KC:printf ("��������λ��֤�룺");
	scanf( "%5s",ch);
	
	for (int i = 0;i < 4; i++){
		
		int j = 0;
		j = ch[i];
		
		if (j >= 65&&j<90){
			chr[i] = j ;
		}
		else if (j >= 97&&j < 122){
			chr[i] = j -32;
		}
		else if (j >= 48&&j < 57){
			chr[i] = j ;
		}
		else {
			printf ("��������ȷ����֤��(Ӣ�Ĵ�Сд������)\n\n");
			goto KC;
		}
	}
	
	printf ("\n��������ǣ�");
	
	for (int i = 0;i < 4; i++){
		printf("%c",chr[i]);
	}
	
	printf ("\n");
	
	return 0;
}
*/


/*****������ʽ*****/
/*
#include "stdio.h"
int main (){
	float a = 1.7,b = 2.7;
	printf ("a=1.7,b=2.7\n");
	printf ("a/2+3*-2/(a+b)-12");
	printf (" = %f\n",(a/2+3*-2/(a+b)-12));
	return 0;
}
*/

/*****�������ȼ�*****/
/*
#include "stdio.h"

int main (){
	int a = 10;
	printf ("%d\n",a+=a-=a*a);
	return 0;
}
*/