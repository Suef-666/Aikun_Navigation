#ifndef EDGE_H
#define EDGE_H


class Edge
{
public:
    Edge(int ,int ,int );
    Edge();
    ~Edge();
    int getStart();
    int getEnd();
    int getDistance();
    void setStart(int _start);
    void setEnd(int _end);
    void setDistance(int _distance);

private:
    int start;
    int end;
    int distance;
};

#endif // EDGE_H
