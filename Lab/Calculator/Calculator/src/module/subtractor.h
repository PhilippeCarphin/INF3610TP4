// ***********************************************************************
//
// Filename : subtractor.h
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:54:23 EDT 2012
//
//
// ***********************************************************************
#ifndef SUBTRACTOR_H
#define SUBTRACTOR_H

#include "systemc.h"
#include "SpaceBaseModule.h"

class subtractor : public SpaceBaseModule
{
	public:

		SC_HAS_PROCESS(subtractor);

		///
		/// Constructor
		///
		subtractor(sc_module_name zName, double dClockPeriod, sc_time_unit Unit, unsigned char ucID, unsigned char ucPriority, bool bVerbose);

		///
		/// Members
		///
		void thread(void);

	private:

		///
		/// Members
		///
		long readOperand();
		long subtract(long operand1, long operand2);
		void sendResult(long data);
};

#endif
