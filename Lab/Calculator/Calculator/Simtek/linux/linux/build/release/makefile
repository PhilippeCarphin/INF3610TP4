################################################################################
#
# Filename : makefile
#
# Author : SpaceStudio generation engine
#
# Warning: This file content will be overwritten by the next generation process.
#
################################################################################

### Variables ###

ARCH	=	.mingw

AS	    =	'C:/SpaceCodesign/SpaceStudio-2.7.0/toolchains/mingw/bin/as.exe'
CC	    =	'C:/SpaceCodesign/SpaceStudio-2.7.0/util/ccache/ccache.exe' 'C:/SpaceCodesign/SpaceStudio-2.7.0/toolchains/mingw/bin/gcc.exe'
CXX	    =	'C:/SpaceCodesign/SpaceStudio-2.7.0/util/ccache/ccache.exe' 'C:/SpaceCodesign/SpaceStudio-2.7.0/toolchains/mingw/bin/gcc.exe'
LD	    =	'C:/SpaceCodesign/SpaceStudio-2.7.0/toolchains/mingw/bin/gcc.exe'
CC_OUT  =   -o 
LD_OUT  =   -o 
MAKE_DEP=   -MD
PLUGIN_DIR =C:/SpaceCodesign/SpaceStudio-2.7.0/hw/lib
PLUGIN_EXT =.so 

CFLAGS	    =	-O2 -DSPACE_SIMULATION_RELEASE -Wall -fno-short-enums -fexceptions -finline-limit=200 -fno-expensive-optimizations -DSC_INCLUDE_DYNAMIC_PROCESSES -mthreads -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0501
CXXFLAGS	=	-O2 -DSPACE_SIMULATION_RELEASE -Wall -fno-short-enums -Wno-deprecated -fexceptions -finline-limit=200 -fno-expensive-optimizations -DSC_INCLUDE_DYNAMIC_PROCESSES -mthreads -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0501
LDFLAGS	    =	 -static -Wl,--start-group -ldistlm -lSpace$(ARCH) -lSpaceLibRuntime$(ARCH) -lsystemc$(ARCH) -lavrocpp_s -lboost_filesystem-mt$(ARCH) -lboost_system-mt$(ARCH) -lboost_thread-mt$(ARCH) -lboost_chrono-mt$(ARCH) -liphlpapi -lelf -lws2_32 -lwsock32 -lstdc++ -Wl,--end-group -mthreads

MAKEFILE = makefile

### Includes ###
INCDIR	=	-I 'C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/release' \
			-I 'C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module' \
			-I 'C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/application' \
			-I 'C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/device' \
			-I 'C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/import/src' \
			-I 'C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/hw/include' \
			-I 'C:/SpaceCodesign/SpaceStudio-2.7.0/SystemC/include' \
			-I 'C:/SpaceCodesign/SpaceStudio-2.7.0/hw/include' \
			-I 'C:/SpaceCodesign/SpaceStudio-2.7.0/hw/include/mingw' \
			-I 'C:/SpaceCodesign/SpaceStudio-2.7.0/toolchains/mingw/include'

### Libs ###
LIBDIR	=	-L 'C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/hw/lib' \
			-L 'C:/SpaceCodesign/SpaceStudio-2.7.0/SystemC/lib' \
			-L 'C:/SpaceCodesign/SpaceStudio-2.7.0/hw/lib'

### Plugins ###
PLUGINS = 

### Sources ###
SOURCES	=	adder.cpp \
			divider.cpp \
			input_reader.cpp \
			matrix_mul.cpp \
			multiplier.cpp \
			output_writer.cpp \
			subtractor.cpp \
			main.cpp \
			bus_mapping.cpp \
			CommandGenerator.cpp \
			temporizer.cpp
CSOURCES = xil_assert.c \
			xil_io.c \
			xuartps_hw.c
SSOURCES = 

### Objects ###
OBJECTSCPP = $(patsubst %.cpp, %.o, $(SOURCES))
OBJECTSC   = $(patsubst %.c, %.o, $(CSOURCES))
OBJECTSS   = $(patsubst %.s, %.o, $(SSOURCES))

### Dependencies ###
DEPSCPP = $(patsubst %.cpp, %.P, $(SOURCES))
DEPSC   = $(patsubst %.c, %.P, $(CSOURCES))

### Target ###
TARGET_DIR	= C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/release/bin
TARGET	= C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/release/bin/Calculatorlinux.exe

### Setting common path for modules, user devices and imported items ###
VPATH = /c/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module:/c/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/release:/c/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/device:/c/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/import/src

####### Implicit rules
.SUFFIXES: .cpp .c .s

%.o: %.cpp $(MAKEFILE)
		@echo ""
		@echo "Compiling HW Platform file ==>" $<
		$(CXX) $(MAKE_DEP) -c $< $(CC_OUT)$@ $(CXXFLAGS) $(INCDIR)
		@cp $*.d $*.P; \
		sed -e 's/#.*//' -e 's|\( \)*\([a-zA-z]\):\([/\\]\)|\1/\2\3|' \
			-e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' \
			< $*.d >> $*.P; \
		rm -f $*.d		

%.o: %.c $(MAKEFILE)
		@echo ""
		@echo "Compiling HW Platform imported file ==>" $<
		$(CC) $(MAKE_DEP) -c $< $(CC_OUT)$@ $(CFLAGS) $(INCDIR)
		@cp $*.d $*.P; \
		sed -e 's/#.*//' -e 's|\( \)*\([a-zA-z]\):\([/\\]\)|\1/\2\3|' \
			-e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' \
			< $*.d >> $*.P; \
		rm -f $*.d		

%.o: %.s $(MAKEFILE)
		@echo ""
		@echo "Compiling HW Platform imported file ==>" $<
		$(AS) $< $(CC_OUT)$@ $(ASFLAGS)
		
%$(PLUGIN_EXT): $(PLUGIN_DIR)/%$(PLUGIN_EXT)
		@echo ""
		@echo "Copying HW platform plugin ==>" $<
		cp $< $(TARGET_DIR)/$@

### Include dependencies ###
ifneq ($(DEPSCPP),)
-include $(DEPSCPP)
endif

ifneq ($(DEPSC),)
-include $(DEPSC))
endif

####### lib rules
all: $(TARGET)

$(TARGET):	$(OBJECTSCPP) $(OBJECTSC) $(OBJECTSS) $(PLUGINS) $(MAKEFILE)
		@echo ""
		@echo "-- Linking files and creating binary target --" $(TARGET)
		-rm -f $(TARGET)
		$(LD) $(LIBDIR) $(OBJECTSCPP) $(OBJECTSC) $(OBJECTSS) $(LDFLAGS) $(LD_OUT)$(TARGET)
		@echo DONE!

clean:
		@echo ""
		@echo "-- Cleaning files --" $(TARGET)
		-rm -f $(OBJECTSCPP) $(OBJECTSC) $(OBJECTSS) $(DEPSCPP) $(DEPSC) $(TARGET)
		-rm -f *~ core
		@echo DONE!

compile_all:	$(OBJECTSCPP) $(OBJECTSC) $(OBJECTSS)
		@echo ""
		@echo DONE!
		
rebuild: clean all

relink:
		@echo ""
		@echo "-- Creating binary target --" $(TARGET)
		-rm -f *~ core
		$(LD) $(LIBDIR) $(OBJECTSCPP) $(OBJECTSC) $(OBJECTSS) $(LDFLAGS) $(LD_OUT)$(TARGET)
		@echo DONE!

