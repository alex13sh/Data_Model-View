#include "mymodel.h"

MyModel::MyModel()
{

}



MNode::MNode(MNode *parent) :Parent(parent)
{

}

MNode::MNode(const QString &name, MNode *parent): Parent(parent), Name(name)
{

}

void MNode::addChild(MNode *child){
    // Duplicate prt check
    this->Childs.append(child);
    childsChange(); // signal about change
}

MNode *MNode::addChild(const QString &name){
    // Duplicate names check
    MNode *tmp= new MNode(name, this);
    this->Childs.append(tmp);
    childsChange(); // signal about change
    return tmp;
}
