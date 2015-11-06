////////////////////////////////////////////////////////////////////////////////
//
// Filename : main.h
//
// Author : SpaceStudio generation engine
//
// Warning: This file content will be overwritten by the next generation process.
//
////////////////////////////////////////////////////////////////////////////////


#ifndef MAIN_H
#define MAIN_H

#include "ApplicationDefinitions.h"
#include "PlatformDefinitions.h"

// Platform specific files
#include "AMBA_AXIBus_LT.h"
#include "DebugModule.h"
#include "ISSAdapter.h"
#include "ModuleMasterAdapter.h"
#include "ModuleSlaveAdapter.h"
#include "ModuleSlaveAdapterFIFORead.h"
#include "ModuleSlaveAdapterFIFOWrite.h"
#include "ResetManager.h"
#include "TFMasterAdapter.h"
#include "TFSlaveAdapter.h"
#include "UserDeviceExternalIOSlave.h"
#include "XilinxPIC.h"
#include "XilinxUART.h"
#include "armCortexA9_DisTLM.h"

// Application specific headers
#include "../../src/device/CommandGenerator.h"
#include "../../src/device/temporizer.h"
#include "../../src/module/adder.h"
#include "../../src/module/divider.h"
#include "../../src/module/input_reader.h"
#include "../../src/module/matrix_mul.h"
#include "../../src/module/multiplier.h"
#include "../../src/module/output_writer.h"
#include "../../src/module/subtractor.h"
#include "bus_mapping.h"

#include "systemc"

#ifdef _MSC_VER
	typedef enum eSpaceInternalStatus;
#else
	typedef int eSpaceInternalStatus;
#endif	
extern int SpaceLibInitialize(int,char**,int&,int&,int[]);
extern eSpaceInternalStatus RegisterSWComponent(unsigned char, unsigned char, bool);
#endif
