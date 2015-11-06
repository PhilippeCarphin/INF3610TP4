// ***********************************************************************
//
// Filename : multiplier.cpp
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:52:49 EDT 2012
//
//
// ***********************************************************************
#include "multiplier.h"
#include "PlatformDefinitions.h"
#include "ApplicationDefinitions.h"
#include "SpaceDisplay.h"
#include "SpaceTypes.h"

//////////////////////////////////////////////////////////////////////////////
///
///	Constructor
///
//////////////////////////////////////////////////////////////////////////////
multiplier::multiplier(sc_module_name zName, double dClockPeriod, sc_time_unit ClockPeriodUnit, unsigned char ucID, unsigned char ucPriority, bool bVerbose)
: SpaceBaseModule( zName, dClockPeriod, ClockPeriodUnit, ucID, ucPriority, bVerbose )
{
	SC_THREAD(thread);
}

//////////////////////////////////////////////////////////////////////////////
///
///	Multiplication's algorithm
///
//////////////////////////////////////////////////////////////////////////////
void multiplier::thread(void)
{
	long operand1;
	long operand2;
	long result;

	while(1)
	{
		operand1 = readOperand();
		operand2 = readOperand();
		result = multiply(operand1, operand2);
		sendResult(result);
	}
}

//////////////////////////////////////////////////////////////////////////////
///
///	Multiplication
///
//////////////////////////////////////////////////////////////////////////////
long multiplier::multiply(long operand1, long operand2)
{
	return operand1 * operand2;
}

//////////////////////////////////////////////////////////////////////////////
///
///	Read an operand
///
//////////////////////////////////////////////////////////////////////////////
long multiplier::readOperand()
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
void multiplier::sendResult(long data)
{
	ModuleWrite(CONTROLLER_ID, SPACE_BLOCKING, &data);
}
