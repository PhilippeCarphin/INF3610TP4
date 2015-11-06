////////////////////////////////////////////////////////////////////////////////
//
// Filename : communication.cpp
//
// Author : SpaceStudio generation engine
//
// Warning: This file content will be overwritten by the next generation process.
//
////////////////////////////////////////////////////////////////////////////////

#include "PlatformDefinitions.h"
#include "EntryClass.h"
#include "CommunicationAPI.h"


//
// Processor-specific devices addresses
//
#define ISS_ADAPTER_BASE_ADDRESS 0x40000000
unsigned long g_ulISSAdapterAddress =  ISS_ADAPTER_BASE_ADDRESS;
#define PIC_BASE_ADDRESS 0x4100D000
unsigned long g_ulPICAddress = PIC_BASE_ADDRESS;
unsigned long g_ulTimerClockFrequency = 800000000;
unsigned long g_ulTimerTickFrequency = 100;
#define STDOUT_BASE_ADDRESS 0x4100C000
unsigned long g_ulStdoutAddress = STDOUT_BASE_ADDRESS;
#define STDIN_BASE_ADDRESS 0x4100C000
unsigned long g_ulStdinAddress = STDIN_BASE_ADDRESS;

//
// Software properties
//
const unsigned long g_ulModuleStackSize = 16384;
const unsigned long g_ulSemNumber = 12;
__attribute__ ((aligned (8))) unsigned char 	g_StackTbl[0];
void* 			g_SemTbl[12];
EntryClass 		g_EntryClassPoolTbl[1];

