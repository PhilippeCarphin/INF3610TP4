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
AddressBinding AMBA_AXIBus_LT1_address[] =
{
	{ 10, {  4, 0x41007000, 0x41007fff}, 0 },	// S_AMBA_AXIBus_LT1_adap_multiplier1_AMBA_AXIBus_LT1_rdIF
	{  7, { 21, 0x41006000, 0x41006fff}, 0 },	// S_AMBA_AXIBus_LT1_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF
	{ 14, { 19, 0x40000000, 0x40ffffff}, 0 },	// S_AMBA_AXIBus_LT1_ISSAdapter1
	{ 15, { 22, 0x4100c000, 0x4100cfff}, 0 },	// S_AMBA_AXIBus_LT1_DebugModule1
	{  5, {  2, 0x41002000, 0x41002fff}, 0 },	// S_AMBA_AXIBus_LT1_adap_divider1_AMBA_AXIBus_LT1_rdIF
	{ 13, {  6, 0x4100a000, 0x4100afff}, 0 },	// S_AMBA_AXIBus_LT1_adap_subtractor1_AMBA_AXIBus_LT1_rdIF
	{ 11, {  5, 0x41009000, 0x41009fff}, 0 },	// S_AMBA_AXIBus_LT1_adap_output_writer1_AMBA_AXIBus_LT1_wrIF
	{  2, {  0, 0x41001000, 0x41001fff}, 0 },	// S_AMBA_AXIBus_LT1_adap_adder1_AMBA_AXIBus_LT1_wrIF
	{  1, {  8, 0x4100e000, 0x4100efff}, 0 },	// S_AMBA_AXIBus_LT1_XilinxUART1
	{  6, {  3, 0x41004000, 0x41004fff}, 0 },	// S_AMBA_AXIBus_LT1_adap_input_reader1_AMBA_AXIBus_LT1_rdIF
	{  9, {  4, 0x41008000, 0x41008fff}, 0 },	// S_AMBA_AXIBus_LT1_adap_multiplier1_AMBA_AXIBus_LT1_wrIF
	{  8, { 21, 0x41005000, 0x41005fff}, 0 },	// S_AMBA_AXIBus_LT1_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF
	{ 12, {  6, 0x4100b000, 0x4100bfff}, 0 },	// S_AMBA_AXIBus_LT1_adap_subtractor1_AMBA_AXIBus_LT1_wrIF
	{  4, {  2, 0x41003000, 0x41003fff}, 0 },	// S_AMBA_AXIBus_LT1_adap_divider1_AMBA_AXIBus_LT1_wrIF
	{  0, { 20, 0x4100d000, 0x4100dfff}, 0 },	// S_AMBA_AXIBus_LT1_XilinxPIC1
	{  3, {  0, 0x41000000, 0x41000fff}, 0 }	// S_AMBA_AXIBus_LT1_adap_adder1_AMBA_AXIBus_LT1_rdIF
};
AddressInfo AMBA_AXIBus_LT1_addressinfo = { 16, AMBA_AXIBus_LT1_address};


ComponentInfo Global_address[] =
{
	{ 19, -1,    SPACE_ISS_ADAPTER},	// ISSAdapter1
	{ 22, -1,         SPACE_DEVICE},	// DebugModule1
	{  0, -1,         SPACE_MODULE},	// adder1
	{  1,  0,         SPACE_MODULE},	// controller1
	{  2, -1,         SPACE_MODULE},	// divider1
	{  3, -1,         SPACE_MODULE},	// input_reader1
	{ 21, -1,         SPACE_MODULE},	// matrix_mul1
	{  4, -1,         SPACE_MODULE},	// multiplier1
	{  5, -1,         SPACE_MODULE},	// output_writer1
	{  6, -1,         SPACE_MODULE},	// subtractor1
	{ 20, -1,         SPACE_DEVICE},	// XilinxPIC1
	{  8, -1,         SPACE_DEVICE} 	// XilinxUART1
};


int IdByPriority[] =
{
	-1, -1, -1, 0, 1, 2, 3, 4, 5, 21, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1	
};

int Global_nbComponents = 12;


#undef BUS_MAPPING
