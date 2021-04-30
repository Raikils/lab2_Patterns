#include "pch.h"
#include "MemoryUsage.h"

int MemoryUsage::CurrentUsage() { return TotalAllocated - TotalFreed; }

void SetCurrentUsage()
{
	s_MemoryUsage.TotalAllocated = 0;
	s_MemoryUsage.TotalFreed = 0;
}

 
 void*  operator new(size_t size)
 {
	 
	 s_MemoryUsage.TotalAllocated += size;
	 return malloc(size);
 }

 void  operator delete(void* memory, int size)
 {
	
	 s_MemoryUsage.TotalFreed += size;
	 free(memory);
 }



 extern  std::string PrintUsage()
 {
	 
	 std::string c = std::to_string(s_MemoryUsage.CurrentUsage());
     return c ;
 }
 
 
