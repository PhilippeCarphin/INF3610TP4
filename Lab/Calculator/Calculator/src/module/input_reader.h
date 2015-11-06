// ***********************************************************************
//
// Filename : input_reader.h
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 10:52:30 EDT 2012
//
//
// ***********************************************************************
#ifndef INPUT_READER_H
#define INPUT_READER_H

#include "systemc.h"
#include "SpaceBaseModule.h"

class input_reader : public SpaceBaseModule
{
	public:

		SC_HAS_PROCESS(input_reader);

		///
		/// Constructor
		///
		input_reader(sc_module_name zName, double dClockPeriod,  sc_time_unit Unit, unsigned char ucID, unsigned char ucPriority, bool bVerbose);

		///
		/// Methods
		///
		void thread(void);

	private:

		///
		/// Methods
		///
		unsigned long readUART();
		void send2FIFO(unsigned long data);
};

#endif
