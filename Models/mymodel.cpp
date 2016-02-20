#include "mymodel.h"
#include <QDebug>
#include <QRegExp>


MyModel::MyModel(MNode *node): MNode(node)
{}



MNode *MNode::getParent() const{
    return Parent;
}

void MNode::setParent(MNode *value){
    Parent = value;
}
MNode::MNode(MNode *parent) :Parent(parent)
{}
MNode::MNode(const QString &name, MNode *parent): Parent(parent), Name(name)
{}

void MNode::setName(const QString &name){
    Name=name;
    Parent->childsChange();
}

void MNode::setText(const QString &text){
    Text=text;
    Parent->childsChange();
}

void MNode::addChild(MNode *child){
    // Duplicate prt check
    this->Childs.append(child);
    this->childsChange(); // signal about change
}

MNode *MNode::addChild(const QString &name){
      // Duplicate names check
    MNode *tmp=0;
    if((tmp=findChild(name))==0)  tmp=new MNode(name, this); else return tmp;
    this->Childs.append(tmp);
    this->childsChange(); // signal about change
    return tmp;
}

MNode *MNode::findChild(const QString &name){
    for(int i=0;i<Childs.size();++i)
        if(Childs[i]->Name==name) return Childs[i];
    return 0;
}

void MNode::swap(MNode *other){
    swap(this,other);
}

void MNode::swap(MNode *n1, MNode *n2){
    MNode *p=n1->Parent; // ----
    n1->Parent=n2->Parent;
    n2->Parent=p;
}


MyModelO::MyModelO( QObject *parent) : QObject(parent)
{}

void MyModelO::childsChange()
{}

MNode *MyModelO::path(const QString &path){
    qDebug()<<"MyModelO::path ("<<path<<")";
//    QString name;
//    int p1=0,p2=0;

//    p2=path.indexOf(QRegularExpression("\\"),p1);
//    name=path.mid(p1,p2);

    QStringList names =path.split("\\");

    if(names.size()==0) return this;
    if(names.size())if(names.first()==QString("")) names.removeFirst();
    if(names.size())if(names.last()==QString("")) names.removeLast();
    if(names.size()==0) return this;

    //if(names.first()!=this->Name) return 0;
    MNode *cur=0,*tmp=0;
    cur=this;
    for(int i=0; i<names.size();++i)
        if(cur) {tmp=cur->findChild(names[i]); if(tmp) cur=tmp; else return cur;} else return 0;
    qDebug()<<"\treturn "<<cur->name();
    return cur;
}

void MyModelO::addChilds(const QString &path, const QString &name){
    qDebug()<<"MyModelO::addChilds ("<<name<<")";
    MNode *tmp=this->path(path);
    if(tmp) tmp=tmp->addChild(name);
    qDebug()<<"\treturn "<<tmp->name();
}

void MyModelO::setText(const QString &path, const QString &text){
    qDebug()<<"MyModelO::setText ("<<text<<")";
    MNode *tmp=this->path(path);
    if(tmp) tmp->setText(text);
    qDebug()<<"\treturn "<<tmp->text();
}

 QStringList MyModelO::getChilds(const QString &path){
    qDebug()<<"MyModelO::getChilds ";
    QStringList lst; MNode *tmp=this->path(path);
    if(!tmp) return QStringList("")<<"";
    foreach (MNode* nd, tmp->getChilds()) {
        if(nd)lst<<nd->name();
    }
    qDebug()<<"\treturn "<<lst;
    return lst;
}
MyModelO::MyModelO(MNode *node, QObject *parent) : MyModel(node), QObject(parent)
{}
