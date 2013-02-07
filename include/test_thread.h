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
