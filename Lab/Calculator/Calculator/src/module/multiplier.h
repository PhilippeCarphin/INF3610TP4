// ***********************************************************************
//
// Filename : multiplier.h
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:52:49 EDT 2012
//
//
// ***********************************************************************
#ifndef MULTIPLIER_H
#define MULTIPLIER_H

#include "systemc.h"
#include "SpaceBaseModule.h"

class multiplier : public SpaceBaseModule
{
	public:

		SC_HAS_PROCESS(multiplier);

		///
		/// Constructor
		///
		multiplier(sc_module_name zName, double dClockPeriod, sc_time_unit Unit, unsigned char ucID, unsigned char ucPriority, bool bVerbose);

		///
		/// Members
		///
		void thread(void);

	private:

		///
		/// Members
		///
		long multiply(long operand1, long operand2);
		long readOperand();
		void sendResult(long data);
};

#endif
