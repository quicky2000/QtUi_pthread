#ifndef MAIN_WINDOW_IF_H
#define MAIN_WINDOW_IF_H

#include <string>

class main_window_if
{
 public:
  virtual void display_status_message(const std::string & p_text)=0;
  virtual void end_of_thread(void)=0;
 private:
};

#endif // MAIN_WINDOW_IF_H
