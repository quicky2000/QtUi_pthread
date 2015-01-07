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
#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <pthread.h>

class my_thread
{
 public:
  virtual void* run(void)=0;
  static void* launch_thread(void* p_arg)
  {
    my_thread *l_thread = (my_thread*) p_arg;
    pthread_exit(l_thread->run());
  }
 private:
};

#endif // MY_THREAD_H
