#include <stdio.h>

int doisPonteiro(char *v1, char *v2){
	
	int a = 0;
	while( v1[a] != '\0'){
		*(v2 + a) = *(v1 + a);
		a += 1;
	}

	return 0;
}

int main(void){
	char v1[10] = "paulo";
	char v2[10] ;
	
	int c = doisPonteiro(v1,v2);
	
	printf("%s", v2);
	
	return 0;
}
