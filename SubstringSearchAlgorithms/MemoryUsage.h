#pragma once

#include <memory>
#include <string>
#include <iostream>

/*!Struct for count used memory*/
struct MemoryUsage
{
    /*!Variable for storage how many memory allocated*/
	uint32_t TotalAllocated = 0;
      /*!Variable for storage how many memory freed*/
	uint32_t TotalFreed= 0 ;
     /*!A method for finding how much memory is being used right now */
	int CurrentUsage();
};

/*!A function for set 0 for TotalAllocated and TotalFreed*/
void SetCurrentUsage();
/*!A static variable that storage count of memory*/
static  MemoryUsage s_MemoryUsage;
/*!Memory allocating function*/
void*  operator new(size_t size);
/*!Memory freeding function*/
void operator delete(void* memory, int size);
/*!Function for print */
extern std::string PrintUsage();
