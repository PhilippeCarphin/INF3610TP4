# 1 "comms/matrix_mul.cpp"
# 1 "<command-line>"
# 1 "comms/matrix_mul.cpp"







# 1 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module/matrix_mul.h" 1
# 11 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module/matrix_mul.h"
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

# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/hw/systemc" 1




namespace sc_core {
}


namespace sc_dt {
}
# 7 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/hw/SpaceBaseModule.h" 2

class SpaceBaseModule;
# 12 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module/matrix_mul.h" 2

# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/hw/systemc" 1
# 14 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module/matrix_mul.h" 2

class matrix_mul: public SpaceBaseModule {
 public:

     SC_HAS_PROCESS(matrix_mul);

  matrix_mul(sc_core::sc_module_name name, double period, sc_core::sc_time_unit unit, unsigned char id, unsigned char priority, bool verbose);

     void thread(void);
     void multiply(unsigned int* matrix1, unsigned int* matrix2, unsigned int* result);
     void readMatrix(unsigned int* matrix);
     void sendResult(unsigned int* matrix);
};
# 9 "comms/matrix_mul.cpp" 2

# 1 "temp/PlatformDefinitions.h" 1
# 11 "comms/matrix_mul.cpp" 2
# 1 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/application/ApplicationDefinitions.h" 1
# 12 "comms/matrix_mul.cpp" 2
# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/hw/SpaceDisplay.h" 1
# 13 "comms/matrix_mul.cpp" 2

# 1 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/import/src/matrix_def.h" 1
# 15 "comms/matrix_mul.cpp" 2

matrix_mul::matrix_mul(sc_core::sc_module_name name, double period, sc_core::sc_time_unit unit, unsigned char id, unsigned char priority, bool verbose)
:SpaceBaseModule(name, period, unit, id, priority, verbose) {
 SC_THREAD(thread);

 set_stack_size(0x16000+(20*20*4*3));
}

void matrix_mul::thread(void) {

 unsigned int matrix1[20*20];
 unsigned int matrix2[20*20];
 unsigned int result[20*20];
 while(1) {

  readMatrix(matrix1);
  SpacePrint("Fin lecture matrice 1 \n");
  readMatrix(matrix2);
  SpacePrint("Fin lecture matrice 2 \n");
  multiply(matrix1, matrix2, result);
  SpacePrint("Fin multiplication matrice  \n");
  sendResult(result);
  SpacePrint("Fin envoi  \n");
 }
}






void matrix_mul::multiply(unsigned int* matrix1, unsigned int* matrix2, unsigned int* result)
{
 unsigned int temp_acc;
 for(int i=0;i<20;i++) {
  for(int j=0; j<20;j++)
  {
   for(int k= 0; k< 20;k++)
   {
    temp_acc += (matrix1[i*20 +k] * matrix2[k*20 +j]);
   }
   result[i*20 +j] = temp_acc;
   temp_acc = 0;
  }
 }
}






void matrix_mul::readMatrix(unsigned int* matrix)
{
 ModuleRead(1, SPACE_BLOCKING, matrix, 20*20);
}






void matrix_mul::sendResult(unsigned int* matrix)
{
 ModuleWrite(1, SPACE_BLOCKING, matrix, 20*20);
}
