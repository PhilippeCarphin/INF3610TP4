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
#ifdef GENX
#include "xuartps_hw.h"
#else
#include "XilinxUARTRegisters.h"
#endif
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

	ModuleRead(CONTROLLER_ID, SPACE_BLOCKING, &data);

    return data;
}

//////////////////////////////////////////////////////////////////////////////
///
///	Send data to UART
///
//////////////////////////////////////////////////////////////////////////////
void output_writer::send2UART(unsigned long data)
{
#ifdef GENX
	XUartPs_SendByte(0xe0001000, (unsigned char)data);
#else
	unsigned long status;

	DeviceRead(UART_ID, UART_STATUS_REG_OFFSET, &status);
	while((status & UART_BIT_TX_FIFO_FULL) == UART_BIT_TX_FIFO_FULL)
	{
		wait(1);
		DeviceRead(UART_ID, UART_STATUS_REG_OFFSET, &status);
	}

	DeviceWrite(UART_ID, UART_TRANSMIT_FIFO_REG_OFFSET, &data);
#endif
}
