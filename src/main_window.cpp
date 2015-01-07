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
#include "main_window.h"
#include <QAction>
#include <QMenu>
#include <QLabel>
#include <QMessageBox>
#include <QStatusBar>
#include <QFileDialog>
#include <QCloseEvent>
#include <QMenuBar>
#include <QDialog>

#include <iostream>
#include <cassert>
#include "test_thread.h"

using namespace std;

//------------------------------------------------------------------------------
main_window::main_window(void):
  m_exit_action(NULL),
  m_launch_thread_action(NULL),
  m_file_menu(NULL),
  m_status_label(NULL),
  m_tab_widget(NULL),
  m_thread(NULL)
{
  setWindowTitle(tr("SODA"));
  create_actions();
  create_menus();
  create_status_bar();

  m_tab_widget = new QTabWidget();
  connect(m_tab_widget,SIGNAL(currentChanged(int)),this, SLOT(treat_tab_changed_event(int)));



  setCentralWidget(m_tab_widget);

  setMinimumSize(160, 160);
  resize(1024, 768);
}

//---------------------------------------------------
// Methods inherited from fichier_client_UI_if class
//---------------------------------------------------
// Comunication with user
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void main_window::display_status_message(const std::string & p_text)
{
  m_status_label->setText(p_text.c_str());
}

//------------------------------------------------------------------------------
void main_window::end_of_thread(void)
{
  display_status_message("Thread terminated");
  delete m_thread;
  m_thread = NULL;
  m_launch_thread_action->setEnabled(true);
}

//------------------------------------------------------------------------------
bool main_window::ask_yes_no_qestion(const std::string & p_title, const std::string & p_question)
{
  int l_result = QMessageBox::question(this,
				       p_title.c_str(),
				       p_question.c_str(),
				       QMessageBox::Yes | QMessageBox::Default,
				       QMessageBox::No);
  return l_result == QMessageBox::Yes;
}


//------------------------------------------------------------------------------
void main_window::treat_tab_changed_event(int index)
{
  std::cout << "QtEvent::tab changed" << std::endl ;
  assert(m_tab_widget);
}

//------------------------------------------------------------------------------
void main_window::exit(void)
{
  cout << "QtEvent::Exit" << endl ;
  close();
}

//------------------------------------------------------------------------------
void main_window::treat_launch_thread_event(void)
{
  cout << "QtEvent::Launch_Thread" << endl ;

  pthread_t l_thread_id;
  // Creating pthread attributes
  pthread_attr_t l_attr;
  pthread_attr_init(&l_attr);
  //  pthread_attr_setdetachstate(&l_attr,PTHREAD_CREATE_JOINABLE);
  pthread_attr_setdetachstate(&l_attr,PTHREAD_CREATE_DETACHED);

  assert(!m_thread);
  m_thread = new test_thread(*this);
  m_launch_thread_action->setEnabled(false);

  // creating threads
  pthread_create(&l_thread_id,&l_attr,my_thread::launch_thread,(void*)m_thread);

  std::cout << "End of Launch Thread event" << std::endl ;
}

//------------------------------------------------------------------------------
void main_window::closeEvent(QCloseEvent *event)
{
  string l_question("Are you sure want to quit ?");
  if(m_thread)
    {
      l_question += "\nSome thread are still running !\n";
    }
  int l_result = QMessageBox::question(this, tr("Quit"),
				       tr(l_question.c_str()),
				       QMessageBox::Yes | QMessageBox::Default,
				       QMessageBox::No);
  if (l_result == QMessageBox::Yes)
    {
      event->accept();
    }
  else
    {
      event->ignore();
    }
}

//------------------------------------------------------------------------------
void main_window::create_actions(void)
{
  m_launch_thread_action = new QAction(tr("&Launch Thread"),this);
  m_launch_thread_action->setShortcut(tr("Ctrl+L"));
  m_launch_thread_action->setStatusTip(tr("Launch Thread")); 
  connect(m_launch_thread_action,SIGNAL(triggered()),this,SLOT(treat_launch_thread_event()));

  m_exit_action = new QAction(tr("&Quit"),this);
  m_exit_action->setShortcut(tr("Ctrl+Q"));
  m_exit_action->setStatusTip(tr("Quit the application")); 
  connect(m_exit_action,SIGNAL(triggered()),this,SLOT(exit()));
}

//------------------------------------------------------------------------------
void main_window::create_menus(void)
{
  m_file_menu = menuBar()->addMenu(tr("&File"));
  m_file_menu->addAction(m_launch_thread_action);
  m_file_menu->addAction(m_exit_action);

  // Manage action activation
  m_exit_action->setEnabled(true);
  m_launch_thread_action->setEnabled(true);
}

//------------------------------------------------------------------------------
void main_window::create_status_bar(void)
{
  m_status_label = new QLabel("Status bar");
  statusBar()->addWidget(m_status_label);
}

//EOF
