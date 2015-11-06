// ***********************************************************************
//
// Filename : subtractor.cpp
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:54:23 EDT 2012
//
//
// ***********************************************************************
#include "subtractor.h"
#include "PlatformDefinitions.h"
#include "ApplicationDefinitions.h"
#include "SpaceDisplay.h"
#include "SpaceDisplay.h"

//////////////////////////////////////////////////////////////////////////////
///
///	Constructor
///
//////////////////////////////////////////////////////////////////////////////
subtractor::subtractor(sc_module_name zName, double dClockPeriod, sc_time_unit ClockPeriodUnit, unsigned char ucID, unsigned char ucPriority, bool bVerbose)
: SpaceBaseModule( zName, dClockPeriod, ClockPeriodUnit, ucID, ucPriority, bVerbose )
{
	SC_THREAD(thread);
}

//////////////////////////////////////////////////////////////////////////////
///
///	Subtraction's algorithm
///
//////////////////////////////////////////////////////////////////////////////
void subtractor::thread(void)
{
	long operand1;
	long operand2;
	long result;

	while(1)
	{
		operand1 = readOperand();
		operand2 = readOperand();
		result = subtract(operand1, operand2);
		sendResult(result);
	}
}

//////////////////////////////////////////////////////////////////////////////
///
///	Subtraction
///
//////////////////////////////////////////////////////////////////////////////
long subtractor::subtract(long operand1, long operand2)
{
	return operand1 - operand2;
}

//////////////////////////////////////////////////////////////////////////////
///
///	Read an operand
///
//////////////////////////////////////////////////////////////////////////////
long subtractor::readOperand()
{
	long data;

	ModuleRead(CONTROLLER_ID, SPACE_BLOCKING, &data);

    return data;
}

//////////////////////////////////////////////////////////////////////////////
///
///	Send the result
///
//////////////////////////////////////////////////////////////////////////////
void subtractor::sendResult(long data)
{
	ModuleWrite(CONTROLLER_ID, SPACE_BLOCKING, &data);
}
