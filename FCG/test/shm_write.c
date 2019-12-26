
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

enum shm_type {
	SHM_READ, SHM_WRITE,
};

char * shm_init(enum shm_type p_shm_type){
	void * shm_buf=(void *)-1;
	int fd;
	if(p_shm_type == SHM_READ){
		fd = open("shm_config", O_RDONLY);
		shm_buf = mmap(NULL, 100, PROT_READ, MAP_SHARED, fd, 0);
	}
	else{
		fd = open("shm_config", O_CREAT|O_RDWR, 0664);
		//改变文件大小
		ftruncate(fd, 100);
		shm_buf = mmap(NULL, 100, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
		
	}
	close(fd);
	return shm_buf;
}


int main(){

	float i=0;
	char * shm_buf = shm_init(SHM_WRITE);
	char p[10]={0};
	for(i=0; i < 100; i++){
		gcvt(i, 10, p);
		strcpy(shm_buf, p);
		printf("%s\n", shm_buf);
		sleep(1);
	}
	return 0;
	
}
