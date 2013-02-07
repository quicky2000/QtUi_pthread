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
