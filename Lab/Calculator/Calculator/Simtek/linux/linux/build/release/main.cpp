////////////////////////////////////////////////////////////////////////////////
//
// Filename : main.cpp
//
// Author : SpaceStudio generation engine
//
// Warning: This file content will be overwritten by the next generation process.
//
////////////////////////////////////////////////////////////////////////////////

#include "main.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

using sc_core::SC_ABORT;
using sc_core::SC_CACHE_REPORT;
using sc_core::SC_DISPLAY;
using sc_core::SC_DO_NOTHING;
using sc_core::SC_ERROR;
using sc_core::SC_FATAL;
using sc_core::SC_LOG;
using sc_core::SC_STOP;
using sc_core::SC_THROW;

using sc_core::SC_SEC;
using sc_core::SC_MS;
using sc_core::SC_US;
using sc_core::SC_NS;
using sc_core::SC_PS;				
using sc_core::SC_FS;

using sc_core::sc_clock;

int sc_main(int arg_count, char **arg_value){
	sc_core::sc_report_handler::suppress(SC_THROW);
	sc_core::sc_report_handler::suppress(SC_ABORT);
	sc_core::sc_report_handler::set_actions("object already exists", SC_DO_NOTHING);
	sc_core::sc_report_handler::set_actions(SC_ERROR, SC_DEFAULT_ERROR_ACTIONS | SC_DISPLAY | SC_STOP);
	sc_core::sc_report_handler::set_actions(SC_FATAL, SC_DEFAULT_FATAL_ACTIONS | SC_DISPLAY | SC_STOP);

	// Variables for simulation time evaluation
	time_t simulation_time_begin = 0;
	time_t simulation_time_end = 0;
	
	// Variables for sorting the arguments
	int simulation_time = -1; 
	int sim_units = 2; //SC_NS 
	int* DEBUGGER_PORT_KEY = 0;  

	// Initialize the SpaceLib components and prepare for simulation       
	if(SpaceLibInitialize(arg_count, arg_value, simulation_time, sim_units, DEBUGGER_PORT_KEY ) == -1 )
		return(0);
	ISSAdapter ISSAdapter1("ISSAdapter1", 10, SC_NS, ISSADAPTER1_ID, false);
	TFMasterAdapter M_AMBA_AXIBus_LT1_adap_input_reader1_ChannelIFPort("M_AMBA_AXIBus_LT1_adap_input_reader1_ChannelIFPort", 10, SC_NS, INPUT_READER_ID, false);
	TFMasterAdapter M_AMBA_AXIBus_LT1_adap_output_writer1_ChannelIFPort("M_AMBA_AXIBus_LT1_adap_output_writer1_ChannelIFPort", 10, SC_NS, OUTPUT_WRITER_ID, false);
	TFMasterAdapter M_AMBA_AXIBus_LT1_armCortexA91_DBusPort("M_AMBA_AXIBus_LT1_armCortexA91_DBusPort", 10, SC_NS, ARMCORTEXA91_ID, false);
	TFMasterAdapter M_AMBA_AXIBus_LT1_armCortexA91_IBusPort("M_AMBA_AXIBus_LT1_armCortexA91_IBusPort", 10, SC_NS, ARMCORTEXA91_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_DebugModule1("S_AMBA_AXIBus_LT1_DebugModule1", 10, SC_NS, DEBUGMODULE1_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_ISSAdapter1("S_AMBA_AXIBus_LT1_ISSAdapter1", 10, SC_NS, ISSADAPTER1_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_XilinxPIC1("S_AMBA_AXIBus_LT1_XilinxPIC1", 10, SC_NS, XILINXPIC1_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_XilinxUART1("S_AMBA_AXIBus_LT1_XilinxUART1", 10, SC_NS, UART_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_adder1_AMBA_AXIBus_LT1_rdIF("S_AMBA_AXIBus_LT1_adap_adder1_AMBA_AXIBus_LT1_rdIF", 10, SC_NS, ADDER_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_adder1_AMBA_AXIBus_LT1_wrIF("S_AMBA_AXIBus_LT1_adap_adder1_AMBA_AXIBus_LT1_wrIF", 10, SC_NS, ADDER_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_divider1_AMBA_AXIBus_LT1_rdIF("S_AMBA_AXIBus_LT1_adap_divider1_AMBA_AXIBus_LT1_rdIF", 10, SC_NS, DIVIDER_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_divider1_AMBA_AXIBus_LT1_wrIF("S_AMBA_AXIBus_LT1_adap_divider1_AMBA_AXIBus_LT1_wrIF", 10, SC_NS, DIVIDER_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_input_reader1_AMBA_AXIBus_LT1_rdIF("S_AMBA_AXIBus_LT1_adap_input_reader1_AMBA_AXIBus_LT1_rdIF", 10, SC_NS, INPUT_READER_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF("S_AMBA_AXIBus_LT1_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF", 10, SC_NS, MATRIX_MUL_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF("S_AMBA_AXIBus_LT1_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF", 10, SC_NS, MATRIX_MUL_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_multiplier1_AMBA_AXIBus_LT1_rdIF("S_AMBA_AXIBus_LT1_adap_multiplier1_AMBA_AXIBus_LT1_rdIF", 10, SC_NS, MULTIPLIER_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_multiplier1_AMBA_AXIBus_LT1_wrIF("S_AMBA_AXIBus_LT1_adap_multiplier1_AMBA_AXIBus_LT1_wrIF", 10, SC_NS, MULTIPLIER_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_output_writer1_AMBA_AXIBus_LT1_wrIF("S_AMBA_AXIBus_LT1_adap_output_writer1_AMBA_AXIBus_LT1_wrIF", 10, SC_NS, OUTPUT_WRITER_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_subtractor1_AMBA_AXIBus_LT1_rdIF("S_AMBA_AXIBus_LT1_adap_subtractor1_AMBA_AXIBus_LT1_rdIF", 10, SC_NS, SUBTRACTOR_ID, false);
	TFSlaveAdapter S_AMBA_AXIBus_LT1_adap_subtractor1_AMBA_AXIBus_LT1_wrIF("S_AMBA_AXIBus_LT1_adap_subtractor1_AMBA_AXIBus_LT1_wrIF", 10, SC_NS, SUBTRACTOR_ID, false);
	ModuleSlaveAdapter adap_adder1_AMBA_AXIBus_LT1_rdIF("adap_adder1_AMBA_AXIBus_LT1_rdIF", ADDER_ID, false);
	ModuleSlaveAdapter adap_adder1_AMBA_AXIBus_LT1_wrIF("adap_adder1_AMBA_AXIBus_LT1_wrIF", ADDER_ID, false);
	ModuleSlaveAdapter adap_divider1_AMBA_AXIBus_LT1_rdIF("adap_divider1_AMBA_AXIBus_LT1_rdIF", DIVIDER_ID, false);
	ModuleSlaveAdapter adap_divider1_AMBA_AXIBus_LT1_wrIF("adap_divider1_AMBA_AXIBus_LT1_wrIF", DIVIDER_ID, false);
	ModuleMasterAdapter adap_input_reader1("adap_input_reader1", 10, SC_NS, INPUT_READER_ID, INPUT_READER_PRIO, ChannelWidth4, (void*)&AMBA_AXIBus_LT1_addressinfo, false);
	ModuleSlaveAdapter adap_input_reader1_AMBA_AXIBus_LT1_rdIF("adap_input_reader1_AMBA_AXIBus_LT1_rdIF", INPUT_READER_ID, false);
	ModuleSlaveAdapter adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF("adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF", MATRIX_MUL_ID, false);
	ModuleSlaveAdapter adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF("adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF", MATRIX_MUL_ID, false);
	ModuleSlaveAdapter adap_multiplier1_AMBA_AXIBus_LT1_rdIF("adap_multiplier1_AMBA_AXIBus_LT1_rdIF", MULTIPLIER_ID, false);
	ModuleSlaveAdapter adap_multiplier1_AMBA_AXIBus_LT1_wrIF("adap_multiplier1_AMBA_AXIBus_LT1_wrIF", MULTIPLIER_ID, false);
	ModuleMasterAdapter adap_output_writer1("adap_output_writer1", 10, SC_NS, OUTPUT_WRITER_ID, OUTPUT_WRITER_PRIO, ChannelWidth4, (void*)&AMBA_AXIBus_LT1_addressinfo, false);
	ModuleSlaveAdapter adap_output_writer1_AMBA_AXIBus_LT1_wrIF("adap_output_writer1_AMBA_AXIBus_LT1_wrIF", OUTPUT_WRITER_ID, false);
	ModuleSlaveAdapter adap_subtractor1_AMBA_AXIBus_LT1_rdIF("adap_subtractor1_AMBA_AXIBus_LT1_rdIF", SUBTRACTOR_ID, false);
	ModuleSlaveAdapter adap_subtractor1_AMBA_AXIBus_LT1_wrIF("adap_subtractor1_AMBA_AXIBus_LT1_wrIF", SUBTRACTOR_ID, false);
	AMBA_AXIBus_LT AMBA_AXIBus_LT1("AMBA_AXIBus_LT1", AMBA_AXIBUS_LT1_ID, 10, SC_NS, ChannelWidth4, 1, 1, 1, (void*)&AMBA_AXIBus_LT1_addressinfo, false);
	DebugModule DebugModule1("DebugModule1", false);
	UserDeviceExternalIOSlave UserDeviceExternalIOSlave1("UserDeviceExternalIOSlave1", 10, SC_NS, USERDEVICEEXTERNALIOSLAVE1_ID, false);
	UserDeviceExternalIOSlave UserDeviceExternalIOSlave2("UserDeviceExternalIOSlave2", 10, SC_NS, USERDEVICEEXTERNALIOSLAVE2_ID, false);
	ModuleSlaveAdapterFIFORead fifo_adap_adder1_AMBA_AXIBus_LT1_rdIF0("fifo_adap_adder1_AMBA_AXIBus_LT1_rdIF0", 10, SC_NS, ADDER_ID, 64, false);
	ModuleSlaveAdapterFIFOWrite fifo_adap_adder1_AMBA_AXIBus_LT1_wrIF0("fifo_adap_adder1_AMBA_AXIBus_LT1_wrIF0", 10, SC_NS, ADDER_ID, 64, false);
	ModuleSlaveAdapterFIFORead fifo_adap_divider1_AMBA_AXIBus_LT1_rdIF0("fifo_adap_divider1_AMBA_AXIBus_LT1_rdIF0", 10, SC_NS, DIVIDER_ID, 64, false);
	ModuleSlaveAdapterFIFOWrite fifo_adap_divider1_AMBA_AXIBus_LT1_wrIF0("fifo_adap_divider1_AMBA_AXIBus_LT1_wrIF0", 10, SC_NS, DIVIDER_ID, 64, false);
	ModuleSlaveAdapterFIFORead fifo_adap_input_reader1_AMBA_AXIBus_LT1_rdIF0("fifo_adap_input_reader1_AMBA_AXIBus_LT1_rdIF0", 10, SC_NS, INPUT_READER_ID, 64, false);
	ModuleSlaveAdapterFIFORead fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF0("fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF0", 10, SC_NS, MATRIX_MUL_ID, 64, false);
	ModuleSlaveAdapterFIFOWrite fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF0("fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF0", 10, SC_NS, MATRIX_MUL_ID, 64, false);
	ModuleSlaveAdapterFIFORead fifo_adap_multiplier1_AMBA_AXIBus_LT1_rdIF0("fifo_adap_multiplier1_AMBA_AXIBus_LT1_rdIF0", 10, SC_NS, MULTIPLIER_ID, 64, false);
	ModuleSlaveAdapterFIFOWrite fifo_adap_multiplier1_AMBA_AXIBus_LT1_wrIF0("fifo_adap_multiplier1_AMBA_AXIBus_LT1_wrIF0", 10, SC_NS, MULTIPLIER_ID, 64, false);
	ModuleSlaveAdapterFIFOWrite fifo_adap_output_writer1_AMBA_AXIBus_LT1_wrIF0("fifo_adap_output_writer1_AMBA_AXIBus_LT1_wrIF0", 10, SC_NS, OUTPUT_WRITER_ID, 64, false);
	ModuleSlaveAdapterFIFORead fifo_adap_subtractor1_AMBA_AXIBus_LT1_rdIF0("fifo_adap_subtractor1_AMBA_AXIBus_LT1_rdIF0", 10, SC_NS, SUBTRACTOR_ID, 64, false);
	ModuleSlaveAdapterFIFOWrite fifo_adap_subtractor1_AMBA_AXIBus_LT1_wrIF0("fifo_adap_subtractor1_AMBA_AXIBus_LT1_wrIF0", 10, SC_NS, SUBTRACTOR_ID, 64, false);
	armCortexA9_DisTLM armCortexA91("armCortexA91", ARMCORTEXA91_ID, "localhost", "1024", false, false);
	adder adder1("adder1", 10, SC_NS, ADDER_ID, ADDER_PRIO, false);
	divider divider1("divider1", 10, SC_NS, DIVIDER_ID, DIVIDER_PRIO, false);
	input_reader input_reader1("input_reader1", 10, SC_NS, INPUT_READER_ID, INPUT_READER_PRIO, false);
	matrix_mul matrix_mul1("matrix_mul1", 10, SC_NS, MATRIX_MUL_ID, MATRIX_MUL_PRIO, false);
	multiplier multiplier1("multiplier1", 10, SC_NS, MULTIPLIER_ID, MULTIPLIER_PRIO, false);
	output_writer output_writer1("output_writer1", 10, SC_NS, OUTPUT_WRITER_ID, OUTPUT_WRITER_PRIO, false);
	subtractor subtractor1("subtractor1", 10, SC_NS, SUBTRACTOR_ID, SUBTRACTOR_PRIO, false);
	XilinxPIC XilinxPIC1("XilinxPIC1", 10, SC_NS, XILINXPIC1_ID, false);
	ResetManager reset_manager_1("reset_manager_1", 10, SC_NS, true);
	XilinxUART XilinxUART1("XilinxUART1", 10, SC_NS, UART_ID, 57600, false, false, false, false);
	sc_clock SysClock("SysClock", 10, SC_NS, 0.5);
	sc_core::sc_signal< bool > sReset;
	sc_core::sc_signal< bool > sXilinxPIC1_IRQOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_adder1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_adder1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_divider1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_divider1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_input_reader1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_multiplier1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_multiplier1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_output_writer1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_subtractor1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0;
	sc_core::sc_signal< bool > sfifo_adap_subtractor1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0;
	CommandGenerator CommandGenerator1("CommandGenerator1", 10, SC_NS, COMMANDGENERATOR_ID, false);
	temporizer temporizer1("temporizer1", 10, SC_NS, TEMPORIZER_ID, false);
	sReset = true;

	// Binding
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_XilinxPIC1);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_XilinxUART1);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_adder1_AMBA_AXIBus_LT1_wrIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_adder1_AMBA_AXIBus_LT1_rdIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_divider1_AMBA_AXIBus_LT1_wrIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_divider1_AMBA_AXIBus_LT1_rdIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_input_reader1_AMBA_AXIBus_LT1_rdIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_multiplier1_AMBA_AXIBus_LT1_wrIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_multiplier1_AMBA_AXIBus_LT1_rdIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_output_writer1_AMBA_AXIBus_LT1_wrIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_subtractor1_AMBA_AXIBus_LT1_wrIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_adap_subtractor1_AMBA_AXIBus_LT1_rdIF);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_ISSAdapter1);
	AMBA_AXIBus_LT1.SlaveIFPort(S_AMBA_AXIBus_LT1_DebugModule1);
	UserDeviceExternalIOSlave1.SlaveIFPort(temporizer1);
	UserDeviceExternalIOSlave2.SlaveIFPort(CommandGenerator1);
	adder1.SpaceModuleReadIFPort[0](fifo_adap_adder1_AMBA_AXIBus_LT1_wrIF0.SpaceModuleReadIFExport);
	adder1.SpaceModuleWriteIFPort[0](fifo_adap_adder1_AMBA_AXIBus_LT1_rdIF0.SpaceModuleWriteIFExport);
	divider1.SpaceModuleReadIFPort[0](fifo_adap_divider1_AMBA_AXIBus_LT1_wrIF0.SpaceModuleReadIFExport);
	divider1.SpaceModuleWriteIFPort[0](fifo_adap_divider1_AMBA_AXIBus_LT1_rdIF0.SpaceModuleWriteIFExport);
	input_reader1.SpaceModuleWriteIFPort[0](fifo_adap_input_reader1_AMBA_AXIBus_LT1_rdIF0.SpaceModuleWriteIFExport);
	matrix_mul1.SpaceModuleReadIFPort[0](fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF0.SpaceModuleReadIFExport);
	matrix_mul1.SpaceModuleWriteIFPort[0](fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF0.SpaceModuleWriteIFExport);
	multiplier1.SpaceModuleReadIFPort[0](fifo_adap_multiplier1_AMBA_AXIBus_LT1_wrIF0.SpaceModuleReadIFExport);
	multiplier1.SpaceModuleWriteIFPort[0](fifo_adap_multiplier1_AMBA_AXIBus_LT1_rdIF0.SpaceModuleWriteIFExport);
	output_writer1.SpaceModuleReadIFPort[0](fifo_adap_output_writer1_AMBA_AXIBus_LT1_wrIF0.SpaceModuleReadIFExport);
	subtractor1.SpaceModuleReadIFPort[0](fifo_adap_subtractor1_AMBA_AXIBus_LT1_wrIF0.SpaceModuleReadIFExport);
	subtractor1.SpaceModuleWriteIFPort[0](fifo_adap_subtractor1_AMBA_AXIBus_LT1_rdIF0.SpaceModuleWriteIFExport);
	XilinxUART1.ExternalIOPort(UserDeviceExternalIOSlave1);
	temporizer1.ExternalIOPort(UserDeviceExternalIOSlave2);
	adap_adder1_AMBA_AXIBus_LT1_wrIF.FifoIFPort[0](fifo_adap_adder1_AMBA_AXIBus_LT1_wrIF0.FifoIFExport);
	adap_adder1_AMBA_AXIBus_LT1_rdIF.FifoIFPort[0](fifo_adap_adder1_AMBA_AXIBus_LT1_rdIF0.FifoIFExport);
	adap_divider1_AMBA_AXIBus_LT1_wrIF.FifoIFPort[0](fifo_adap_divider1_AMBA_AXIBus_LT1_wrIF0.FifoIFExport);
	adap_divider1_AMBA_AXIBus_LT1_rdIF.FifoIFPort[0](fifo_adap_divider1_AMBA_AXIBus_LT1_rdIF0.FifoIFExport);
	adap_input_reader1_AMBA_AXIBus_LT1_rdIF.FifoIFPort[0](fifo_adap_input_reader1_AMBA_AXIBus_LT1_rdIF0.FifoIFExport);
	adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF.FifoIFPort[0](fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF0.FifoIFExport);
	adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF.FifoIFPort[0](fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF0.FifoIFExport);
	adap_multiplier1_AMBA_AXIBus_LT1_wrIF.FifoIFPort[0](fifo_adap_multiplier1_AMBA_AXIBus_LT1_wrIF0.FifoIFExport);
	adap_multiplier1_AMBA_AXIBus_LT1_rdIF.FifoIFPort[0](fifo_adap_multiplier1_AMBA_AXIBus_LT1_rdIF0.FifoIFExport);
	adap_output_writer1_AMBA_AXIBus_LT1_wrIF.FifoIFPort[0](fifo_adap_output_writer1_AMBA_AXIBus_LT1_wrIF0.FifoIFExport);
	adap_subtractor1_AMBA_AXIBus_LT1_wrIF.FifoIFPort[0](fifo_adap_subtractor1_AMBA_AXIBus_LT1_wrIF0.FifoIFExport);
	adap_subtractor1_AMBA_AXIBus_LT1_rdIF.FifoIFPort[0](fifo_adap_subtractor1_AMBA_AXIBus_LT1_rdIF0.FifoIFExport);
	S_AMBA_AXIBus_LT1_XilinxPIC1.SlaveIFPort(XilinxPIC1);
	S_AMBA_AXIBus_LT1_XilinxUART1.SlaveIFPort(XilinxUART1);
	S_AMBA_AXIBus_LT1_adap_adder1_AMBA_AXIBus_LT1_wrIF.SlaveIFPort(adap_adder1_AMBA_AXIBus_LT1_wrIF);
	S_AMBA_AXIBus_LT1_adap_adder1_AMBA_AXIBus_LT1_rdIF.SlaveIFPort(adap_adder1_AMBA_AXIBus_LT1_rdIF);
	S_AMBA_AXIBus_LT1_adap_divider1_AMBA_AXIBus_LT1_wrIF.SlaveIFPort(adap_divider1_AMBA_AXIBus_LT1_wrIF);
	S_AMBA_AXIBus_LT1_adap_divider1_AMBA_AXIBus_LT1_rdIF.SlaveIFPort(adap_divider1_AMBA_AXIBus_LT1_rdIF);
	S_AMBA_AXIBus_LT1_adap_input_reader1_AMBA_AXIBus_LT1_rdIF.SlaveIFPort(adap_input_reader1_AMBA_AXIBus_LT1_rdIF);
	S_AMBA_AXIBus_LT1_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF.SlaveIFPort(adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF);
	S_AMBA_AXIBus_LT1_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF.SlaveIFPort(adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF);
	S_AMBA_AXIBus_LT1_adap_multiplier1_AMBA_AXIBus_LT1_wrIF.SlaveIFPort(adap_multiplier1_AMBA_AXIBus_LT1_wrIF);
	S_AMBA_AXIBus_LT1_adap_multiplier1_AMBA_AXIBus_LT1_rdIF.SlaveIFPort(adap_multiplier1_AMBA_AXIBus_LT1_rdIF);
	S_AMBA_AXIBus_LT1_adap_output_writer1_AMBA_AXIBus_LT1_wrIF.SlaveIFPort(adap_output_writer1_AMBA_AXIBus_LT1_wrIF);
	S_AMBA_AXIBus_LT1_adap_subtractor1_AMBA_AXIBus_LT1_wrIF.SlaveIFPort(adap_subtractor1_AMBA_AXIBus_LT1_wrIF);
	S_AMBA_AXIBus_LT1_adap_subtractor1_AMBA_AXIBus_LT1_rdIF.SlaveIFPort(adap_subtractor1_AMBA_AXIBus_LT1_rdIF);
	S_AMBA_AXIBus_LT1_ISSAdapter1.SlaveIFPort(ISSAdapter1);
	S_AMBA_AXIBus_LT1_DebugModule1.SlaveIFPort(DebugModule1);
	input_reader1.ChannelIFPort(adap_input_reader1);
	output_writer1.ChannelIFPort(adap_output_writer1);
	adap_input_reader1.ChannelIFPort(M_AMBA_AXIBus_LT1_adap_input_reader1_ChannelIFPort);
	adap_output_writer1.ChannelIFPort(M_AMBA_AXIBus_LT1_adap_output_writer1_ChannelIFPort);
	armCortexA91.DBusPort(M_AMBA_AXIBus_LT1_armCortexA91_DBusPort);
	armCortexA91.IBusPort(M_AMBA_AXIBus_LT1_armCortexA91_IBusPort);
	M_AMBA_AXIBus_LT1_adap_input_reader1_ChannelIFPort.ChannelIFPort(AMBA_AXIBus_LT1);
	M_AMBA_AXIBus_LT1_adap_output_writer1_ChannelIFPort.ChannelIFPort(AMBA_AXIBus_LT1);
	M_AMBA_AXIBus_LT1_armCortexA91_DBusPort.ChannelIFPort(AMBA_AXIBus_LT1);
	M_AMBA_AXIBus_LT1_armCortexA91_IBusPort.ChannelIFPort(AMBA_AXIBus_LT1);
	armCortexA91.DebuggerIFPort(DebugModule1);
	XilinxPIC1.IRQOutPort(sXilinxPIC1_IRQOutPort0);
	fifo_adap_output_writer1_AMBA_AXIBus_LT1_wrIF0.IRQHasRoomOutPort(sfifo_adap_output_writer1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	fifo_adap_input_reader1_AMBA_AXIBus_LT1_rdIF0.IRQHasDataOutPort(sfifo_adap_input_reader1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);
	fifo_adap_adder1_AMBA_AXIBus_LT1_wrIF0.IRQHasRoomOutPort(sfifo_adap_adder1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	fifo_adap_subtractor1_AMBA_AXIBus_LT1_wrIF0.IRQHasRoomOutPort(sfifo_adap_subtractor1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	fifo_adap_multiplier1_AMBA_AXIBus_LT1_wrIF0.IRQHasRoomOutPort(sfifo_adap_multiplier1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	fifo_adap_divider1_AMBA_AXIBus_LT1_wrIF0.IRQHasRoomOutPort(sfifo_adap_divider1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF0.IRQHasRoomOutPort(sfifo_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	fifo_adap_adder1_AMBA_AXIBus_LT1_rdIF0.IRQHasDataOutPort(sfifo_adap_adder1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);
	fifo_adap_subtractor1_AMBA_AXIBus_LT1_rdIF0.IRQHasDataOutPort(sfifo_adap_subtractor1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);
	fifo_adap_multiplier1_AMBA_AXIBus_LT1_rdIF0.IRQHasDataOutPort(sfifo_adap_multiplier1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);
	fifo_adap_divider1_AMBA_AXIBus_LT1_rdIF0.IRQHasDataOutPort(sfifo_adap_divider1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);
	fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF0.IRQHasDataOutPort(sfifo_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);
	ISSAdapter1.nResetPort(sReset);
	adder1.nResetPort(sReset);
	divider1.nResetPort(sReset);
	input_reader1.nResetPort(sReset);
	matrix_mul1.nResetPort(sReset);
	multiplier1.nResetPort(sReset);
	output_writer1.nResetPort(sReset);
	subtractor1.nResetPort(sReset);
	XilinxPIC1.nResetPort(sReset);
	XilinxUART1.ClockPort(SysClock);
	XilinxUART1.nResetPort(sReset);
	reset_manager_1.nResetPort(sReset);
	adap_input_reader1.nResetPort(sReset);
	adap_output_writer1.nResetPort(sReset);
	fifo_adap_adder1_AMBA_AXIBus_LT1_wrIF0.nResetPort(sReset);
	fifo_adap_adder1_AMBA_AXIBus_LT1_rdIF0.nResetPort(sReset);
	fifo_adap_divider1_AMBA_AXIBus_LT1_wrIF0.nResetPort(sReset);
	fifo_adap_divider1_AMBA_AXIBus_LT1_rdIF0.nResetPort(sReset);
	fifo_adap_input_reader1_AMBA_AXIBus_LT1_rdIF0.nResetPort(sReset);
	fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF0.nResetPort(sReset);
	fifo_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF0.nResetPort(sReset);
	fifo_adap_multiplier1_AMBA_AXIBus_LT1_wrIF0.nResetPort(sReset);
	fifo_adap_multiplier1_AMBA_AXIBus_LT1_rdIF0.nResetPort(sReset);
	fifo_adap_output_writer1_AMBA_AXIBus_LT1_wrIF0.nResetPort(sReset);
	fifo_adap_subtractor1_AMBA_AXIBus_LT1_wrIF0.nResetPort(sReset);
	fifo_adap_subtractor1_AMBA_AXIBus_LT1_rdIF0.nResetPort(sReset);
	armCortexA91.SPI0InPort(sXilinxPIC1_IRQOutPort0);
	XilinxPIC1.IRQInPort[0](sfifo_adap_output_writer1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	XilinxPIC1.IRQInPort[1](sfifo_adap_input_reader1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);
	XilinxPIC1.IRQInPort[2](sfifo_adap_adder1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	XilinxPIC1.IRQInPort[3](sfifo_adap_subtractor1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	XilinxPIC1.IRQInPort[4](sfifo_adap_multiplier1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	XilinxPIC1.IRQInPort[5](sfifo_adap_divider1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	XilinxPIC1.IRQInPort[6](sfifo_adap_matrix_mul1_AMBA_AXIBus_LT1_wrIF0_IRQHasRoomOutPort0);
	XilinxPIC1.IRQInPort[7](sfifo_adap_adder1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);
	XilinxPIC1.IRQInPort[8](sfifo_adap_subtractor1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);
	XilinxPIC1.IRQInPort[9](sfifo_adap_multiplier1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);
	XilinxPIC1.IRQInPort[10](sfifo_adap_divider1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);
	XilinxPIC1.IRQInPort[11](sfifo_adap_matrix_mul1_AMBA_AXIBus_LT1_rdIF0_IRQHasDataOutPort0);


	// The following section is a free section where user can singlehandedly code.
	// All code put in between tags will be preserved and copied into your newly generated main file
	// *Warning* All code put everywhere else will be erased without possible undo operation.
	// _FREE_SECTION_START_ (Do Not Erase or Duplicate this Line)	
		//	Empty
	// _FREE_SECTION_END_ (Do Not Erase or Duplicate this Line)

	// No buffer for the output.
	setvbuf ( stdout, NULL , _IONBF , 0);
	
	// Simulation section  -- Begin
	std::cout << "Starting simulation.\n";
	time( &simulation_time_begin );
	sc_core::sc_start(simulation_time,sc_core::sc_time_unit(sim_units));
	time( &simulation_time_end );

	std::cout << std::endl << "Simulation has ended @" << sc_core::sc_time_stamp().to_seconds() << " s";
	std::cout << std::endl << "Simulation wall clock time: " << (unsigned long)(simulation_time_end - simulation_time_begin) << " seconds." << std::endl << std::endl;
	std::cout.flush();

	// Simulation section  -- End
	
    return 0; // No problem occurs
}
