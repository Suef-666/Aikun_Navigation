#ifndef NODE_H
#define NODE_H

#include <QPoint>
#include <QString>

class Node
{
public:
    Node(int x,int y,int index);
    Node(int x,int y,int index,QString name);
    Node(int index,QString name);
    ~Node();
    QPoint poi();
    int getIndex();
    bool isReal();
    void setReal(bool really);
    void setPoint(int x,int y);
    void setPoint(QPoint poi);
    void setIndex(int index);
    QString getName();

private:
    QPoint point;
    QString Name;
    int Index;
    bool real;

};

#endif // NODE_H
