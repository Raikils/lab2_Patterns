#pragma once

#include <memory>
#include <string>
#include <iostream>


struct MemoryUsage
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed= 0 ;
	int CurrentUsage();
};


void SetCurrentUsage();
static  MemoryUsage s_MemoryUsage;
void*  operator new(size_t size);
void operator delete(void* memory, int size);

extern std::string PrintUsage();
