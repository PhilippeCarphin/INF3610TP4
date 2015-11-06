///////////////////////////////////////////////////////////////////////////////
//
// Filename : matrix_mul.cpp
//
// Creation date : Tue Oct 27 15:02:38 EDT 2015
//
///////////////////////////////////////////////////////////////////////////////
#include "matrix_mul.h"

#include "PlatformDefinitions.h"
#include "ApplicationDefinitions.h"
#include "SpaceDisplay.h"
#include "SpaceTypes.h"
#include "matrix_def.h"

matrix_mul::matrix_mul(sc_core::sc_module_name name, double period, sc_core::sc_time_unit unit, unsigned char id, unsigned char priority, bool verbose)
:SpaceBaseModule(name, period, unit, id, priority, verbose) {
 SC_THREAD(thread);
 //0x16000 is the default stack size
 set_stack_size(0x16000+(100*100*4*3));
}

void matrix_mul::thread(void) {

 unsigned int matrix1[100*100];
 unsigned int matrix2[100*100];
 unsigned int result[100*100];
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

//////////////////////////////////////////////////////////////////////////////
///
///	Multiplication
///
//////////////////////////////////////////////////////////////////////////////
void matrix_mul::multiply(unsigned int* matrix1, unsigned int* matrix2, unsigned int* result)
{
 unsigned int temp_acc;
 for(int i=0;i<100;i++) {
  for(int j=0; j<100;j++)
  {
   for(int k= 0; k< 100;k++)
   {
    temp_acc += (matrix1[i*100 +k] * matrix2[k*100 +j]);
   }
   result[i*100 +j] = temp_acc;
   temp_acc = 0;
  }
 }
}

//////////////////////////////////////////////////////////////////////////////
///
///	Read a matrix
///
//////////////////////////////////////////////////////////////////////////////
void matrix_mul::readMatrix(unsigned int* matrix)
{
 ModuleRead(1, SPACE_BLOCKING, matrix, 100*100);
}

//////////////////////////////////////////////////////////////////////////////
///
///	Send the result
///
//////////////////////////////////////////////////////////////////////////////
void matrix_mul::sendResult(unsigned int* matrix)
{
 ModuleWrite(1, SPACE_BLOCKING, matrix, 100*100);
}
