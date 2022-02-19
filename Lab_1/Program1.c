#include<stdio.h>

void SizeOfVariables(void) {
char c;
short s;
int i;
unsigned int ui;
unsigned long int ul;
float f;
double d;
long double ld;
void *ptr;

printf("Size of char: %d bytes\n", sizeof(c));
printf("Size of short: %d bytes\n", sizeof(s));
printf("Size of int : %d bytes\n", sizeof(i));
printf("Size of unsigned int: %d byte\n", sizeof(ui));
printf("Size of unsigned long int : %d bytes\n", sizeof(ul));
printf("Size of float: %d bytes\n", sizeof(f));
printf("Size of double: %d bytes\n", sizeof(d));
printf("Size of long double: %d byte\n", sizeof(ld));
printf("size of ponter : %d byte\n",sizeof(*ptr));

}
