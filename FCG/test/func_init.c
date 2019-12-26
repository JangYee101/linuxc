
#include <stdio.h>

char * HELLO="hello world";

int func1(char *msg, int num)
{
	printf("%s\t%d\n", msg, num);
	return 0;
}

char * func2(char *msg, int num)
{
	printf("%s\t%d\n", msg, num);
	return HELLO;
}

int main(){
	int (*func1_p)(char*, int);
	char * (*func2_p)(char*, int);
	func1_p=func1;
	func2_p=func2;
	printf("func1_p is %d\n", func1_p("xixi", 4));
	printf("func2_p is %s\n", func1_p("haha", 8));
	printf("%s\n", HELLO);
	return 0;

}
