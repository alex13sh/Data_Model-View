#ifndef MITREE_H
#define MITREE_H

#include <QString>

class MITree
{
public:
    MITree(){}

    virtual void addChilds(const QString &path, const QString &name)=0;

    virtual void setText(const QString &path, const QString &text)=0;
    virtual void remove(const QString &path)=0;

    virtual QStringList getChilds(const QString &path)=0;
};

#endif // MITREE_H
