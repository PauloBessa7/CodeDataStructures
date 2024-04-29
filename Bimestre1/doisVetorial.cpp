#include <stdio.h>

int doisPonteiro(char *v1, char *v2){
	
	int a = 0;
	while( v1[a] != '\0'){
		a += 1;
	}
	
	int b =0;
	while( *(v2 + b) != '\0'){
		b += 1;
	}


	return a + b;
}

int main(void){
	char v1[10] = "1234567";
	char v2[92] = "89";
	
	int c = doisPonteiro(v1,v2);
	
	printf("%d", c);
	
	return 0;
}
