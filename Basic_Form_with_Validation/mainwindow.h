#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QSizePolicy>
#include <QSize>
#include <QEvent>
#include <QResizeEvent>
#include <QFormLayout>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void windowSizeChanged(const QSize &newSize);

private slots:
    void handle_signIn();
    void resizeEvent(QResizeEvent* event) override;
    void handleWindowStateChange(const QSize& size);

private:
    Ui::MainWindow *ui;
    QPushButton* signIn;
    QFormLayout* mainLayout;
    QHBoxLayout* firstLayout;
    QHBoxLayout* secondLayout;
    QWidget* widget;

    QLineEdit* userName;
    QLineEdit* passWord;

    QSize* windowSize;

};
#endif // MAINWINDOW_H
