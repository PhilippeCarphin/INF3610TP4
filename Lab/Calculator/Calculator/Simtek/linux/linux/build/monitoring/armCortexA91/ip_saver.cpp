////////////////////////////////////////////////////////////////////////////////
//
// Author : SpaceStudio generation engine
//
// Warning: This file content will be overwritten by the next generation process.
//
////////////////////////////////////////////////////////////////////////////////
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <sys/mman.h>
#include <fcntl.h>

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

#define ACTIVATE_REGISTER_ACCESS 	0x11AAA11
#define DEACTIVATE_REGISTER_ACCESS	0x11BBB11

void save_ip(volatile unsigned long* ip_saver) {
	int fd;
	struct ifreq ifr;

	fd = socket(AF_INET, SOCK_DGRAM, 0);
	ifr.ifr_addr.sa_family = AF_INET;
	strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);
	ioctl(fd, SIOCGIFADDR, &ifr);
	close(fd);
	char* full_ip = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
	char* token;
	token = strtok (full_ip,".");
	while (token != NULL) {
		*ip_saver = atoi(token);
		token = strtok (NULL, ".");
	}
}

int main(int arg_count, char** arg_value) {
	int fd = open("/dev/mem", O_RDWR);
	if (fd < 0)
		printf("Error while opening /dev/mem \n");

	void* device_add = mmap(0, 0x10000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0x7FFF0000);
	if (device_add == MAP_FAILED)
		printf("Error while mapping virtual memory \n");

	volatile unsigned long* SPECIAL_REGISTER_ACCESS = (unsigned long*)((unsigned char*)device_add + 0xFFF0);
	volatile unsigned long* IP_SAVER = (unsigned long*)((unsigned char*)device_add + 0xFFFC);

	*SPECIAL_REGISTER_ACCESS = ACTIVATE_REGISTER_ACCESS;
	save_ip(IP_SAVER);
	*SPECIAL_REGISTER_ACCESS = DEACTIVATE_REGISTER_ACCESS;

	if(munmap(device_add, 0x10000) == -1)
		printf("Error while unmapping virtual memory \n");
	close(fd);

    return 0;
}



