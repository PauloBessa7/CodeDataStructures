#include <stdio.h
>

int main(void) {

  int a = 100, *b, **c, ***d, ****e;
  b = &a;
  c = &b;
  d = &c;
  e = &d;

  printf("Endere�o de A: %p\tConteudo de A:%d\n", &a, a);
  printf("Endere�o de B: %p\tConteudo de B:%d\n", &b, b);
  printf("Conteudo apontado por B: %d\n", *b);
  printf("Endere�o de C: %p\tConteudo de C:%d\n", &c, c);
  printf("Conteudo apontado por C: %d\n", **c);
  printf("Endere�o de D: %p\tConteudo de D:%d\n", &d, d);
  printf("Conteudo apontado por D: %d\n", ***d);
  printf("Endere�o de E: %p\tConteudo de E:%d\n", &e, e);
  printf("Conteudo apontado por E: %d\n", ****e);
  
  
  return 0;
}
