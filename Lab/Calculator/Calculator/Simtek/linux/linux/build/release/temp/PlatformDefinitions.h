// ***********************************************************************
//
// Filename: 		PlatformDefinitions.h
//
// Level:			Simtek
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
#define SIMTEK

// User's Module ID
#define ADDER_ID   0
#define CONTROLLER_ID   1
#define DIVIDER_ID   2
#define INPUT_READER_ID   3
#define MATRIX_MUL_ID   21
#define MULTIPLIER_ID   4
#define OUTPUT_WRITER_ID   5
#define SUBTRACTOR_ID   6

// User's Device(and Wrapper) ID
#define COMMANDGENERATOR_ID   10
#define TEMPORIZER_ID   11

// User's Module priority
#define ADDER_PRIO   3
#define CONTROLLER_PRIO   4
#define DIVIDER_PRIO   5
#define INPUT_READER_PRIO   6
#define MATRIX_MUL_PRIO   9
#define MULTIPLIER_PRIO   7
#define OUTPUT_WRITER_PRIO   8
#define SUBTRACTOR_PRIO   10

// User's Device(and Wrapper) priority

// SpaceComponents IDs
#define AMBA_AXIBUS_LT1_ID   15
#define ARMCORTEXA91_CORE0_ID   13
#define ARMCORTEXA91_CORE1_ID   14
#define ARMCORTEXA91_HP0_AMBA_AXIBUS_LT1_ID   16
#define ARMCORTEXA91_ID   7
#define FUNCTIONALBRIDGE1_ID   17
#define FUNCTIONALBRIDGE2_ID   18
#define ISSADAPTER1_ID   19
#define UART_ID   8
#define USERDEVICEEXTERNALIOSLAVE1_ID   9
#define USERDEVICEEXTERNALIOSLAVE2_ID   12
#define XILINXPIC1_ID   20

// SpaceComponents PRIOs
#define ARMCORTEXA91_PRIO   1
#define FUNCTIONALBRIDGE1_PRIO   1
#define FUNCTIONALBRIDGE2_PRIO   2

#endif //PLATFORM_DEFINITIONS_H
