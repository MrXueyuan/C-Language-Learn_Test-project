/**This program example applies to A function that defines the maximum value of an input value and returns the maximum value.**/
/*
The program was written by ��˸�(17207080110)
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int maxArr (int *array,int length){			//��������
	int max_num = 0;	//�������
	
	printf("\nThe Array Length is :%d.\n\n",length);	//���ָ������ĳ��ȣ���ָ���ڴ�ռ��С��
	
	for (int i=0;i<length;i++){			//��������
        printf("\t>>>maxNumber-array[%d] is %d\n",i,array[i]);		//���ÿ��Ԫ�ص�ֵ
		
		if (array[i]> max_num) max_num = array[i];		//�ж������ֵ
	}
	
	return max_num;		//�����������
}

int main(void){
	
	int i =0;	//ѭ������
	char in_ch;		//�����ַ������ж�
	int count = 1;	//����ռ���չ��С����
	int *a = (int*)malloc(1*sizeof(int));	//Ϊָ��a�����ʼ��С�ڴ��
	int n;		//��ת����
	
	printf ("This program example applies to the average of Results.\n\n");
	printf ("Program was written by ��˸�(17207080110)\n\n");
	printf ("-------------------------\n\n");
	printf("Please enter an array (each element is separated by a space):\n");
	
	while(scanf("%d",&n)){		//��ȡ����
		
		a[i] = n;	//����ת�����е�����ת��ָ������
		
		i++;	//ѭ������
		
		if((in_ch = getchar()) == '\n')		//�ַ��������ж�
			break;  
		
		if(i>=count){  
			a = (int *)realloc(a,(i+1)*sizeof(int));	//���Ѿ����ڵ�һ���ڴ�����
			count += 1;		//�ռ��С����
		}
	}
	printf("\nThe Array\'s max number is %d.\n",maxArr(a,count));		//�������maxArr����������Ϊָ�����鼰�ռ��С
	return 0;
}


