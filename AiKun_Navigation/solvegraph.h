#ifndef SOLVEGRAPH_H
#define SOLVEGRAPH_H
#include <QList>
#include "edge.h"

class SolveGraph{
public:
    SolveGraph(QList<Edge*> l,int num);
    int num,g[60][60];
    ~SolveGraph();

};

#endif // SOLVEGRAPH_H
