#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // New QLabel for the top text
    QLabel *topText = new QLabel("Click Counter", this);
    topText->setStyleSheet("font-size: 20px; color: white; background: blue;");
    topText->setAlignment(Qt::AlignCenter);
    topText->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);



    ui->setupUi(this);
    this->setFixedSize(300,350);
    this->setWindowTitle("Click counter");
    this->setStyleSheet("background: green");

    label = new QLabel("0", this);
    label->setStyleSheet("background: black");
    label->setFixedSize(100,30);
    label->setAlignment(Qt::AlignCenter);

    button = new QPushButton("Click", this);
    button->setStyleSheet("background: black");
    button->setFixedSize(100,50);

    reset = new QPushButton("Reset", this);
    reset->setStyleSheet("background: black");
    reset->setFixedSize(100,50);

    widget = new QWidget(this);

    hLayout = new QHBoxLayout;

    hLayout->addWidget(button);
    hLayout->addWidget(reset);

    layout = new QVBoxLayout(widget);

    layout->addWidget(topText,0,Qt::AlignHCenter);
    layout->addWidget(label,0,Qt::AlignHCenter);
    layout->addLayout(hLayout);
    layout->setAlignment(Qt::AlignVCenter);
    QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(spacer);
    this->setCentralWidget(widget);





    connect(button, &QPushButton::clicked, this, &MainWindow::click_handler);
    connect(reset,&QPushButton::clicked,this,&MainWindow::reset_handler);
}




MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::click_handler() {
    label->setText(QString::number(label->text().toInt() + 1));

}

void MainWindow::reset_handler() {
    label->setText("0");
}
