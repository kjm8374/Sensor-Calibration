/**
 ** DynamicArrays.c
 **
 ** Description: This program implements functions for a Dynamic Array             
 **              data structure.       
 **                                                                           
 ** Author: Kushal Malhotra                                                                       
 ** 
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClassErrors.h"
#include "DynamicArrays.h"

/***************************************************************************
 CreateDArray -- Allocates memory and initializes DArray state             
        void CreateDArray(DArray *DArrayHead, unsigned int InitialSize)
 Where:
    DArray *DArrayHead       - Pointer to a storage block which holds the
                               data structure entry 
    unsigned int InitialSize - The initial data block size, could be 0
    returns: void            - nothing is returned.
    errors:                  - This routine will print an error message to 
                               stderror and exit with an error code
 **************************************************************************/
void CreateDArray(DArray *DArrayHead, unsigned int InitialSize) {
   /************************************************************************
   Pseudo code: 
   Initialize array with 0 entries used 
   Initialize capacity (you decide, could be zero)
   Based on capacity allocate memory storage, if necessary 
      If initial capacity is zero, no allocation needed 
      else Allocate storage space for payload according to struc Data
   if memory not allocated print error to stderr and exit with a code 
   
  ************************************************************************/
  DArrayHead->Capacity = InitialSize;
  DArrayHead->EntriesUsed = 0;
    if (InitialSize != 0) {
      DArrayHead->Payload =(Data*)malloc((DArrayHead->Capacity)*sizeof(Data));
        if ((DArrayHead->Payload) == NULL) {
          fprintf(stderr, "error");
          exit(MALLOC_ERROR);  
        }
    }
  
} /* CreateDArray() */


/***************************************************************************
  PushToDArray -- Adds data at the end of the dynamic array and updates its 
                  state in the array header.  If full, reallocates memory 
                  space according to growth policy                          
        unsigned int PushToDArray(DArray *DArrayHead, Data *PayloadPtr)     
Where:
    DArray *DArrayHead      - Pointer to a storage block which holds the
                              data structure entry 
    Data * PayloadPtr       - 
    returns: unsigned int   - The index of the last element inserted
    errors:                 - This routine will print an error message to 
                              stderror and exit with an error code 
 **************************************************************************/
unsigned int PushToDArray(DArray *DArrayHead, Data *PayloadPtr)
{
   /************************************************************************
    Pseudo code: 
    Check if the array needs to be made larger 
    If yes, increase the size of the dynamic array by GROWTH_AMOUNT
    Re-allocate storage for the array elements using larger size 
    if memory not re-allocated print error to stderr and exit 
    Copy the Data in PlayloadPtr into the Darray
    Increment the number of elements used in Darray header 
    Return the array index of last element inserted 
   ************************************************************************/
   if (DArrayHead->Capacity == DArrayHead->EntriesUsed) {
     DArrayHead->Capacity = DArrayHead->Capacity + GROWTH_AMOUNT;
     DArrayHead->Payload = (Data*) realloc((DArrayHead->Payload),(DArrayHead->Capacity)*sizeof(Data));
     if ((DArrayHead->Payload) == NULL){
       fprintf(stderr,"error");
       exit(REALLOC_ERROR);
     }
     }
    memcpy(&(DArrayHead->Payload[DArrayHead->EntriesUsed]),PayloadPtr,sizeof(Data));
      return DArrayHead->EntriesUsed++;
 
} /* PushToDArray() */


/*************************************************************************
 DestroyDArray -- Returns the memory back to the heap and updates the   
                  state in the array header      
        void DestroyDArray(DArray *DArrayHead)
  Where:
    DArray *DArrayHead  - Pointer to a storage block which holds the
                          data structure entry 
    returns: void       - nothing is returned.
    errors:             - No errors are reported
*************************************************************************/
void DestroyDArray(DArray *DArrayHead)
{
   /**********************************************************************
    Pseudo code: 
    Set the number of entries used to zero in Darray header 
    Set the capacity to zero in Darray header
    De-allocate the storage for the array elements 
 *************************************************************************/
 DArrayHead->EntriesUsed = 0;
 DArrayHead->Capacity = 0;
 free(DArrayHead->Payload);
 DArrayHead->Payload = NULL;
} /* DestroyDArray() */

/**************************************************************************
 Searches the dynamic array for a provided word and returns the
 pointer to the data if found or NULL if not found.

 Where: DArray *DArrayHead - Pointer to the dynamic array to search
        char *String       - The item to search for
 Returns: A pointer to the data found or NULL for not found
 Errors: none
***************************************************************************/
Data *SearchDArray(DArray *DArrayHead, char *String) {
   
   /*-----  Don't implement this until instructed in Lab 6 ----*/
 	//int count = 0;
	//	while (!(count == DArrayHead->EntriesUsed)){
	//	if (!strcmp(DArrayHead->Payload[count].String,String)){
	//		return &(DArrayHead->Payload[count]);	
	//	}
	//	else {
	//		count++;	
	//	}
	//	}
   
   return NULL;
} /* SearchDArray() */
