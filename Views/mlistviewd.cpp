#include "mlistviewd.h"
#include "ui_mlistviewd.h"

#include <QDebug>


MListViewD::MListViewD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MListViewD)
{
    ui->setupUi(this);
}

MListViewD::~MListViewD()
{
    delete ui;
}

void MListViewD::goHome(){
    ui->txtPath->setText("\\");
    this->on_cmdGo_clicked();
}

void MListViewD::update(){
    qDebug()<<"MListViewD::update";
    if(!ITree) return;
    ui->lstChilds->clear();
    qDebug()<<"\tclear;";
    ui->lstChilds->addItems(ITree->getChilds(ui->txtPath->text()));
    qDebug()<<"\tfill;";
}

void MListViewD::on_cmdAdd_clicked(){
    if(!ITree) return;
    ITree->addChilds(ui->txtPath->text(), ui->txtName->text());
    ui->txtName->clear();
    this->update();
}

void MListViewD::on_cmdGo_clicked(){
    if(!ITree) return;
    if(ui->txtPath->text().isEmpty()) return;
    paths.append(ui->txtPath->text()); if(paths.size()>10) paths.removeFirst();
    //ITree->pathGo(ui->txtPath->text());
    this->update();
}

void MListViewD::on_lstChilds_itemDoubleClicked(QListWidgetItem *item){
    ui->txtPath->setText(ui->txtPath->text() + item->text() + "\\");
    this->on_cmdGo_clicked();
}

void MListViewD::on_cmdBack_clicked(){
    QString path;
    if(paths.size()>1) {
        path=paths.takeLast(); path=paths.takeLast();
    }
    ui->txtPath->setText(path); this->on_cmdGo_clicked();
}
