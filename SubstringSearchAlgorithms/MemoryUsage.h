#pragma once

#include <memory>
#include <string>
#include <iostream>


#ifdef SubstringSearchAlgorithms_lib
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif


struct DECLSPEC MemoryUsage
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed= 0 ;
	int CurrentUsage();
};


void SetCurrentUsage();
static  MemoryUsage s_MemoryUsage;
void*  operator new(size_t size);
void DECLSPEC operator delete(void* memory, int size);

extern DECLSPEC std::string PrintUsage();