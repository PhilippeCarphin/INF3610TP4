// ***********************************************************************
//
// Filename : divider.cpp
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:52:58 EDT 2012
//
//
// ***********************************************************************
#include "divider.h"
#include "PlatformDefinitions.h"
#include "ApplicationDefinitions.h"
#include "SpaceDisplay.h"
#include "SpaceDisplay.h"

//////////////////////////////////////////////////////////////////////////////
///
///	Constructor
///
//////////////////////////////////////////////////////////////////////////////
divider::divider(sc_module_name zName, double dClockPeriod, sc_time_unit ClockPeriodUnit, unsigned char ucID, unsigned char ucPriority, bool bVerbose)
: SpaceBaseModule( zName, dClockPeriod, ClockPeriodUnit, ucID, ucPriority, bVerbose )
{
	SC_THREAD(thread);
}

//////////////////////////////////////////////////////////////////////////////
///
///	Division's algorithm
///
//////////////////////////////////////////////////////////////////////////////
void divider::thread(void)
{
	long operand1;
	long operand2;
	long result;

	while(1)
	{
		operand1 = readOperand();
		operand2 = readOperand();
		result = divide(operand1, operand2);
		sendResult(result);
	}
}

//////////////////////////////////////////////////////////////////////////////
///
///	Division
///
//////////////////////////////////////////////////////////////////////////////
long divider::divide(long operand1, long operand2)
{
	return operand1 / operand2;
}

//////////////////////////////////////////////////////////////////////////////
///
///	Read an operand
///
//////////////////////////////////////////////////////////////////////////////
long divider::readOperand()
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
void divider::sendResult(long data)
{
	ModuleWrite(CONTROLLER_ID, SPACE_BLOCKING, &data);
}
