#include "MemoryUsage.h"

/*!Implementation of  MemoryUsage!*/



int MemoryUsage::CurrentUsage() { return TotalAllocated - TotalFreed; }

/*!Implementation of  SetUsage!*/




void SetCurrentUsage()
{
	s_MemoryUsage.TotalAllocated = 0;
	s_MemoryUsage.TotalFreed = 0;
}

 /*!Implementation of  operator new!*/



 void*  operator new(size_t size)
 {
	 
	 s_MemoryUsage.TotalAllocated += size;
	 return malloc(size);
 }

 /*!
 \param[in] size input parametr
 */
  /*!Implementation of  operator delete!*/


 void  operator delete(void* memory, size_t size)
 {
	
	 s_MemoryUsage.TotalFreed += size;
	 free(memory);
 }

 /*!
 \param[in] memory input parametr
  \param[in] size input parametr
 */
  /*!Implementation of  PrintUsage!*/



 extern  std::string PrintUsage()
 {
	 
	 std::string c = std::to_string(s_MemoryUsage.CurrentUsage());
     return c ;
 }
 
 
