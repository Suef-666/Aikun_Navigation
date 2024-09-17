#ifndef SOLVE_H
#define SOLVE_H
#include <QDate>
#include <QTime>
#include <QList>
#include "edge.h"
#include "solvegraph.h"

class Solve{

public:
   Solve();
   Solve(int u,int v,int model);
   Solve(int u,int v,int model,QDate DateNow,QTime Timenow);
   void set(int u,int v,int model);
   void set(int u,int v,int model,QDate mdate,QTime mtime);
   void updateGraph(SolveGraph *T);
   int distance(SolveGraph *G);
   int time(SolveGraph *G);
   int waiting_subway();
   int waiting_weekdayK();
   int waiting_weekdayD();
   int waiting_weekendK();
   int waiting_weekendD();
   void Route(SolveGraph *G);
   void dijkstra(int s,SolveGraph *G);
   int tran(int h,int m);

   int getCount();
   int* getRoute();
   int getWaitTime();
   bool getWay();

private:
   int u,v,model;
   int track[105],dis[105],vis[105],tr[105];
   QDate mdate;
   QTime mtime;

   int cnt = 0 ;
   int line[105];
   int waitTime = 0;
   bool way;
};

#endif // SOLVE_H
