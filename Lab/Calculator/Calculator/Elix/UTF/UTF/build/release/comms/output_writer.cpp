// ***********************************************************************
//
// Filename : output_writer.cpp
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:52:40 EDT 2012
//
//
// ***********************************************************************
#include "output_writer.h"
#include "PlatformDefinitions.h"
#include "ApplicationDefinitions.h"
#include "SpaceDisplay.h"
#include "SpaceDisplay.h"



#include "XilinxUARTRegisters.h"

//////////////////////////////////////////////////////////////////////////////
///
///	Constructor
///
//////////////////////////////////////////////////////////////////////////////
output_writer::output_writer(sc_module_name zName, double dClockPeriod, sc_time_unit ClockPeriodUnit, unsigned char ucID, unsigned char ucPriority, bool bVerbose)
: SpaceBaseModule( zName, dClockPeriod, ClockPeriodUnit, ucID, ucPriority, bVerbose )
{
 SC_THREAD(thread);
}

//////////////////////////////////////////////////////////////////////////////
///
///	Convert FIFO to UART
///
//////////////////////////////////////////////////////////////////////////////
void output_writer::thread(void)
{
 while(1)
 {
  send2UART(readFIFO());
 }
}

//////////////////////////////////////////////////////////////////////////////
///
///	Read a character from the FIFO
///
//////////////////////////////////////////////////////////////////////////////
unsigned long output_writer::readFIFO()
{
 unsigned long data;

 ModuleRead(1, SPACE_BLOCKING, &data);

    return data;
}

//////////////////////////////////////////////////////////////////////////////
///
///	Send data to UART
///
//////////////////////////////////////////////////////////////////////////////
void output_writer::send2UART(unsigned long data)
{



 unsigned long status;

 DeviceRead(8, 0x00000008ul /*|< Status Register*/, &status);
 while((status & 0x08 /*|< bit 28 : indicates if transmit FIFO is full*/) == 0x08 /*|< bit 28 : indicates if transmit FIFO is full*/)
 {
  wait(1);
  DeviceRead(8, 0x00000008ul /*|< Status Register*/, &status);
 }

 DeviceWrite(8, 0x00000004ul /*|< Transmit FIFO*/, &data);

}
