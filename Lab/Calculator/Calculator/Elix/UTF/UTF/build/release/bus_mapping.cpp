////////////////////////////////////////////////////////////////////
//
// Filename       : bus_mapping.cpp
//
////////////////////////////////////////////////////////////////////
//  Copyright 2011 - Space Codesign Systems, Inc.
//  All rights reserved.
////////////////////////////////////////////////////////////////////
#define BUS_MAPPING
#include "bus_mapping.h"


/////////////////////////////////////////////////////////
///
///	Arrays	(those arrays are generated by SpaceStudio, please do not modify)
///
/////////////////////////////////////////////////////////
AddressBinding UTFChannel1_address[] =
{
	{  0, {  8, 0x00000000, 0x000000ff}, 0 }	// S_UTFChannel1_XilinxUART1
};
AddressInfo UTFChannel1_addressinfo = {  1, UTFChannel1_address};


ComponentInfo Global_address[] =
{
	{  0, -1,         SPACE_MODULE},	// adder1
	{  1, -1,         SPACE_MODULE},	// controller1
	{  2, -1,         SPACE_MODULE},	// divider1
	{  3, -1,         SPACE_MODULE},	// input_reader1
	{  5, -1,         SPACE_MODULE},	// multiplier1
	{  6, -1,         SPACE_MODULE},	// output_writer1
	{  7, -1,         SPACE_MODULE},	// subtractor1
	{  8, -1,         SPACE_DEVICE} 	// XilinxUART1
};


int IdByPriority[] =
{
	-1, 0, 1, 2, 3, -1, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1	
};

int Global_nbComponents = 8;


#undef BUS_MAPPING
