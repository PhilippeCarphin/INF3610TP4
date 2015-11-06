////////////////////////////////////////////////////////////////////////////////
//
// Author : SpaceStudio generation engine
//
// Warning: This file content will be overwritten by the next generation process.
//
////////////////////////////////////////////////////////////////////////////////
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>

#include <cstdlib>
#include <cstdio>
#include <cstring>

#define ACTIVATE_REGISTER_ACCESS 	0x11AAA11
#define DEACTIVATE_REGISTER_ACCESS	0x11BBB11

int main(int arg_count, char** arg_value) {
	int fd = open("/dev/mem", O_RDWR);
	if (fd < 0)
		printf("Error while opening /dev/mem \n");

	void* device_add = mmap(0, 0x10000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0x7FFF0000);
	if (device_add == MAP_FAILED)
		printf("Error while mapping virtual memory \n");

	volatile unsigned long* SPECIAL_REGISTER_ACCESS = (unsigned long*)((unsigned char*)device_add + 0xFFF0);
	volatile unsigned long* GDBSERVER_RDY = (unsigned long*)((unsigned char*)device_add + 0xFFEC);

	*SPECIAL_REGISTER_ACCESS = ACTIVATE_REGISTER_ACCESS;
	*GDBSERVER_RDY = 1;
	*SPECIAL_REGISTER_ACCESS = DEACTIVATE_REGISTER_ACCESS;

	if(munmap(device_add, 0x10000) == -1)
		printf("Error while unmapping virtual memory \n");
	close(fd);

    return 0;
}



