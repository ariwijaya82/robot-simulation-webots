#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtGui/QAction>

#include "panel.hpp"

class MainWindow : public QMainWindow {
  public:
    MainWindow(GlobalData* global);

  private:
    Panel *panel;

    QMenu *modeMenu;
    QMenu *viewMenu;
    QAction *simulateAct;
    QAction *astarAct;
    QAction *bezierAct;
    
    QAction *nodeAct;
    QAction *visNodeAct;
    QAction *robotAreaAct;
    QAction *astarPathAct;
    QAction *bezierPathAct;
    QAction *followingPathAct;
    QAction *robotAct;

    void createActions();
    void createMenus();
    void connectActions();

    void handleModeChanged(int);
    void handleViewChanged(int, bool);
};

#endif