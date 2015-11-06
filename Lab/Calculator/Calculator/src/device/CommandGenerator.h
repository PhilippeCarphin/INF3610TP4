#ifndef CommandGenerator_H_
#define CommandGenerator_H_

#include <systemc.h>

#include "SpaceDisplay.h"
#include "SpaceBaseDevice.h"
#include "SpaceBaseMasterDevice.h"

#define COMMAND_LENGTH 4

class CommandGenerator: public SpaceBaseDevice {
	public:

		CommandGenerator(sc_module_name name, double period, sc_time_unit unit, unsigned char id, bool verbose);
		~CommandGenerator() { }

		virtual void SlaveRead(tlm::tlm_generic_payload& trans, sc_time& delay);
		virtual void SlaveWrite(tlm::tlm_generic_payload& trans, sc_time& delay);

		void before_end_of_elaboration();
	
	private:

		const char* getCommand();
		char getNextCharacter(const char* command);
		void prepareNextCommand();

		unsigned int m_commandIndex;

		int m_operand1;
		int m_operand2;

		char m_command[COMMAND_LENGTH+1];
		char m_operations[4];
		unsigned int m_operationIndex;
};

#endif
