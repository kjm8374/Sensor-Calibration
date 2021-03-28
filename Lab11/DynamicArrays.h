/**************************************************************************
* Dynamic Arrays Module  - public interface
*
* data types: Data - struct with data to be stored
*             DArray - structure for Dynamic Array Header
*
* functions: CreateDArray, PushToDArray, DestroyDArray
*
* Author: Kushal Malhotra 
**************************************************************************/
#ifndef _DYNAMIC_ARRAYS_H_
#define _DYNAMIC_ARRAYS_H_

/* Growth Policy : Constant Size */
#define GROWTH_AMOUNT (100) 
#define MAX_STR_LEN   (256) 

/**************************  modify as needed *************************/
/** Data typemark to store payload: Modify according to application  ***/
/** In this case the payload consists of a sequence number and a word **/
#ifdef HW8
typedef struct {
   double x;
   double y;
  } Data;
#elif HW9
typedef struct {
   int Num;                   /* Sequence number */
   double point;
  } Data;
#else
    
typedef struct {
   char String[MAX_STR_LEN];  /* string MUST BE < MAX_STR_LEN*/
  } Data;
#endif 
/************ Nothing else in the module needs to be modified **********/



/************ Nothing else in the module needs to be modified **********/

/**************************************************************************
* DArray - Dynamic Array Header structure to keep track of its "state" 
*          The "state" of the Dynamic Array is: Capacity and EntriesUsed
**************************************************************************/
typedef struct {
   unsigned int Capacity;    /* Max Number of elements array can hold */
   unsigned int EntriesUsed; /* Number of array elements "used"       */
   Data *Payload;   /* Pointer to array that actually holds the data  */
  } DArray;

/***************************************************************************
 function prototypes to create, add and destroy data arrays
 **************************************************************************/
void CreateDArray( DArray *DArrayPtr, unsigned int InitialSize );
unsigned int PushToDArray( DArray *DArrayPtr, Data *PayloadPtr );
void DestroyDArray(DArray *DArrayPtr);
Data *SearchDArray(DArray *DArrayHead, char *String); /* Used in  hw4 */

#endif /* _DYNAMIC_ARRAYS_H_ */
