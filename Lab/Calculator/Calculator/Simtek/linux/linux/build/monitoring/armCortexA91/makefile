################################################################################
#
# Filename : makefile
#
# Author : SpaceStudio generation engine
#
# Warning: This file content will be overwritten by the next generation process.
#
################################################################################

####### Variables #######

ARCH		=  	.arm

OS		= Linux

AS		=	'C:/SpaceCodesign/SpaceStudio-2.7.0/toolchains/arm-unknown-linux-gnueabi/bin/arm-unknown-linux-gnueabi-as.exe'
CC		=	'C:/SpaceCodesign/SpaceStudio-2.7.0/util/ccache/ccache.exe' 'C:/SpaceCodesign/SpaceStudio-2.7.0/toolchains/arm-unknown-linux-gnueabi/bin/arm-unknown-linux-gnueabi-gcc.exe'
CXX		=	'C:/SpaceCodesign/SpaceStudio-2.7.0/util/ccache/ccache.exe' 'C:/SpaceCodesign/SpaceStudio-2.7.0/toolchains/arm-unknown-linux-gnueabi/bin/arm-unknown-linux-gnueabi-gcc.exe'
LD		=	'C:/SpaceCodesign/SpaceStudio-2.7.0/toolchains/arm-unknown-linux-gnueabi/bin/arm-unknown-linux-gnueabi-gcc.exe'

### Includes ###
INCDIR	=	-I 'C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91' \
			-I 'C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring' \
			-I 'C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module' \
			-I 'C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/application' \
			-I 'C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/import/src' \
			-I 'C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/sw/include' \
			-I 'C:/SpaceCodesign/SpaceStudio-2.7.0/sw/OS/Linux3.6.0-digilent' \
			-I 'C:/SpaceCodesign/SpaceStudio-2.7.0/sw/OS/POSIX'

### Libs ###
LIBDIR	 =	-L 'C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/sw/lib'

ASFLAGS  =  -mcpu=cortex-a9 -mfpu=vfp -mfloat-abi=softfp
CFLAGS	 =	-O2 -DSPACE_SIMULATION_MONITORING  -Wall -fno-short-enums -mcpu=cortex-a9 -mfpu=vfp -mfloat-abi=softfp -DOS_GLOBALS -DOS_CPU_GLOBALS
CXXFLAGS =	-O2 -DSPACE_SIMULATION_MONITORING  -Wall -fno-short-enums -mcpu=cortex-a9 -mfpu=vfp -mfloat-abi=softfp -DOS_GLOBALS -DOS_CPU_GLOBALS
LDFLAGS	 =	  -static -Wl,--start-group -lpthread -lSpace$(ARCH)$(OS) -lstdc++ -lc -lm -Wl,--end-group -u _boot -static

LINKERSCRIPT = 
MAKEFILE = makefile

### Sources ###
SOURCES	=	controller.cpp \
			mainarmCortexA91.cpp \
			communication.cpp \
			OSConfiguration.cpp
CSOURCES = matrix.c \
			TorToOS.c \
			pTorToOS.c
SSOURCES = 
ASOURCES = 

### Objects ###
OBJECTSCPP = $(patsubst %.cpp, %.o, $(SOURCES))
OBJECTSC   = $(patsubst %.c, %.o, $(CSOURCES))
OBJECTSS   = $(patsubst %.s, %.o, $(SSOURCES))
OBJECTSA   = $(patsubst %.S, %.o, $(ASOURCES))

### Dependencies ###
DEPSCPP = $(patsubst %.cpp, %.P, $(SOURCES))
DEPSC   = $(patsubst %.c, %.P, $(CSOURCES))
DEPSA   = $(patsubst %.S, %.P, $(ASOURCES))

### Target ###
TARGET	= C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/Calculator_armCortexA91.arm.elf
 
### Stop simulation ###
STOP_SIMULATION	= C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/stop_simulation.elf

### ip saver ###
IP_SAVER = C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/ip_saver.elf

### gdbserver notifier ###
GDBSERVER_NOTIFIER = C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/gdbserver_notifier.elf

### Setting common path for modules and imported items ###
VPATH = /c/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91:/c/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/import/src:/c/SpaceCodesign/SpaceStudio-2.7.0/sw/OS/Linux3.6.0-digilent:/c/SpaceCodesign/SpaceStudio-2.7.0/sw/OS/POSIX

####### Implicit rules
.SUFFIXES: .cpp .c .s

%.o: %.cpp $(MAKEFILE)
		@echo ""
		@echo "Compiling SW ISS file ==>" $<
		$(CXX) -MD -c $< -o $@ $(CXXFLAGS) $(INCDIR)
		@cp $*.d $*.P; \
		sed -e 's/#.*//' -e 's|\( \)*\([a-zA-z]\):\([/\\]\)|\1/\2\3|' \
			-e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' \
			< $*.d >> $*.P; \
		rm -f $*.d		

%.o: %.c $(MAKEFILE)
		@echo ""
		@echo "Compiling SW imported file ==>" $<
		$(CC) -MD -c $< -o $@ $(CFLAGS) $(INCDIR)
		@cp $*.d $*.P; \
		sed -e 's/#.*//' -e 's|\( \)*\([a-zA-z]\):\([/\\]\)|\1/\2\3|' \
			-e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' \
			< $*.d >> $*.P; \
		rm -f $*.d		
		
%.o: %.s $(MAKEFILE)
		@echo ""
		@echo "Compiling SW imported file ==>" $<
		$(AS) $< -o $@ $(ASFLAGS)
		
%.o: %.S $(MAKEFILE)
		@echo ""
		@echo "Compiling SW imported file ==>" $<
		$(CC) -MD -c $< -o $@ $(CFLAGS) $(INCDIR)
		@cp $*.d $*.P; \
		sed -e 's/#.*//' -e 's|\( \)*\([a-zA-z]\):\([/\\]\)|\1/\2\3|' \
			-e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' \
			< $*.d >> $*.P; \
		rm -f $*.d		
 
stop_simulation.o: stop_simulation.cpp $(MAKEFILE)
		@echo ""
		@echo "Compiling SW ISS file ==>" $<
		$(CXX) -MD -c $< -o $@ $(CXXFLAGS) $(INCDIR)	

### Include dependencies ###
ifneq ($(DEPSCPP),)
-include $(DEPSCPP)
endif

ifneq ($(DEPSC),)
-include $(DEPSC))
endif

ifneq ($(DEPSA),)
-include $(DEPSA))
endif

####### lib rules
all: $(TARGET) $(STOP_SIMULATION) $(IP_SAVER) $(GDBSERVER_NOTIFIER) 	

staticlib: $(TARGET) 

$(TARGET): $(OBJECTSCPP) $(OBJECTSC) $(OBJECTSS) $(OBJECTSA) $(LINKERSCRIPT) $(MAKEFILE)
	@echo ""
	@echo " --- Linking objects and creating ELF executable ---"
	$(LD) $(LIBDIR) $(LIBS) $(OBJECTSCPP) $(OBJECTSC) $(OBJECTSS) $(OBJECTSA) $(LDFLAGS) -o $(TARGET) 	
	@echo "DONE!"

$(STOP_SIMULATION): stop_simulation.o $(MAKEFILE)
	@echo " --- Linking objects and creating stop_simulation ELF executable ---"
	$(LD) $(LIBDIR) $(LIBS) communication.o OSConfiguration.o stop_simulation.o $(LDFLAGS) -o $(STOP_SIMULATION)

$(IP_SAVER): ip_saver.o $(MAKEFILE)
	@echo " --- Linking objects and creating ip_saver ELF executable ---"
	$(LD) $(LIBDIR) ip_saver.o $(LDFLAGS) -o $(IP_SAVER)

$(GDBSERVER_NOTIFIER): gdbserver_notifier.o $(MAKEFILE)
	@echo " --- Linking objects and creating gdbserver_notifier ELF executable ---"
	$(LD) $(LIBDIR) gdbserver_notifier.o $(LDFLAGS) -o $(GDBSERVER_NOTIFIER) 			

clean:
	@echo ""
	@echo " --- Cleaning SW project ---"
	-rm -f $(OBJECTSCPP) $(OBJECTSC) $(OBJECTSS) $(OBJECTSA) $(DEPSCPP) $(DEPSC) $(DEPSA) $(TARGET)
	-rm -f *~ core 
	@echo "DONE!"

compile_all:	$(OBJECTSCPP) $(OBJECTSC) $(OBJECTSS) $(OBJECTSA)
	@echo ""
	@echo DONE!

rebuild: clean all

relink:
	@echo ""
	@echo " --- Creating ELF executable ---"
	-rm -f *~ core
	$(LD) $(LIBDIR) $(LIBS) $(OBJECTSCPP) $(OBJECTSC) $(OBJECTSS) $(OBJECTSA) $(LDFLAGS) -o $(TARGET) 	
	@echo "DONE!"

