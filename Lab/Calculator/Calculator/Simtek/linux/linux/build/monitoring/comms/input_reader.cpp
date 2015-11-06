// ***********************************************************************
//
// Filename : input_reader.cpp
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:52:30 EDT 2012
//
//
// ***********************************************************************
#include "input_reader.h"
#include "PlatformDefinitions.h"
#include "ApplicationDefinitions.h"
#include "SpaceDisplay.h"
#include "SpaceTypes.h"



#include "XilinxUARTRegisters.h"


//////////////////////////////////////////////////////////////////////////////
///
///	Constructor
///
//////////////////////////////////////////////////////////////////////////////
input_reader::input_reader(sc_module_name zName, double dClockPeriod, sc_time_unit ClockPeriodUnit, unsigned char ucID, unsigned char ucPriority, bool bVerbose)
: SpaceBaseModule( zName, dClockPeriod, ClockPeriodUnit, ucID, ucPriority, bVerbose )
{
 SC_THREAD(thread);
}

//////////////////////////////////////////////////////////////////////////////
///
///	Convert UART to FIFO
///
//////////////////////////////////////////////////////////////////////////////
void input_reader::thread(void)
{
 while(1)
 {
  send2FIFO(readUART());
 }
}


//////////////////////////////////////////////////////////////////////////////
///
///	Read a character from the uart
///
//////////////////////////////////////////////////////////////////////////////
unsigned long input_reader::readUART()
{




 unsigned long status;
 unsigned long data;

 DeviceRead(8, 0x00000008ul /*|< Status Register*/, &status);
 while((status & 0x01 /*|< bit 31 : indicates if receive FIFO contains a valid data*/)==0)
 {
  wait(1);
  DeviceRead(8, 0x00000008ul /*|< Status Register*/,&status);
 }
 DeviceRead(8, 0x00000000ul /*|< Receive FIFO*/, &data);

 return data;

}

//////////////////////////////////////////////////////////////////////////////
///
///	Send data to fifo
///
//////////////////////////////////////////////////////////////////////////////
void input_reader::send2FIFO(unsigned long data)
{
 ModuleWrite(1, SPACE_BLOCKING, &data);
}
