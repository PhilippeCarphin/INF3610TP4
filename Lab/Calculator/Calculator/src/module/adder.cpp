// ***********************************************************************
//
// Filename : adder.cpp
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:53:16 EDT 2012
//
//
// ***********************************************************************
#include "adder.h"
#include "PlatformDefinitions.h"
#include "ApplicationDefinitions.h"
#include "SpaceDisplay.h"
#include "SpaceTypes.h"

//////////////////////////////////////////////////////////////////////////////
///
///	Constructor
///
//////////////////////////////////////////////////////////////////////////////
adder::adder(sc_module_name zName, double dClockPeriod, sc_time_unit ClockPeriodUnit, unsigned char ucID, unsigned char ucPriority, bool bVerbose)
: SpaceBaseModule( zName, dClockPeriod, ClockPeriodUnit, ucID, ucPriority, bVerbose )
{
	SC_THREAD(thread);
}


//////////////////////////////////////////////////////////////////////////////
///
///	Addition's algorithm
///
//////////////////////////////////////////////////////////////////////////////
void adder::thread(void)
{
	long operand1;
	long operand2;
	long result;

	while(1)
	{
		operand1 = readOperand();
		operand2 = readOperand();
		result = add(operand1, operand2);
		sendResult(result);
	}
}

//////////////////////////////////////////////////////////////////////////////
///
///	Addition
///
//////////////////////////////////////////////////////////////////////////////
long adder::add(long operand1, long operand2)
{
	return operand1 + operand2;
}

//////////////////////////////////////////////////////////////////////////////
///
///	Read an operand
///
//////////////////////////////////////////////////////////////////////////////
long adder::readOperand()
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
void adder::sendResult(long data)
{
	ModuleWrite(CONTROLLER_ID, SPACE_BLOCKING, &data);
}
