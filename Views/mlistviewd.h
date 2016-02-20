#ifndef MLISTVIEWD_H
#define MLISTVIEWD_H

#include <QWidget>
#include <QListWidgetItem>

#include "../Interfaces/mitree.h"

namespace Ui {
class MListViewD;
}

class MListViewD : public QWidget
{
    Q_OBJECT

    MITree *ITree;
    QVector<QString> paths;
public:
    explicit MListViewD(QWidget *parent = 0);
    ~MListViewD();

    void setInterface(MITree *tree){ITree=tree;}

    void goHome();
    void update();
private slots:
    void on_cmdAdd_clicked();

    void on_cmdGo_clicked();

    void on_lstChilds_itemDoubleClicked(QListWidgetItem *item);

    void on_cmdBack_clicked();

private:
    Ui::MListViewD *ui;
};

#endif // MLISTVIEWD_H
