#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QFileDialog>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void loadImage();
    void saveImage();
    void decodeMsg();
    void encodeMsg();
    void msgChanged();
private:
    Ui::MainWindow *ui;
    QImage image;

};
#endif // MAINWINDOW_H
