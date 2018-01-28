#include "stdio.h"

int main (){
	
	int _p;
	char ch;
	
	printf ("ÊäÈëÒ»¸ö×Ö·û£º");
	
	ch = getchar();
	
	if (ch>='0' && ch<='9'){
		_p="Êý×Ö×Ö·û";
	}
	else if(ch>='A' && ch<='Z'){
		_p="´óÐ´Ó¢ÎÄ×Ö·û";
	}
	else if(ch>='a' && ch<='z'){
		_p="Ð¡Ð´Ó¢ÎÄ×Ö·û";
	}
	else {
		_p="ÆäËû×Ö·û";
	}
	
	printf ("nÄãÊäÈëµÄ×Ö·û%cÊÇ%s.\n",ch,_p);
	
	return 0;
}