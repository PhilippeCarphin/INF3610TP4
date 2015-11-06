// ***********************************************************************
//
// Filename : CommandGenerator.cpp
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed May 29 12:52:32 EDT 2013
//
//
// ***********************************************************************

#include "CommandGenerator.h"
#include "SpaceDeviceUtility.h"
#include "PlatformDefinitions.h"
#include "ApplicationDefinitions.h"
#include "tlm"
#include <stdio.h>

CommandGenerator::CommandGenerator(sc_module_name name, double period, sc_time_unit unit, unsigned char id, bool verbose)
:SpaceBaseDevice(name, sc_time(period, unit), id, verbose) {
	m_operand1 = 0;
	m_operand2 = 0;
	m_operations[0] = '+';
	m_operations[1] = '-';
	m_operations[2] = 'x';
	m_operations[3] = '/';
	m_operationIndex = 0;
	m_operationIndex = 0;
	m_commandIndex = 0;
	sprintf(m_command, "%d%c%d\n", m_operand1, m_operations[m_operationIndex], m_operand2);
}

void CommandGenerator::before_end_of_elaboration() {
	SpaceBaseDevice::before_end_of_elaboration();
}

void CommandGenerator::SlaveRead(tlm::tlm_generic_payload& trans, sc_time& delay) {
	unsigned long* pulData32 = (unsigned long*)trans.get_data_ptr();
	*pulData32 = (unsigned long)getNextCharacter(getCommand());
	
	trans.set_response_status(tlm::TLM_OK_RESPONSE);
	delay += GetClockPeriod();
}

void CommandGenerator::SlaveWrite(tlm::tlm_generic_payload& trans, sc_time& delay) {
	trans.set_response_status(tlm::TLM_OK_RESPONSE);
	delay += GetClockPeriod();
}

const char* CommandGenerator::getCommand() {
	if (m_commandIndex == COMMAND_LENGTH) {
		prepareNextCommand();
		m_commandIndex = 0;
		sprintf(m_command, "%d%c%d\n", m_operand1, m_operations[m_operationIndex], m_operand2);
	}

	return m_command;
}

char CommandGenerator::getNextCharacter(const char* command) {
	return command[m_commandIndex++];
}

void CommandGenerator::prepareNextCommand() {
	m_operand2++;

	if (m_operand2 == 10) {
		m_operand1++;
		m_operand2 = 0;
	}

	if (m_operand1 == 10) {
		m_operationIndex++;
		m_operand1 = 0;
	}

	if (m_operationIndex == 5) {
		m_operationIndex = 0;
		while(1);
	}
}
