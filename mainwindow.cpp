#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Models/mymodel.h"
#include "Views/mlistviewd.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyModelO *mdl= new MyModelO(new MNode("Корень"));

    MListViewD *lvd = new MListViewD(this);
    lvd->setInterface(mdl);
    lvd->goHome();

    this->setCentralWidget(lvd);
}

MainWindow::~MainWindow()
{
    delete ui;
}
