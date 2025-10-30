#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Model* SimonGame, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void lightRed();
    void lightBlue();
    void setStatus(Model::GameStatus);

private:
    Ui::MainWindow *ui;
    //model variable
    Model* simonGame;
};
#endif // MAINWINDOW_H
