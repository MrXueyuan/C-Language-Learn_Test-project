/*
	Visual Studio 2010
	老师的编译环境
*/
/*
#include "stdio.h"					//预编译头文件 标准输入输出

int main (void)						//整数类型，空参数，void表示空
{
	int nam1,nam2,ccnam;
	
	printf ("Hello World !\n");		//调用stdio.h头文件的printf函数，并传入字符串，通过转义字符换行。
	
	printf("Input you first namber:");
	scanf("%f",&nam1);
	
	printf("Input you senced namber:");
	scanf("%f",&nam2);
	
	printf("Add all namber is:%f.\n",ccnam);
	
	return 0;						//返回空指针
}
*/

/*
C语言
掌握库函数
了解结构特点
*/

/*
	main为主函数
*/

/*
#include "stdio.h"
int main (void){
	int d_cube_a,d_cube_b;
	
	printf 	("Input the Cube a and b :\n");
	printf 	("Name A:");
	scanf 	("%d",&d_cube_a);
	printf 	("Name B:");
	scanf 	("%d",&d_cube_b);
	printf 	("The Cube area is %d.\n",d_cube_a*d_cube_b);
	
	return 0;
}
*/

#include "stdio.h"

int max ();
int min ();

int max_num,min_num;
char test_a;

int main (){
	int x,y,z;
	printf ("Input you Number:\n");
	
	
	printf ("\nX = ");
	scanf("%d",&x);
	printf ("\nY = ");
	scanf("%d",&y);
	printf ("\nZ = ");
	scanf("%d",&z);
	
	printf ("\n");
	
	printf ("The Max number is %d.\n",max(x,y,z));
	printf ("The Min number is %d.\n",min(x,y,z));
	
	return 0;
	
}


int max (int x,int y,int z){
	max_num = 0;
	
	if (x>y)
		max_num = x;
	else if (z>x)
		max_num = z;
	else
		max_num = y;
	
	return (max_num);
}

int min (int x,int y,int z){
	min_num = 0;
	
	if (x<y)
		min_num = x;
	else if (z<x)
		min_num = z;
	else
		min_num = y;
	
	return (min_num);
}






















