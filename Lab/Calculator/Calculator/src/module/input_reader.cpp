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
#ifdef GENX
	wait(1);
    return XUartPs_RecvByte(0xe0001000);
#else
	unsigned long status;
	unsigned long data;

	DeviceRead(UART_ID, UART_STATUS_REG_OFFSET, &status);
	while((status & UART_BIT_TX_FIFO_VALID_DATA)==0)
	{
		wait(1);
		DeviceRead(UART_ID, UART_STATUS_REG_OFFSET,&status);
	}
	DeviceRead(UART_ID, UART_RECEIVE_FIFO_REG_OFFSET, &data);

	return data;
#endif
}

//////////////////////////////////////////////////////////////////////////////
///
///	Send data to fifo
///
//////////////////////////////////////////////////////////////////////////////
void input_reader::send2FIFO(unsigned long data)
{
	ModuleWrite(CONTROLLER_ID, SPACE_BLOCKING, &data);
}
