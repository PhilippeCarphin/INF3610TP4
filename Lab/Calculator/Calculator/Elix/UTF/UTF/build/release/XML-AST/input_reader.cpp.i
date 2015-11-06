# 1 "comms/input_reader.cpp"
# 1 "<command-line>"
# 1 "comms/input_reader.cpp"
# 11 "comms/input_reader.cpp"
# 1 "C:/Users/Arnaud/Desktop/SpaceProject/Lab/Calculator/Calculator/src/module/input_reader.h" 1
# 14 "C:/Users/Arnaud/Desktop/SpaceProject/Lab/Calculator/Calculator/src/module/input_reader.h"
# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/hw/systemc.h" 1



# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/hw/systemc" 1




namespace sc_core {
}


namespace sc_dt {
}
# 5 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/hw/systemc.h" 2


namespace std {}
using std::ios;
using std::streambuf;
using std::streampos;
using std::streamsize;
using std::iostream;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::flush;
using std::dec;
using std::hex;
using std::oct;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::size_t;
using std::memchr;
using std::memcmp;
using std::memcpy;
using std::memmove;
using std::memset;
using std::strcat;
using std::strncat;
using std::strchr;
using std::strrchr;
using std::strcmp;
using std::strncmp;
using std::strcpy;
using std::strncpy;
using std::strcspn;
using std::strspn;
using std::strlen;
using std::strpbrk;
using std::strstr;
using std::strtok;
# 15 "C:/Users/Arnaud/Desktop/SpaceProject/Lab/Calculator/Calculator/src/module/input_reader.h" 2
# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/hw/SpaceBaseModule.h" 1



# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/hw/include/SpaceTypes.h" 1
# 22 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/hw/include/SpaceTypes.h"
static const unsigned char SPACE_OK = 0;
static const unsigned char SPACE_ERROR = 1;
static const unsigned char SPACE_EMPTY = 2;
static const unsigned char SPACE_FULL = 3;
static const unsigned char SPACE_NOT_CONNECTED = 99;

typedef unsigned char eSpaceStatus;







typedef enum
{

 SPACE_CHANNEL_OK = 0,
 SPACE_CHANNEL_FULL = 1,
 SPACE_CHANNEL_EMPTY = 2,
 SPACE_CHANNEL_UNUSED_STATUS_1 = 3,

 SPACE_CHANNEL_UNUSED_STATUS_2 = 4,
    SPACE_CHANNEL_ADDR_OUT_OF_RANGE = 5,

 SPACE_CHANNEL_ERROR = 6,

 SPACE_CHANNEL_TERMINATOR_ACCESS = 7,


    SPACE_CHANNEL_MSG_SIZE_ERROR = 8,
    SPACE_CHANNEL_NO_QUEUE_AVAILABLE = 9,
 SPACE_CHANNEL_UNUSED_STATUS_4 = 10,


 SPACE_CHANNEL_IN_PROGRESS = 11,




 SPACE_UNKNOWN_DESTINATION = 12,
 SPACE_INVALID_OFFSET = 13


} eSpaceChannelStatus;
# 75 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/hw/include/SpaceTypes.h"
static const unsigned long SPACE_NON_BLOCKING = 0;
static const unsigned long SPACE_NO_WAIT = 0;
static const unsigned long SPACE_BLOCKING = 0xFFFFFFFF;
static const unsigned long SPACE_WAIT_FOREVER = 0xFFFFFFFF;

typedef unsigned long eSpaceTransactionType;
# 89 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/hw/include/SpaceTypes.h"
typedef enum
{
    SPACE_UNREGISTERED = 0,
    SPACE_MODULE = 1,
    SPACE_DEVICE = 2,

 SPACE_ISS_ADAPTER = 4,
 SPACE_REGISTER_FILE = 5,
 SPACE_SLAVE_BRIDGE = 6
} eSpaceComponentType;







typedef enum
{
 SPACE_MODULE_READ = 0,
 SPACE_MODULE_WRITE = 1,
 SPACE_DEVICE_READ = 2,
 SPACE_DEVICE_WRITE = 3,
 SPACE_REGISTER_READ = 4,
 SPACE_REGISTER_WRITE = 5,
 SPACE_UNKNOWN_COMMUNICATION = 0xFF
} eSpaceCommunicationType;
# 5 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/hw/SpaceBaseModule.h" 2



class SpaceBaseModule;
# 16 "C:/Users/Arnaud/Desktop/SpaceProject/Lab/Calculator/Calculator/src/module/input_reader.h" 2

class input_reader : public SpaceBaseModule
{
 public:

  SC_HAS_PROCESS(input_reader);




  input_reader(sc_module_name zName, double dClockPeriod, sc_time_unit Unit, unsigned char ucID, unsigned char ucPriority, bool bVerbose);




  void thread(void);

 private:




  unsigned long readUART();
  void send2FIFO(unsigned long data);
};
# 12 "comms/input_reader.cpp" 2
# 1 "temp/PlatformDefinitions.h" 1
# 13 "comms/input_reader.cpp" 2
# 1 "C:/Users/Arnaud/Desktop/SpaceProject/Lab/Calculator/Calculator/src/application/ApplicationDefinitions.h" 1
# 14 "comms/input_reader.cpp" 2
# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/hw/SpaceDisplay.h" 1
# 15 "comms/input_reader.cpp" 2




# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/hw/include/XilinxUARTRegisters.h" 1
# 20 "comms/input_reader.cpp" 2







input_reader::input_reader(sc_module_name zName, double dClockPeriod, sc_time_unit ClockPeriodUnit, unsigned char ucID, unsigned char ucPriority, bool bVerbose)
: SpaceBaseModule( zName, dClockPeriod, ClockPeriodUnit, ucID, ucPriority, bVerbose )
{
 SC_THREAD(thread);
}






void input_reader::thread(void)
{
 while(1)
 {
  send2FIFO(readUART());
 }
}







unsigned long input_reader::readUART()
{




 unsigned long status;
 unsigned long data;

 DeviceRead(8, 0x00000008ul , &status);
 while((status & 0x01 )==0)
 {
  wait(1);
  DeviceRead(8, 0x00000008ul ,&status);
 }
 DeviceRead(8, 0x00000000ul , &data);

 return data;

}






void input_reader::send2FIFO(unsigned long data)
{
 ModuleWrite(1, SPACE_BLOCKING, &data);
}
