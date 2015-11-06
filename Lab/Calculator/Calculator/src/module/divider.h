// ***********************************************************************
//
// Filename : divider.h
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:52:58 EDT 2012
//
//
// ***********************************************************************
#ifndef DIVIDER_H
#define DIVIDER_H

#include "systemc.h"
#include "SpaceBaseModule.h"

class divider : public SpaceBaseModule
{
	public:

		SC_HAS_PROCESS(divider);

		///
		/// Constructor
		///
		divider(sc_module_name zName, double dClockPeriod, sc_time_unit Unit, unsigned char ucID, unsigned char ucPriority, bool bVerbose);

		///
		/// Members
		///
		void thread(void);

	private:

		///
		/// Members
		///
		long readOperand();
		long divide(long operand1, long operand2);
		void sendResult(long data);
};

#endif
