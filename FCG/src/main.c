#define _GNU_SOURCE

#include <malloc.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dlfcn.h>

int (*_open) (const char * pathname, int flags, ...) = NULL;
int (*_mkdir) (const char *pathname, mode_t mode) = NULL;

int open(const char * pathname, int flags, ...){
	char buf[100]={0};
	getcwd(buf, 100);
	printf("open file %s\n", buf);
	//_open(pathname, flags, mode);
	return -1;
}

int mkdir(const char * pathname, mode_t mode){
	char buf[100]={0};
	getcwd(buf, 100);
	printf("mkdir %s\n", buf);
	_mkdir(pathname, mode);
	return 0;
}

int before_main(){
	_open = (int (*)(const char *, int , ...)) dlsym(RTLD_NEXT, "open");
	_mkdir = (int (*) (const char*, mode_t)) dlsym(RTLD_NEXT, "mkdir");
	return 0;
}


void __attribute__ ((constructor)) before_start_func(void){
	before_main();
	return ;
}

/*
int main(){
	return 0;
}*/
