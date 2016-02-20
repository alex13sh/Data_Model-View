#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QVector>

// Модели нужны для работы с данными
// Моделей, возможно, будет несколько

struct MNode{
    QString  Name, Text; // Данные этого узла
    QVector<MNode*> Childs; // Ссылки на детей . Vector - Это массив
    MNode *Parent;
public:
    MNode(MNode *parent=0);
    MNode(const QString &name,MNode *parent=0);

    void addChild(MNode *child);
    MNode *addChild(const QString &name);



protected:
    virtual void childsChange(){}
};

// Моя первая модель
class MyModel
{
public:
    MyModel();

};


// Обёртки

class MyModelO : public QObject , public MyModel
{
    Q_OBJECT
public:

};

#endif // MYMODEL_H
