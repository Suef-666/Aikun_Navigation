#include "node.h"
#include <QString>
#include <QPoint>

Node::Node(int x,int y,int index){

    point.setX(x);
    point.setY(y);
    Index = index;
    Name = nullptr;
}

Node::Node(int x,int y,int index,QString name ){

    point.setX(x);
    point.setY(y);
    Index = index;
    Name = name;
}

Node::Node(int index ,QString name){

    point.setX(0);
    point.setY(0);
    Index = index;
    Name = name;
}


Node::~Node(){

}

QPoint Node::poi(){
    return point;
}

int Node::getIndex(){
    return Index;
}

bool Node::isReal(){
    return real;
}

void Node::setReal(bool really){
    real = really;
}

void Node::setIndex(int index){
    Index =index;
}

void Node::setPoint(int x, int y){
    point.setX(x);
    point.setY(y);
}

void Node::setPoint(QPoint poi){
    point = poi;
}

QString Node::getName(){
    return Name;
}

