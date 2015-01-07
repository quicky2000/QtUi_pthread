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
