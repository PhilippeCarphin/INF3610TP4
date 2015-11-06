////////////////////////////////////////////////////////////////////////////////
//
// Filename : mainarmCortexA91.cpp
//
// Author : SpaceStudio generation engine
//
// Warning: This file content will be overwritten by the next generation process.
//
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C"
{
#endif
	int sc_main(int arg_count, char **arg_value);
#ifdef __cplusplus	
}	
#endif
	
#include "ApplicationDefinitions.h"
#include "PlatformDefinitions.h"
#include "controller.h"
#include "OSConfiguration.h"
#include <sys/mman.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "systemc"

using sc_core::SC_SEC;
using sc_core::SC_MS;
using sc_core::SC_US;
using sc_core::SC_NS;
using sc_core::SC_PS;				
using sc_core::SC_FS;

#define ACTIVATE_REGISTER_ACCESS 	0x11AAA11
#define DEACTIVATE_REGISTER_ACCESS	0x11BBB11

void exit(void) {
	int fd = open("/dev/mem", O_RDWR);
	if (fd < 0)
		printf("Error while opening /dev/mem \n");

	void* device_add = mmap(0, 0x10000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0x7FFF0000);
	if (device_add == MAP_FAILED)
			printf("Error while mapping virtual memory \n");

	volatile unsigned long* ENABLE_REGISTER_ACCESS = (unsigned long*)((unsigned char*)device_add + 0xFFF0);
	volatile unsigned long* END_OF_APPLICATION = (unsigned long*)((unsigned char*)device_add + 0xFFF8);

	*ENABLE_REGISTER_ACCESS = ACTIVATE_REGISTER_ACCESS;
	*END_OF_APPLICATION = 1;
	*ENABLE_REGISTER_ACCESS = DEACTIVATE_REGISTER_ACCESS;
}


int sc_main(int arg_count, char **arg_value)
{
	atexit(exit);

	int fd = open("/dev/mem", O_RDWR);
	if (fd < 0)
		printf("Error while opening /dev/mem \n");

	void* device_add = mmap(0, 0x10000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0x7FFF0000);
	if (device_add == MAP_FAILED)
		printf("Error while mapping virtual memory \n");

	volatile unsigned long* SPECIAL_REGISTER_ACCESS = (unsigned long*)((unsigned char*)device_add + 0xFFF0);
	volatile unsigned long* START_OF_APPLICATION = (unsigned long*)((unsigned char*)device_add + 0xFFF4);

	*SPECIAL_REGISTER_ACCESS = ACTIVATE_REGISTER_ACCESS;
	*START_OF_APPLICATION = syscall(SYS_gettid);
	*SPECIAL_REGISTER_ACCESS = DEACTIVATE_REGISTER_ACCESS;

	// Module(s) instantiation
		
	controller controller1("controller1", 10, SC_NS, CONTROLLER_ID, CONTROLLER_PRIO, false);	
	
	// Simulation section  -- Begin
	
	sc_core::sc_start();

	// Simulation section  -- End
	
	if(munmap(device_add, 0x10000) == -1)
		printf("Error while unmapping virtual memory \n");
	close(fd);

	
    return 0; // No problem occurs
}
