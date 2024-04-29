#include <stdio.h>

int main(void){
	int a,*b,**c,***d;
	
	a =2;
	
	b = &a;
	c = &b;
	d = &c;
	
	printf("%d %d %d %d",a , *b * 2,**c * 3 ,***d * 4);	  
	
	
	
	return 0;
}
