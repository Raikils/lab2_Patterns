#include "MemoryUsage.h"

/*!Implementation of  MemoryUsage!*/

/*!
\code

int MemoryUsage::CurrentUsage() { return TotalAllocated - TotalFreed; }

\endcode
*/
int MemoryUsage::CurrentUsage() { return TotalAllocated - TotalFreed; }

/*!Implementation of  SetUsage!*/


/*!
\code

void SetCurrentUsage()
{
    s_MemoryUsage.TotalAllocated = 0;
    s_MemoryUsage.TotalFreed = 0;
}

\endcode
*/

void SetCurrentUsage()
{
	s_MemoryUsage.TotalAllocated = 0;
	s_MemoryUsage.TotalFreed = 0;
}

 /*!Implementation of  operator new!*/

/*!
\code

 void*  operator new(size_t size)
 {

     s_MemoryUsage.TotalAllocated += size;
     return malloc(size);
 }

\endcode
*/

 void*  operator new(size_t size)
 {
	 
	 s_MemoryUsage.TotalAllocated += size;
	 return malloc(size);
 }

 /*!
 \param[in] size input parametr
 */
  /*!Implementation of  operator delete!*/

 /*!
 \code

 void  operator delete(void* memory, int size)
 {

     s_MemoryUsage.TotalFreed += size;
     free(memory);
 }

 \endcode
 */
 void  operator delete(void* memory, int size)
 {
	
	 s_MemoryUsage.TotalFreed += size;
	 free(memory);
 }

 /*!
 \param[in] memory input parametr
  \param[in] size input parametr
 */
  /*!Implementation of  PrintUsage!*/

 /*!
 \code

 extern  std::string PrintUsage()
 {

     std::string c = std::to_string(s_MemoryUsage.CurrentUsage());
     return c ;
 }



 \endcode
 */
 extern  std::string PrintUsage()
 {
	 
	 std::string c = std::to_string(s_MemoryUsage.CurrentUsage());
     return c ;
 }
 
 
