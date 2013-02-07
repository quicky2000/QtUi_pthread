#include "test_thread.h"
#include <unistd.h>
#include <iostream>
#include <sstream>

//--------------------------------------------------------------------------=---
test_thread::test_thread(main_window_if & p_window):
  m_main_window_if(p_window)
{
}

//--------------------------------------------------------------------------=---
void * test_thread::run(void)
{
  std::cout << "Thread start run" << std::endl ;
  for(unsigned int l_index = 0 ;l_index < 10 ; ++l_index)
    {
      std::cout << "Loop " << l_index << std::endl ;      
      std::stringstream l_stream;
      l_stream << "loop " << l_index;
      m_main_window_if.display_status_message(l_stream.str());
      sleep(3);
    }
  std::cout << "End of thread run" << std::endl ;
  m_main_window_if.end_of_thread();
  return NULL;
}

//EOF
