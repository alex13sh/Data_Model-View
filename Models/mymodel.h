#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QVector>

// Модели нужны для работы с данными
// Моделей, возможно, будет несколько

class MNode{
protected:
    QString  Name, Text; // Данные этого узла
    QVector<MNode*> Childs; // Ссылки на детей . Vector - Это массив
    MNode *Parent;
public:
    MNode(MNode *parent=0);
    MNode(const QString &name,MNode *parent=0);



    void addChild(MNode *child);
    MNode *addChild(const QString &name);

    MNode *findChild(const QString &name);
    const QVector<MNode*> &getChilds() const {return Childs;}

public:
    void swap(MNode *other);
    static void swap(MNode *n1, MNode *n2);

public:
    MNode *getParent() const;
    void setParent(MNode *value);

    void setName(const QString &name);
    const QString &name()const {return Name;}
    void setText(const QString &text);
    const QString &text()const {return Text;}
protected:
    virtual void childsChange(){} // оповещаем наследника об изменениях
};

// Моя первая модель
class MyModel : public MNode
{
public:
    MyModel(MNode *node=0);

};

#include "../Interfaces/mitree.h"
// Обёртки

class MyModelO : public QObject , public MyModel, public MITree
{
    Q_OBJECT
public:
    MyModelO(QObject *parent=0);
    MyModelO(MNode *node=0, QObject *parent=0);

signals:
    sg_childsChange();
protected:
    void childsChange();

    MNode *path(const QString &path);

    // MITree interface
public:
    void addChilds(const QString &path, const QString &name);
    void setText(const QString &path, const QString &text);
    void remove(const QString &path){};

    QStringList getChilds(const QString &path);
};

#endif // MYMODEL_H
