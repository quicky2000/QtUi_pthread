/*
    This file is part of QtUi_pthread
    Copyright (C) 2012  Julien Thevenon ( julien_thevenon at yahoo.fr )

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
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
