# 1 "comms/controller.cpp"
# 1 "<command-line>"
# 1 "comms/controller.cpp"
# 11 "comms/controller.cpp"
# 1 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module/controller.h" 1
# 14 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module/controller.h"
# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/sw/systemc.h" 1



# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/sw/systemc" 1




namespace sc_core {
}
# 5 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/sw/systemc.h" 2


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
# 15 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module/controller.h" 2
# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/sw/SpaceBaseModule.h" 1



# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/sw/include/SpaceTypes.h" 1
# 22 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/sw/include/SpaceTypes.h"
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
# 75 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/sw/include/SpaceTypes.h"
static const unsigned long SPACE_NON_BLOCKING = 0;
static const unsigned long SPACE_NO_WAIT = 0;
static const unsigned long SPACE_BLOCKING = 0xFFFFFFFF;
static const unsigned long SPACE_WAIT_FOREVER = 0xFFFFFFFF;

typedef unsigned long eSpaceTransactionType;
# 89 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceLib/release/sw/include/SpaceTypes.h"
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
# 5 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/sw/SpaceBaseModule.h" 2



class SpaceBaseModule;
# 16 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module/controller.h" 2
# 1 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/import/src/matrix.h" 1



# 1 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/import/src/matrix_def.h" 1
# 5 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/import/src/matrix.h" 2
extern unsigned int* matrix_data[];
# 17 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/module/controller.h" 2

typedef enum {
 ADD,
 SUBTRACTION,
 MULTIPLY,
 DIVIDE,
 MATRIX_MUL
} Operation;

class controller : public SpaceBaseModule
{
 public:

  SC_HAS_PROCESS(controller);




  controller(sc_module_name zName, double dClockPeriod, sc_time_unit Unit, unsigned char ucID, unsigned char ucPriority, bool bVerbose);




  void thread(void);

 private:




  unsigned int m_matrix_result[100*100];

  void sendResult(long data);
  void sendCharacter(unsigned char character);
  unsigned long readInput();
  void readData(long* operand1, long* operand2, Operation* operation);
  long getFirstOperand(unsigned char* ptr);
  long getSecondOperand(unsigned char* ptr);
  long convertCharacterToNumber(unsigned char* ptr, unsigned char length);
  bool isNegative(unsigned char character);
  bool isDigit(unsigned char character);
  bool isSpace(char character);
  bool isOperationCharacter(unsigned char character);
  unsigned long pow(int base, int exponent);
  int getOperationPosition(unsigned char* ptr);
  void readInputStream(unsigned char* ptr);
  void sanitize(unsigned char* ptr, int* position);
  bool isValidCommand(unsigned char* ptr);
  bool isDividedByZeroDetected(unsigned char* ptr);
  bool isOperationDetected(unsigned char* ptr);
  bool isOperand1Detected(unsigned char* ptr);
  bool isOperand2Detected(unsigned char* ptr);
  bool isNumber(unsigned char* ptr, unsigned char length);
  bool isLFDetected(unsigned char* ptr);
  int getLFPosition(unsigned char* ptr);
  bool isLF(unsigned char character);
  unsigned char* trimSpaces(unsigned char* ptr, unsigned char* length);
  Operation getOperation(unsigned char* ptr);
  long delegateOperation(Operation operation, long operand1, long operand2);
  void sendAdditionOperand(long data);
  void sendSubtractionOperand(long data);
  void sendMultiplicationOperand(long data);
  void sendDivisionOperand(long data);
  long readAdditionResult();
  long readSubtractionResult();
  long readMultiplicationResult();
  long readDivisionResult();
  void init(unsigned char* ptr);
  int atoi(unsigned char c);
  unsigned char itoa(unsigned int x);
  int getOrder(unsigned long data);
  void displayMessage(char* message);
  void sendMatrix(long index);
  void readMatrixMultiplicationResult();
};
# 12 "comms/controller.cpp" 2
# 1 "temp/PlatformDefinitions.h" 1
# 13 "comms/controller.cpp" 2
# 1 "C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/src/application/ApplicationDefinitions.h" 1
# 14 "comms/controller.cpp" 2
# 1 "C:/SpaceCodesign/SpaceStudio-2.7.0/SpaceStudio/src/main/resources/a/ck/headers/sw/SpaceDisplay.h" 1
# 15 "comms/controller.cpp" 2
# 24 "comms/controller.cpp"
controller::controller(sc_module_name zName, double dClockPeriod, sc_time_unit ClockPeriodUnit, unsigned char ucID, unsigned char ucPriority, bool bVerbose)
: SpaceBaseModule(zName, dClockPeriod, ClockPeriodUnit, ucID, ucPriority, bVerbose)
{
 SC_THREAD(thread);
}






void controller::thread(void)
{
 long operand1;
 long operand2;
 long result;
 Operation operation;

 while(1) {
  readData(&operand1, &operand2, &operation);
  result = delegateOperation(operation, operand1, operand2);
  sendResult(result);
 }
}






void controller::sendResult(long data)
{
 if (GetVerbose())
  SpacePrint("Result:%d\n", data);

 int i;
 unsigned long power;
 unsigned int digit;


 if (data < 0)
 {
  sendCharacter('-');
  data *= -1;
 }

 for(i=getOrder(data);i>=0;i--)
 {
  power = pow(10, i);
  digit = data/power;
  data -= digit*power;
  sendCharacter(itoa(digit));
 }

 sendCharacter(0xD);
}






void controller::sendCharacter(unsigned char character)
{
 unsigned long data = (unsigned long)character;
 ModuleWrite(5, SPACE_BLOCKING, &data);
}






unsigned long controller::readInput()
{
 unsigned long data;

 ModuleRead(3, SPACE_BLOCKING, &data);

 return data;
}






void controller::readData(long* operand1, long* operand2, Operation* operation)
{
 unsigned char raw[20];

 readInputStream(raw);
 *operand1 = getFirstOperand(raw);
 *operand2 = getSecondOperand(raw);
 *operation = getOperation(raw);
 if (*operand1 == 3 && *operand2 == 0 && *operation == MATRIX_MUL)
 {
  sc_core::sc_stop();
 }
}






long controller::getFirstOperand(unsigned char* ptr)
{
 unsigned char length = getOperationPosition(ptr);
 unsigned char* trimPtr = trimSpaces(ptr, &length);
 long number = convertCharacterToNumber(trimPtr, length);

 if (GetVerbose())
  SpacePrint("First operand:%d\n", number);

 return number;
}






long controller::getSecondOperand(unsigned char* ptr)
{
 unsigned char length = getLFPosition(ptr) - getOperationPosition(ptr) - 1;
 unsigned char* trimPtr = trimSpaces(ptr + getOperationPosition(ptr) + 1, &length);
 long number = convertCharacterToNumber(trimPtr, length);

 if (GetVerbose())
  SpacePrint("Second operand:%d\n", number);

 return number;
}






long controller::convertCharacterToNumber(unsigned char* ptr, unsigned char length)
{
 unsigned char i;
 unsigned long number = 0;
 bool isNegativeNumber = false;

  for(i=0;i<length;i++)
  {
   if (isNegative(ptr[i]))
   {
    isNegativeNumber = true;
    continue;
   }

  number += atoi(ptr[i]) * pow(10, length-i-1);
  }

  return isNegativeNumber ? number * -1 : number;
}






bool controller::isNegative(unsigned char character)
{
 if (character == '-')
  return true;
 return false;
}






bool controller::isDigit(unsigned char character)
{
 if (('0' <= character) && (character <= '9'))
  return true;
 return false;
}






bool controller::isSpace(char character)
{
 if (character == ' ')
  return true;
 return false;
}






bool controller::isOperationCharacter(unsigned char character)
{
 if ((character == '+') || (character == '-') || (character == '/') || (character == 'x') || (character == 'X') || (character == '*') || (character == 'z'))
  return true;
 return false;
}






unsigned long controller::pow(int base, int exponent)
{
 unsigned long result = 1;
 int i;
 for(i=0;i<exponent;i++)
  result *= base;
 return result;
}






int controller::getOperationPosition(unsigned char* ptr)
{
 bool isFirstCharacter = true;
 int i=0;
 for(i=0;i<20;i++)
 {
  if (!isFirstCharacter && isOperationCharacter(ptr[i]))
   return i;

  if (isFirstCharacter && isDigit(ptr[i]))
   isFirstCharacter = false;
 }

 return -1;
}






void controller::readInputStream(unsigned char* ptr)
{
 int position;
 sanitize(ptr, &position);
 bool isOverflow = false;


    while(!isValidCommand(ptr) || isDividedByZeroDetected(ptr))
    {

     if (isLFDetected(ptr) && (!isOperationDetected(ptr) || !isOperand1Detected(ptr) || !isOperand2Detected(ptr)))
     {
      sanitize(ptr, &position);
      displayMessage("Invalid input string\n");
      isOverflow = false;
     }

     if (isDividedByZeroDetected(ptr)) {
      sanitize(ptr, &position);
      displayMessage("Division by zero detected\n");
      isOverflow = false;
     }

  ptr[position++] = (unsigned char)readInput();


  if (position == 20)
  {
   sanitize(ptr, &position);
   if (!isOverflow)
    displayMessage("String too long, try again\n");
   isOverflow = true;
  }
    }
}






bool controller::isValidCommand(unsigned char* ptr)
{
 return isLFDetected(ptr) && isOperationDetected(ptr) && isOperand1Detected(ptr) && isOperand2Detected(ptr);
}






bool controller::isDividedByZeroDetected(unsigned char* ptr)
{
 return isValidCommand(ptr) && getSecondOperand(ptr) == 0 && getOperation(ptr) == DIVIDE;
}






void controller::sanitize(unsigned char* ptr, int* position)
{
 *position = 0;
 init(ptr);
}






bool controller::isOperationDetected(unsigned char* ptr)
{
 return getOperationPosition(ptr) != -1;
}






bool controller::isOperand1Detected(unsigned char* ptr)
{
 unsigned char length = getOperationPosition(ptr);
 unsigned char* trimPtr = trimSpaces(ptr, &length);
 return isNumber(trimPtr, length);
}






bool controller::isOperand2Detected(unsigned char* ptr)
{
 unsigned char length = getLFPosition(ptr) - getOperationPosition(ptr) - 1;
 unsigned char* trimPtr = trimSpaces(ptr + getOperationPosition(ptr) + 1, &length);
 return isNumber(trimPtr, length);
}






bool controller::isNumber(unsigned char* ptr, unsigned char length)
{
 bool isFirstCharacter = true;
 int i;

 for(i=0;i<length;i++)
 {
  if (isSpace(ptr[i]))
   return false;

  if (isFirstCharacter && !isDigit(ptr[i]) && !isNegative(ptr[i]))
   return false;

  if (!isFirstCharacter && !isDigit(ptr[i]))
   return false;

  isFirstCharacter = false;
 }

 return true;
}






bool controller::isLFDetected(unsigned char* ptr)
{
 return getLFPosition(ptr) != -1;
}






int controller::getLFPosition(unsigned char* ptr)
{
 int i;
 for(i=0;i<20;i++)
  if (isLF(ptr[i]))
   return i;
 return -1;
}






bool controller::isLF(unsigned char character)
{
 return character == 0xD || character == 0xA;
}






unsigned char* controller::trimSpaces(unsigned char* ptr, unsigned char* length)
{
 int i;
 int count = 0;


 for(i=0;i<*length;i++)
  if (isSpace(ptr[i]))
   continue;
  else
   break;

 unsigned char* tmpPtr = ptr + i;
 *length -= i;


 for(i=*length-1;i>=0;i--)
 {
  if (isSpace(tmpPtr[i]))
   count++;
  else
   break;
 }

 *length -= count;

 return tmpPtr;
}






Operation controller::getOperation(unsigned char* ptr)
{
 unsigned char operation = ptr[getOperationPosition(ptr)];

 if (operation == '+')
 {
  if (GetVerbose())
   SpacePrint("Addition detected!\n");

  return ADD;
 }

 if (operation == '-')
 {
  if (GetVerbose())
   SpacePrint("Subtraction detected!\n");

  return SUBTRACTION;
 }

 if ((operation == '*') || (operation == 'x') || (operation == 'X'))
 {
  if (GetVerbose())
   SpacePrint("Multiplication detected!\n");

  return MULTIPLY;
 }

 if (operation == 'z')
 {
  if (GetVerbose())
   SpacePrint("Matrix multiplication detected!\n");

  return MATRIX_MUL;
 }

 if (GetVerbose())
  SpacePrint("Division detected!\n");

 return DIVIDE;
}






long controller::delegateOperation(Operation operation, long operand1, long operand2)
{
 long result;
    switch (operation)
    {
        case ADD:
        {
         sendAdditionOperand(operand1);
         sendAdditionOperand(operand2);
         result = readAdditionResult();

    SpacePrint("%d + %d = %d\n", operand1, operand2, result);

         break;
        }
        case SUBTRACTION:
        {
         sendSubtractionOperand(operand1);
         sendSubtractionOperand(operand2);
         result = readSubtractionResult();

    SpacePrint("%d - %d = %d\n", operand1, operand2, result);

         break;
        }
        case MULTIPLY:
        {
         sendMultiplicationOperand(operand1);
         sendMultiplicationOperand(operand2);
         result = readMultiplicationResult();

    SpacePrint("%d * %d = %d\n", operand1, operand2, result);

         break;
        }
        case DIVIDE:
        {
         sendDivisionOperand(operand1);
         sendDivisionOperand(operand2);
         result = readDivisionResult();

    SpacePrint("%d / %d = %d\n", operand1, operand2, result);

         break;
        }
        case MATRIX_MUL:
        {

         SpacePrint("Demarrage mult mat\n");

         sendMatrix(operand1);
         sendMatrix(operand2);

         SpacePrint("Fin envoi matrice\n");

         readMatrixMultiplicationResult();

         SpacePrint("Fin recuperation matrice\n");




         SpacePrint("%d z %d =\n", operand1, operand2);
# 592 "comms/controller.cpp"
         break;
        }
    }

    return result;
}






void controller::sendAdditionOperand(long data)
{
 ModuleWrite(0, SPACE_BLOCKING, &data);
}






void controller::sendSubtractionOperand(long data)
{
 ModuleWrite(6, SPACE_BLOCKING, &data);
}






void controller::sendMultiplicationOperand(long data)
{
 ModuleWrite(4, SPACE_BLOCKING, &data);
}






void controller::sendDivisionOperand(long data)
{
 ModuleWrite(2, SPACE_BLOCKING, &data);
}






void controller::sendMatrix(long index)
{
 ModuleWrite(21, SPACE_BLOCKING, matrix_data[index], 100*100);
}






long controller::readAdditionResult()
{
 long data;

 ModuleRead(0, SPACE_BLOCKING, &data);

    return data;
}






long controller::readSubtractionResult()
{
 long data;

 ModuleRead(6, SPACE_BLOCKING, &data);

    return data;
}






long controller::readMultiplicationResult()
{
 long data;

 ModuleRead(4, SPACE_BLOCKING, &data);

    return data;
}






long controller::readDivisionResult()
{
 long data;

 ModuleRead(2, SPACE_BLOCKING, &data);

    return data;
}






void controller::readMatrixMultiplicationResult()
{
 ModuleRead(21, SPACE_BLOCKING, m_matrix_result, 100*100);

}






void controller::init(unsigned char* ptr)
{
 int i=0;
 for(i=0;i<20;i++)
  ptr[i] = 0;
}






int controller::atoi(unsigned char c)
{
 return c - 0x30;
}






unsigned char controller::itoa(unsigned int x)
{
 return x + 0x30;
}






int controller::getOrder(unsigned long data)
{
 if (data == 0)
  return 0;

 int order = 0;

 while (data >= pow(10, order))
 {
  order++;
 }

 return --order;
}






void controller::displayMessage(char* message)
{
 int i=0;
 do
 {
  sendCharacter(message[i]);
 } while(!isLF(message[i++]));

 sendCharacter(0xD);
}
