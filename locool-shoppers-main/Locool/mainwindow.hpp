#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#include <QMainWindow>
#include <QDebug>
#include <QFileInfo>
#include <QDir>

#if defined Q_OS_WIN
static const QDir ASSET_ROOT("../../locool-shoppers/assets");
#endif

#if defined Q_OS_MAC
static const QDir ASSET_ROOT("../../../../../locool-shoppers/assets");
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
