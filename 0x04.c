#include "stdio.h"

int main (){
	
	int _p;
	char ch;
	
	printf ("����һ���ַ���");
	
	ch = getchar();
	
	if (ch>='0' && ch<='9'){
		_p="�����ַ�";
	}
	else if(ch>='A' && ch<='Z'){
		_p="��дӢ���ַ�";
	}
	else if(ch>='a' && ch<='z'){
		_p="СдӢ���ַ�";
	}
	else {
		_p="�����ַ�";
	}
	
	printf ("n��������ַ�%c��%s.\n",ch,_p);
	
	return 0;
}