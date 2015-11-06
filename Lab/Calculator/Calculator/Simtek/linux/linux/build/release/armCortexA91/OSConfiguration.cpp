////////////////////////////////////////////////////////////////////////////////
//
// Filename : OS Configuration File
//
// Author : SpaceStudio generation engine
//
// Warning: This file content will be overwritten by the next generation process.
//
////////////////////////////////////////////////////////////////////////////////

#include	"OSConfiguration.h"
#include	<semaphore.h>
#include	<sched.h>

sem_t g_SemaphoreTbl[13];
pthread_t g_ThreadTbl[1];
pthread_attr_t g_AttrTbl[1];
sched_param g_ParamTbl[1];
arg_struct g_ArgTbl[1];
unsigned long g_ulOSStackSize = 0x400000;
unsigned long g_ulOSHeapSize = 0x0;

