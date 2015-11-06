// ***********************************************************************
//
// Filename : output_writer.h
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:52:40 EDT 2012
//
//
// ***********************************************************************
#ifndef OUTPUT_WRITER_H
#define OUTPUT_WRITER_H

#include "systemc.h"
#include "SpaceBaseModule.h"

class output_writer : public SpaceBaseModule
{
	public:

		SC_HAS_PROCESS(output_writer);

		///
		/// Constructor
		///
		output_writer(sc_module_name zName, double dClockPeriod, sc_time_unit Unit, unsigned char ucID, unsigned char ucPriority, bool bVerbose);

		///
		/// Methods
		///
		void thread(void);

	private:

		///
		/// Methods
		///
		unsigned long readFIFO();
		void send2UART(unsigned long data);
};

#endif
