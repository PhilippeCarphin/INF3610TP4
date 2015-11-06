// ***********************************************************************
//
// Filename : controller.h
//
// Author : SpaceStudio generation engine
//
// Creation date : Wed Oct 17 09:38:19 EDT 2012
//
//
// ***********************************************************************
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "systemc.h"
#include "SpaceBaseModule.h"

typedef enum {
	ADD,
	SUBTRACTION,
	MULTIPLY,
	DIVIDE
} Operation;

class controller : public SpaceBaseModule
{
	public:

		SC_HAS_PROCESS(controller);

		///
		/// Constructor
		///
		controller(sc_module_name zName, double dClockPeriod, sc_time_unit Unit, unsigned char ucID, unsigned char ucPriority, bool bVerbose);

		///
		/// Members
		///
		void thread(void);
	
	private:

		///
		/// Members
		///

		void sendResult(long data);
		void sendCharacter(unsigned char character);
		unsigned long readInput();
		void readData(long* operand1, long* operand2, Operation* operation);
		long getFirstOperand(unsigned char* ptr);
		long getSecondOperand(unsigned char* ptr);
		long convertCharacterToNumber(unsigned char* ptr, unsigned char length);
		bool isNegative(unsigned char character);
		bool isDigit(unsigned char character);
		bool isSpace(char character);
		bool isOperationCharacter(unsigned char character);
		unsigned long pow(int base, int exponent);
		int getOperationPosition(unsigned char* ptr);
		void readInputStream(unsigned char* ptr);
		void sanitize(unsigned char* ptr, int* position);
		bool isValidCommand(unsigned char* ptr);
		bool isDividedByZeroDetected(unsigned char* ptr);
		bool isOperationDetected(unsigned char* ptr);
		bool isOperand1Detected(unsigned char* ptr);
		bool isOperand2Detected(unsigned char* ptr);
		bool isNumber(unsigned char* ptr, unsigned char length);
		bool isLFDetected(unsigned char* ptr);
		int getLFPosition(unsigned char* ptr);
		bool isLF(unsigned char character);
		unsigned char* trimSpaces(unsigned char* ptr, unsigned char* length);
		Operation getOperation(unsigned char* ptr);
		long delegateOperation(Operation operation, long operand1, long operand2);
		void sendAdditionOperand(long data);
		void sendSubtractionOperand(long data);
		void sendMultiplicationOperand(long data);
		void sendDivisionOperand(long data);
		long readAdditionResult();
		long readSubtractionResult();
		long readMultiplicationResult();
		long readDivisionResult();
		void init(unsigned char* ptr);
		int atoi(unsigned char c);
		unsigned char itoa(unsigned int x);
		int getOrder(unsigned long data);
		void displayMessage(char* message);

};

#endif
