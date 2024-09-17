#include "solvegraph.h"

SolveGraph::SolveGraph(QList<Edge*> l,int num){

    for(int i=1;i<=num;i++)
        for(int j=1;j<=num;j++)
            g[i][j]=1e4;

    int u,v,w;
    for(int i=0;i<l.size();i++){
        u=l.at(i)->getStart(),v=l.at(i)->getEnd(),w=l.at(i)->getDistance();
        g[u][v]=w;
    }
    this->num=num;
}
SolveGraph::~SolveGraph(){

}
