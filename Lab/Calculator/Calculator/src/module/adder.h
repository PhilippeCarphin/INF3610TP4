// ***********************************************************************
//
// Filename : adder.h
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:53:16 EDT 2012
//
//
// ***********************************************************************
#ifndef ADDER_H
#define ADDER_H

#include "systemc.h"
#include "SpaceBaseModule.h"

class adder : public SpaceBaseModule
{
	public:

		SC_HAS_PROCESS(adder);

		///
		/// Constructor
		///
		adder(sc_module_name zName, double dClockPeriod, sc_time_unit Unit, unsigned char ucID, unsigned char ucPriority, bool bVerbose);

		///
		/// Members
		///
		void thread(void);

	private:

		///
		/// Members
		///
		long add(long operand1, long operand2);
		long readOperand();
		void sendResult(long data);
};

#endif
