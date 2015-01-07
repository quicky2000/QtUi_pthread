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
#ifndef _TEST_THREAD_H_
#define _TEST_THREAD_H_

#include "my_thread.h"
#include "main_window_if.h"

class main_window_if;

class test_thread: public my_thread
{
 public:
  test_thread(main_window_if & p_window);
  void* run(void);
  inline virtual ~test_thread(void){}
 private:
  main_window_if & m_main_window_if;
};
#endif // _TEST_THREAD_H_
