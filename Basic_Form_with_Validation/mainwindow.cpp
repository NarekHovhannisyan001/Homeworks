#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Basic Form with Validation");

    // Create central widget and layouts
    widget = new QWidget(this);
    mainLayout = new QFormLayout(widget);
    firstLayout = new QHBoxLayout();
    secondLayout = new QHBoxLayout();
    QSize tmpSize = this->size();
    windowSize = new QSize(tmpSize.width(),tmpSize.height());

    // Create widgets
    userName = new QLineEdit(this);
    passWord = new QLineEdit(this);
    passWord->setEchoMode(QLineEdit::Password); // Set password mode for the password field

    // Calculate the width for QLineEdit widgets
    int editWidth = windowSize->width() / 2;

    // Set fixed width for QLineEdit widgets
    userName->setFixedWidth(editWidth);
    passWord->setFixedWidth(editWidth);

    signIn = new QPushButton("Sign In");
    signIn->setStyleSheet("QPushButton { min-width: 10em; min-height: 5em; }");


    // Add widgets to layouts
    firstLayout->addWidget(new QLabel("Username:"));
    firstLayout->addWidget(userName);
    firstLayout->addStretch(1);
    secondLayout->addWidget(new QLabel("Password:"));
    secondLayout->addWidget(passWord);
    secondLayout->addStretch(1);

    // *spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    QHBoxLayout *signInLayout = new QHBoxLayout();
    // signInLayout->setAlignment(Qt::AlignCenter);
    signInLayout->addWidget(signIn, 0, Qt::AlignHCenter);
    //signInLayout->addSpacerItem(spacer);
    int buttonMargin = windowSize->width();
    signIn->setStyleSheet("margin-right:" + QString::number(buttonMargin) + "px");
    // Add layouts to main layout
    mainLayout->addRow(firstLayout);
    mainLayout->addRow(secondLayout);
    mainLayout->addRow(signInLayout);

    mainLayout->setSpacing(20);



    // Set size policies to expanding
    userName->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    passWord->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    signIn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);


    // Set central widget
    setCentralWidget(widget);




    // Connect button click to slot
    connect(signIn, &QPushButton::clicked, this, &MainWindow::handle_signIn);
    connect(this, &MainWindow::windowSizeChanged, this, &MainWindow::handleWindowStateChange);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle_signIn() {
    QString username = userName->text();
    QString password = passWord->text();

    // Check if either username or password is empty
    if (username.isEmpty() || password.isEmpty()) {
        // Display error message box
        QMessageBox::critical(this, "Error", "Please enter both username and password.");
        return;
    } else {
        userName->clear();
        passWord->clear();
    }

}


void MainWindow::resizeEvent(QResizeEvent *event) {
    // Emit the window size changed signal whenever the window is resized-09876543234567890-]
    emit windowSizeChanged(event->size());
}

void MainWindow::handleWindowStateChange(const QSize &size) {
    // Calculate the width for QLineEdit widgets
    int editWidth = size.width() / 2;

    // Set the new width for the QLineEdit widgets
    userName->setFixedWidth(editWidth);
    passWord->setFixedWidth(editWidth);
    signIn->setStyleSheet("margin-right:" + QString::number(editWidth) + "px");
}
