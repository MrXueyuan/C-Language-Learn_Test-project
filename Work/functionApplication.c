/**This program example applies to A function that defines the maximum value of an input value and returns the maximum value.**/
/*
The program was written by 李烁瀚(17207080110)
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int maxArr (int *array,int length){			//参数输入
	int max_num = 0;	//输出变量
	
	printf("\nThe Array Length is :%d.\n\n",length);	//输出指针数组的长度（即指针内存空间大小）
	
	for (int i=0;i<length;i++){			//遍历数组
        printf("\t>>>maxNumber-array[%d] is %d\n",i,array[i]);		//输出每个元素的值
		
		if (array[i]> max_num) max_num = array[i];		//判断最大数值
	}
	
	return max_num;		//返回输出变量
}

int main(void){
	
	int i =0;	//循环变量
	char in_ch;		//输入字符结束判断
	int count = 1;	//输入空间拓展大小变量
	int *a = (int*)malloc(1*sizeof(int));	//为指针a分配初始大小内存块
	int n;		//中转变量
	
	printf ("This program example applies to the average of Results.\n\n");
	printf ("Program was written by 李烁瀚(17207080110)\n\n");
	printf ("-------------------------\n\n");
	printf("Please enter an array (each element is separated by a space):\n");
	
	while(scanf("%d",&n)){		//获取输入
		
		a[i] = n;	//将中转变量中的数据转入指针数组
		
		i++;	//循环增量
		
		if((in_ch = getchar()) == '\n')		//字符串结束判断
			break;  
		
		if(i>=count){  
			a = (int *)realloc(a,(i+1)*sizeof(int));	//将已经存在的一段内存扩大
			count += 1;		//空间大小增量
		}
	}
	printf("\nThe Array\'s max number is %d.\n",maxArr(a,count));		//输出调用maxArr函数，参数为指针数组及空间大小
	return 0;
}


