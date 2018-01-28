/*****输入字符输出ASCII*****/
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


/*****输入大写字符转换小写*****/
/*
#include "stdio.h"
int main (){
	char ch[5];
	char chr[5];
	
	KC:printf ("请输入四位验证码：");
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
			printf ("请输入正确的验证码(英文大小写及数字)\n\n");
			goto KC;
		}
	}
	
	printf ("\n您输入的是：");
	
	for (int i = 0;i < 4; i++){
		printf("%c",chr[i]);
	}
	
	printf ("\n");
	
	return 0;
}
*/


/*****运算表达式*****/
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

/*****计算优先级*****/
/*
#include "stdio.h"

int main (){
	int a = 10;
	printf ("%d\n",a+=a-=a*a);
	return 0;
}
*/