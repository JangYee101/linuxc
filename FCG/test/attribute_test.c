
#include <stdio.h>

void __attribute__ ((constructor)) before_start_func(void){
	printf("here is brefore start\n");
}

void __attribute__ ((destructor)) later_end_func(void){
	printf("here is later end\n");
}



int main(){
	printf("hello world\n");
	return 0;
}
