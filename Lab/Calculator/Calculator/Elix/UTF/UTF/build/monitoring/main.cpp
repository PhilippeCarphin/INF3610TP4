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

	// Initialize the SpaceLib components and prepare for simulation       
	if(SpaceLibInitialize(arg_count, arg_value, simulation_time, sim_units,  0) == -1 )
		return(0);
	TFMasterAdapter M_UTFChannel1_adap_input_reader1_ChannelIFPort("M_UTFChannel1_adap_input_reader1_ChannelIFPort", 10, SC_NS, INPUT_READER_ID, false);
	TFMasterAdapter M_UTFChannel1_adap_output_writer1_ChannelIFPort("M_UTFChannel1_adap_output_writer1_ChannelIFPort", 10, SC_NS, OUTPUT_WRITER_ID, false);
	TFSlaveAdapter S_UTFChannel1_XilinxUART1("S_UTFChannel1_XilinxUART1", 10, SC_NS, UART_ID, false);
	ModuleMasterAdapter adap_input_reader1("adap_input_reader1", 10, SC_NS, INPUT_READER_ID, INPUT_READER_PRIO, ChannelWidthInfinite, (void*)&UTFChannel1_addressinfo, false);
	ModuleMasterAdapter adap_output_writer1("adap_output_writer1", 10, SC_NS, OUTPUT_WRITER_ID, OUTPUT_WRITER_PRIO, ChannelWidthInfinite, (void*)&UTFChannel1_addressinfo, false);
	UTFChannel UTFChannel1("UTFChannel1", UTFCHANNEL1_ID, ChannelWidthInfinite, (void*)&UTFChannel1_addressinfo, false);
	UserDeviceExternalIOSlave UserDeviceExternalIOSlave1("UserDeviceExternalIOSlave1", 10, SC_NS, USERDEVICEEXTERNALIOSLAVE1_ID, false);
	UserDeviceExternalIOSlave UserDeviceExternalIOSlave2("UserDeviceExternalIOSlave2", 10, SC_NS, USERDEVICEEXTERNALIOSLAVE2_ID, false);
	SDLRegister DL_adder1_TO_controller1_SDLRegister1("DL_adder1_TO_controller1_SDLRegister1", 10, SC_NS, DL_ADDER1_TO_CONTROLLER1_SDLREGISTER1_ID, 64, false);
	SDLRegister DL_controller1_TO_adder1_SDLRegister1("DL_controller1_TO_adder1_SDLRegister1", 10, SC_NS, DL_CONTROLLER1_TO_ADDER1_SDLREGISTER1_ID, 64, false);
	SDLRegister DL_controller1_TO_divider1_SDLRegister1("DL_controller1_TO_divider1_SDLRegister1", 10, SC_NS, DL_CONTROLLER1_TO_DIVIDER1_SDLREGISTER1_ID, 64, false);
	SDLRegister DL_controller1_TO_matrix_mul1_SDLRegister1("DL_controller1_TO_matrix_mul1_SDLRegister1", 10, SC_NS, DL_CONTROLLER1_TO_MATRIX_MUL1_SDLREGISTER1_ID, 64, false);
	SDLRegister DL_controller1_TO_multiplier1_SDLRegister1("DL_controller1_TO_multiplier1_SDLRegister1", 10, SC_NS, DL_CONTROLLER1_TO_MULTIPLIER1_SDLREGISTER1_ID, 64, false);
	SDLRegister DL_controller1_TO_output_writer1_SDLRegister1("DL_controller1_TO_output_writer1_SDLRegister1", 10, SC_NS, DL_CONTROLLER1_TO_OUTPUT_WRITER1_SDLREGISTER1_ID, 64, false);
	SDLRegister DL_controller1_TO_subtractor1_SDLRegister1("DL_controller1_TO_subtractor1_SDLRegister1", 10, SC_NS, DL_CONTROLLER1_TO_SUBTRACTOR1_SDLREGISTER1_ID, 64, false);
	SDLRegister DL_divider1_TO_controller1_SDLRegister1("DL_divider1_TO_controller1_SDLRegister1", 10, SC_NS, DL_DIVIDER1_TO_CONTROLLER1_SDLREGISTER1_ID, 64, false);
	SDLRegister DL_input_reader1_TO_controller1_SDLRegister1("DL_input_reader1_TO_controller1_SDLRegister1", 10, SC_NS, DL_INPUT_READER1_TO_CONTROLLER1_SDLREGISTER1_ID, 64, false);
	SDLRegister DL_matrix_mul1_TO_controller1_SDLRegister1("DL_matrix_mul1_TO_controller1_SDLRegister1", 10, SC_NS, DL_MATRIX_MUL1_TO_CONTROLLER1_SDLREGISTER1_ID, 64, false);
	SDLRegister DL_multiplier1_TO_controller1_SDLRegister1("DL_multiplier1_TO_controller1_SDLRegister1", 10, SC_NS, DL_MULTIPLIER1_TO_CONTROLLER1_SDLREGISTER1_ID, 64, false);
	SDLRegister DL_subtractor1_TO_controller1_SDLRegister1("DL_subtractor1_TO_controller1_SDLRegister1", 10, SC_NS, DL_SUBTRACTOR1_TO_CONTROLLER1_SDLREGISTER1_ID, 64, false);
	adder adder1("adder1", 10, SC_NS, ADDER_ID, ADDER_PRIO, false);
	controller controller1("controller1", 10, SC_NS, CONTROLLER_ID, CONTROLLER_PRIO, false);
	divider divider1("divider1", 10, SC_NS, DIVIDER_ID, DIVIDER_PRIO, false);
	input_reader input_reader1("input_reader1", 10, SC_NS, INPUT_READER_ID, INPUT_READER_PRIO, false);
	matrix_mul matrix_mul1("matrix_mul1", 10, SC_NS, MATRIX_MUL_ID, MATRIX_MUL_PRIO, false);
	multiplier multiplier1("multiplier1", 10, SC_NS, MULTIPLIER_ID, MULTIPLIER_PRIO, false);
	output_writer output_writer1("output_writer1", 10, SC_NS, OUTPUT_WRITER_ID, OUTPUT_WRITER_PRIO, false);
	subtractor subtractor1("subtractor1", 10, SC_NS, SUBTRACTOR_ID, SUBTRACTOR_PRIO, false);
	ResetManager reset_manager_1("reset_manager_1", 10, SC_NS, true);
	XilinxUART XilinxUART1("XilinxUART1", 10, SC_NS, UART_ID, 57600, false, false, false, false);
	sc_clock SysClock("SysClock", 10, SC_NS, 0.5);
	sc_core::sc_signal< bool > sReset;
	CommandGenerator CommandGenerator1("CommandGenerator1", 10, SC_NS, COMMANDGENERATOR_ID, false);
	temporizer temporizer1("temporizer1", 10, SC_NS, TEMPORIZER_ID, false);
	sReset = true;

	// Binding
	UTFChannel1.SlaveIFPort(S_UTFChannel1_XilinxUART1);
	UserDeviceExternalIOSlave1.SlaveIFPort(temporizer1);
	UserDeviceExternalIOSlave2.SlaveIFPort(CommandGenerator1);
	adder1.SpaceModuleReadIFPort[0](DL_controller1_TO_adder1_SDLRegister1.SpaceModuleReadIFExport);
	adder1.SpaceModuleWriteIFPort[0](DL_adder1_TO_controller1_SDLRegister1.SpaceModuleWriteIFExport);
	controller1.SpaceModuleReadIFPort[0](DL_adder1_TO_controller1_SDLRegister1.SpaceModuleReadIFExport);
	controller1.SpaceModuleReadIFPort[1](DL_divider1_TO_controller1_SDLRegister1.SpaceModuleReadIFExport);
	controller1.SpaceModuleReadIFPort[2](DL_input_reader1_TO_controller1_SDLRegister1.SpaceModuleReadIFExport);
	controller1.SpaceModuleReadIFPort[3](DL_matrix_mul1_TO_controller1_SDLRegister1.SpaceModuleReadIFExport);
	controller1.SpaceModuleReadIFPort[4](DL_multiplier1_TO_controller1_SDLRegister1.SpaceModuleReadIFExport);
	controller1.SpaceModuleReadIFPort[5](DL_subtractor1_TO_controller1_SDLRegister1.SpaceModuleReadIFExport);
	controller1.SpaceModuleWriteIFPort[0](DL_controller1_TO_adder1_SDLRegister1.SpaceModuleWriteIFExport);
	controller1.SpaceModuleWriteIFPort[1](DL_controller1_TO_divider1_SDLRegister1.SpaceModuleWriteIFExport);
	controller1.SpaceModuleWriteIFPort[2](DL_controller1_TO_matrix_mul1_SDLRegister1.SpaceModuleWriteIFExport);
	controller1.SpaceModuleWriteIFPort[3](DL_controller1_TO_multiplier1_SDLRegister1.SpaceModuleWriteIFExport);
	controller1.SpaceModuleWriteIFPort[4](DL_controller1_TO_output_writer1_SDLRegister1.SpaceModuleWriteIFExport);
	controller1.SpaceModuleWriteIFPort[5](DL_controller1_TO_subtractor1_SDLRegister1.SpaceModuleWriteIFExport);
	divider1.SpaceModuleReadIFPort[0](DL_controller1_TO_divider1_SDLRegister1.SpaceModuleReadIFExport);
	divider1.SpaceModuleWriteIFPort[0](DL_divider1_TO_controller1_SDLRegister1.SpaceModuleWriteIFExport);
	input_reader1.SpaceModuleWriteIFPort[0](DL_input_reader1_TO_controller1_SDLRegister1.SpaceModuleWriteIFExport);
	matrix_mul1.SpaceModuleReadIFPort[0](DL_controller1_TO_matrix_mul1_SDLRegister1.SpaceModuleReadIFExport);
	matrix_mul1.SpaceModuleWriteIFPort[0](DL_matrix_mul1_TO_controller1_SDLRegister1.SpaceModuleWriteIFExport);
	multiplier1.SpaceModuleReadIFPort[0](DL_controller1_TO_multiplier1_SDLRegister1.SpaceModuleReadIFExport);
	multiplier1.SpaceModuleWriteIFPort[0](DL_multiplier1_TO_controller1_SDLRegister1.SpaceModuleWriteIFExport);
	output_writer1.SpaceModuleReadIFPort[0](DL_controller1_TO_output_writer1_SDLRegister1.SpaceModuleReadIFExport);
	subtractor1.SpaceModuleReadIFPort[0](DL_controller1_TO_subtractor1_SDLRegister1.SpaceModuleReadIFExport);
	subtractor1.SpaceModuleWriteIFPort[0](DL_subtractor1_TO_controller1_SDLRegister1.SpaceModuleWriteIFExport);
	XilinxUART1.ExternalIOPort(UserDeviceExternalIOSlave2);
	CommandGenerator1.ExternalIOPort(UserDeviceExternalIOSlave1);
	S_UTFChannel1_XilinxUART1.SlaveIFPort(XilinxUART1);
	input_reader1.ChannelIFPort(adap_input_reader1);
	output_writer1.ChannelIFPort(adap_output_writer1);
	adap_input_reader1.ChannelIFPort(M_UTFChannel1_adap_input_reader1_ChannelIFPort);
	adap_output_writer1.ChannelIFPort(M_UTFChannel1_adap_output_writer1_ChannelIFPort);
	M_UTFChannel1_adap_input_reader1_ChannelIFPort.ChannelIFPort(UTFChannel1);
	M_UTFChannel1_adap_output_writer1_ChannelIFPort.ChannelIFPort(UTFChannel1);
	adder1.nResetPort(sReset);
	controller1.nResetPort(sReset);
	divider1.nResetPort(sReset);
	input_reader1.nResetPort(sReset);
	matrix_mul1.nResetPort(sReset);
	multiplier1.nResetPort(sReset);
	output_writer1.nResetPort(sReset);
	subtractor1.nResetPort(sReset);
	XilinxUART1.ClockPort(SysClock);
	XilinxUART1.nResetPort(sReset);
	reset_manager_1.nResetPort(sReset);
	adap_input_reader1.nResetPort(sReset);
	adap_output_writer1.nResetPort(sReset);

	SPACE_MONITORABLE_SYSTEM( SPACE_MONITOR_USE_FILE, "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Elix/UTF/UTF/build/monitoring");
		
	SPACE_MONITORABLE_BUS( UTFChannel1 );
	SPACE_MONITORABLE_MODULE( adder1 );
	SPACE_MONITORABLE_MODULE( controller1 );
	SPACE_MONITORABLE_MODULE( divider1 );
	SPACE_MONITORABLE_MODULE( input_reader1 );
	SPACE_MONITORABLE_MODULE( matrix_mul1 );
	SPACE_MONITORABLE_MODULE( multiplier1 );
	SPACE_MONITORABLE_MODULE( output_writer1 );
	SPACE_MONITORABLE_MODULE( subtractor1 );
	SPACE_MONITORABLE_SDL( DL_adder1_TO_controller1_SDLRegister1 );
	SPACE_MONITORABLE_SDL( DL_controller1_TO_adder1_SDLRegister1 );
	SPACE_MONITORABLE_SDL( DL_controller1_TO_divider1_SDLRegister1 );
	SPACE_MONITORABLE_SDL( DL_controller1_TO_matrix_mul1_SDLRegister1 );
	SPACE_MONITORABLE_SDL( DL_controller1_TO_multiplier1_SDLRegister1 );
	SPACE_MONITORABLE_SDL( DL_controller1_TO_output_writer1_SDLRegister1 );
	SPACE_MONITORABLE_SDL( DL_controller1_TO_subtractor1_SDLRegister1 );
	SPACE_MONITORABLE_SDL( DL_divider1_TO_controller1_SDLRegister1 );
	SPACE_MONITORABLE_SDL( DL_input_reader1_TO_controller1_SDLRegister1 );
	SPACE_MONITORABLE_SDL( DL_matrix_mul1_TO_controller1_SDLRegister1 );
	SPACE_MONITORABLE_SDL( DL_multiplier1_TO_controller1_SDLRegister1 );
	SPACE_MONITORABLE_SDL( DL_subtractor1_TO_controller1_SDLRegister1 );

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
