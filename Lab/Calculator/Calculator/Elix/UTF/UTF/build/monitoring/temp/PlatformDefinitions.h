// ***********************************************************************
//
// Filename: 		PlatformDefinitions.h
//
// Level:			Elix
//
// Author: 			SpaceStudio generation engine
//
// Warning: 
// ========
//			1) This file content will be overwritten by the next generation process.
//			2) All the ID must be unique to the current project.
//
// ***********************************************************************

#ifndef PLATFORM_DEFINITIONS_H
#define PLATFORM_DEFINITIONS_H

//Level of technology of this platform
#define ELIX

// User's Module ID
#define ADDER_ID   0
#define CONTROLLER_ID   1
#define DIVIDER_ID   2
#define INPUT_READER_ID   3
#define MATRIX_MUL_ID   4
#define MULTIPLIER_ID   5
#define OUTPUT_WRITER_ID   6
#define SUBTRACTOR_ID   7

// User's Device(and Wrapper) ID
#define COMMANDGENERATOR_ID   12
#define TEMPORIZER_ID   13

// User's Module priority
#define ADDER_PRIO   1
#define CONTROLLER_PRIO   2
#define DIVIDER_PRIO   3
#define INPUT_READER_PRIO   4
#define MATRIX_MUL_PRIO   5
#define MULTIPLIER_PRIO   6
#define OUTPUT_WRITER_PRIO   7
#define SUBTRACTOR_PRIO   8

// User's Device(and Wrapper) priority

// SpaceComponents IDs
#define UART_ID   8
#define USERDEVICEEXTERNALIOSLAVE1_ID   11
#define USERDEVICEEXTERNALIOSLAVE2_ID   9
#define UTFCHANNEL1_ID   10

// SpaceComponents PRIOs

#endif //PLATFORM_DEFINITIONS_H
