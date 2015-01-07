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
#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QMainWindow>

class QAction;
class QMenu;
class QLabel;
class QTabWidget;

#include "main_window_if.h"
class test_thread;

class main_window : public QMainWindow, public main_window_if
{
  Q_OBJECT

    public:
  main_window(void);

  //---------------------------------------------------
  // Methods inherited from fichier_client_UI_if class
  //---------------------------------------------------
  // Comunication with user
  void display_status_message(const std::string & p_text);
  bool ask_yes_no_qestion(const std::string & p_title, const std::string & p_question);
  void end_of_thread(void);

  private slots:
  void treat_tab_changed_event(int index);
  void treat_launch_thread_event();
  void exit();
  

 private:
  void closeEvent(QCloseEvent *event);
  void create_actions(void);
  void create_menus(void);
  void create_status_bar(void);

  QAction *m_exit_action;
  QAction *m_launch_thread_action;
  QMenu * m_file_menu;
  QLabel * m_status_label;
  QTabWidget *m_tab_widget;

  test_thread * m_thread;
};

#endif
