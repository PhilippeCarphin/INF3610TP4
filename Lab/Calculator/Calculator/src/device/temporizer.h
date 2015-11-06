// ***********************************************************************
//
// Filename : temporizer.h
//
// Author : SpaceStudio generation engine
//
// Creation date : Mon Jun 06 12:25:24 EDT 2011
//
//
// ***********************************************************************
#ifndef TEMPORIZER_H_
#define TEMPORIZER_H_

#include <systemc.h>
#include <SpaceDisplay.h>
#include <SpaceBaseDevice.h>


#define PACKET_LENGTH 1
#define BOOT_PERIOD (sc_time(10, SC_US))
#define PACKET_INTERARRIVAL_PERIOD (sc_time(1, SC_US))

// ***********************************************************************/
///\class    temporizer
///
///\brief    This class is a shell creating your custom interface
///			 device
///
// ***********************************************************************/
class temporizer 
: 	public SpaceBaseDevice
{
public:

	SC_HAS_PROCESS(temporizer);

	// Note: the following port is actually declared in the SpaceBaseDevice class,
	// but is also accessible from this user device in order to send or receive
	// data through an ExternalIOSlave component.
	// sc_port<SpaceSlaveIF> ExternalIOPort;
	
	//
	// temporizer
	// ***********************************************************************
	///
	/// Allows to instantiate your device
	///
	// ***********************************************************************
	temporizer(sc_module_name Name,
					 double dClockPeriod,
					 sc_time_unit Unit,
					 unsigned char ucID,
			   		 bool bVerbose);
	
	~temporizer();
	
 	//
	// SlaveRead
	// ***********************************************************************
	/// 
	/// Interface Method for Read Operations going to the device  
	///
	// ***********************************************************************
    virtual void SlaveRead(tlm::tlm_generic_payload& trans, sc_time& delay );
   
	//
	// SlaveWrite
	// ***********************************************************************
	/// 
	/// Interface Method for Write Operations going to the device  
	///
	// ***********************************************************************
    virtual void SlaveWrite(tlm::tlm_generic_payload& trans, sc_time& delay );


	//
	// SystemC elaboration methods
	// ***********************************************************************
	void before_end_of_elaboration();
	void end_of_elaboration();
	
	// SystemC temporization thread
	void packet_arrival_thread();
	
	// Packet arrival event
	sc_event packet_arrived;
	
private:

	unsigned long m_nbBytes;	

};

#endif // TEMPORIZER_H_

// eof 
