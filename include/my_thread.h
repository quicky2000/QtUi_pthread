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
