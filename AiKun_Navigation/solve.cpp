#include "solve.h"
#include "edge.h"
#include "node.h"
#include <QList>

//Solve类构造函数，函数重载对应津南校区和校区间两种情况
Solve::Solve(){

    this->u = this->v = 0;
    this->model = 3;
}

Solve::Solve(int u,int v,int model){

    this->u=u;
    this->v=v;
    this->model=model;
}

Solve::Solve(int u,int v,int model,QDate DateNow,QTime Timenow){

    this->u=u,this->v=v,this->model=model;
    this->mdate=DateNow,this->mtime=Timenow;
}

void Solve::set(int u,int v,int model){

    this->u=u;
    this->v=v;
    this->model = model;
}

void Solve::set(int u, int v, int model, QDate mdate, QTime mtime){

    this->u = u;
    this->v = v;
    this->model = model;
    this->mdate = mdate;
    this->mtime = mtime;
}

//根据出发时刻对应等待时间更新分层图T
void Solve::updateGraph(SolveGraph *T){

    if(mdate.dayOfWeek()>=1&&mdate.dayOfWeek()<=5){
        T->g[1][2]=T->g[2][1]=waiting_weekdayK();
        T->g[1][3]=T->g[3][1]=waiting_weekdayD();
    }
    else{
        T->g[1][2]=T->g[2][1]=waiting_weekendK();
        T->g[1][3]=T->g[3][1]=waiting_weekendD();
    }

    T->g[1][4]=T->g[4][1]=waiting_subway();
    if(mdate.year()==2023)T->g[9][13]=T->g[13][9]=8;
}

//求解通行最短距离或时间
int Solve::distance(SolveGraph *G){

   if(model!=0)return -1;

   dijkstra(u,G);

   return dis[v];
}

int Solve::time(SolveGraph *T){

    if(model!=1)return -1;

    updateGraph(T);

    dijkstra(u,T);

    return dis[v];
}

//计算各交通工具等待时间
int Solve::waiting_subway(){

    int h=mtime.hour(),m=mtime.minute();
    int rm=tran(h,m)+5;

    if(rm<=tran(6,10))return tran(6,10)-rm;
    if(rm>tran(22,44))return tran(6,10)+1440-rm;

    return (rm-tran(6,10))%7;
}

int Solve::waiting_weekdayK(){

    int h=mtime.hour(),m=mtime.minute();
    int rm=tran(h,m);

    if(h<=5){
        return tran(6,30)-rm;
    }
    if(h==6){
        if(m<=30)return tran(6,30)-rm;
        if(m>30&&m<=35)return tran(6,35)-rm;
        if(m>35&&m<=40)return tran(6,40)-rm;
        if(m>40&&m<=50)return tran(6,50)-rm;
        return tran(7,10)-rm;
    }
    if(h==7){
        if(m<=10)return tran(7,10)-rm;
        if(m>10&&m<=40)return tran(7,40)-rm;
        return tran(8,0)-rm;
    }
    if(h==8){
        if(m==0)return tran(8,0)-rm;
        if(m>0&&m<=30)return tran(8,30)-rm;
        return tran(9,0)-rm;
    }
    if(h==9){
        if(m==0)return tran(9,0)-rm;
        if(m>0&&m<=40)return tran(9,40)-rm;
        return tran(10,10)-rm;
    }
    if(h==10){
        if(m<=10)return tran(10,10)-rm;
        if(m>10&&m<=30)return tran(10,30)-rm;
        return tran(11,0)-rm;
    }
    if(h==11){
        if(m==0)return tran(11,0)-rm;
        if(m>0&&m<=30)return tran(11,30)-rm;
        return tran(12,0)-rm;
    }
    if(h==12){
        if(m==0)return tran(12,0)-rm;
        return tran(13,0)-rm;
    }
    if(h==13){
        if(m==0)return tran(13,0)-rm;
        if(m>0&&m<=30)return tran(13,30)-rm;
        return tran(14,0)-rm;
    }
    if(h==14){
        if(m==0)return tran(14,0)-rm;
        if(m>0&&m<=30)return tran(14,30)-rm;
        if(m>30&&m<=50)return tran(14,50)-rm;
        return tran(15,10)-rm;
    }
    if(h==15){
        if(m<=10)return tran(15,10)-rm;
        if(m>10&&m<=30)return tran(15,30)-rm;
        return tran(17,50)-rm;
    }
    if(h==16)return tran(17,50)-rm;
    if(h==17){
        if(m<=50)return tran(17,50)-rm;
        return tran(18,10)-rm;
    }
    if(h==18){
        if(m<=10)return tran(18,10)-rm;
        if(m>10&&m<=50)return tran(18,50)-rm;
        return tran(19,10)-rm;
    }
    if(h==19){
        if(m<=10)return tran(19,10)-rm;
        if(m>10&&m<=50)return tran(19,50)-rm;
        return tran(20,10)-rm;
    }
    if(h==20){
        if(m<=10)return tran(20,10)-rm;
        return tran(6,30)+1440-rm;
    }

    return tran(6,30)+1440-rm;
}

int Solve::waiting_weekdayD(){
    int h=mtime.hour(),m=mtime.minute();
    int rm=tran(h,m);

    if(h<=5){
        return tran(6,30)-rm;
    }
    if(h==6){
        if(m<=30)return tran(6,30)-rm;
        if(m>30&&m<=40)return tran(6,40)-rm;
        if(m>40&&m<=50)return tran(6,50)-rm;
        return tran(7,10)-rm;
    }
    if(h==7){
        if(m<=10)return tran(7,10)-rm;
        if(m>10&&m<=20)return tran(7,20)-rm;
        if(m>20&&m<=30)return tran(7,30)-rm;
        if(m>30&&m<=40)return tran(7,40)-rm;
        if(m>40&&m<=50)return tran(7,50)-rm;
        if(m>50&&m<=55)return tran(7,55)-rm;
        return tran(8,0)-rm;
    }
    if(h==8){
        if(m==0)return tran(8,0)-rm;
        if(m>0&&m<=10)return tran(8,10)-rm;
        if(m>10&&m<=30)return tran(8,30)-rm;
        return tran(10,30)-rm;
    }
    if(h==9)return tran(10,30)-rm;
    if(h==10){
        if(m<=30)return tran(10,30)-rm;
        return tran(12,30)-rm;
    }
    if(h==11)return tran(12,30)-rm;
    if(h==12){
        if(m<=30)return tran(12,30)-rm;
        return tran(14,30)-rm;
    }
    if(h==13)return tran(14,30)-rm;
    if(h==14){
        if(m<=30)return tran(14,30)-rm;
        return tran(16,30)-rm;
    }
    if(h==15)return tran(16,30)-rm;
    if(h==16){
        if(m<=30)return tran(16,30)-rm;
        return tran(21,15)-rm;
    }
    if(h>=17&&h<=20)return tran(21,15)-rm;
    if(h==21){
        if(m<=15)return tran(21,15)-rm;
        return tran(6,30)+1440-rm;
    }
    return tran(6,30)+1440-rm;
}

int Solve::waiting_weekendK(){

    int h=mtime.hour(),m=mtime.minute();
    int rm=tran(h,m);

    if(rm<=tran(6,30))return tran(6,30)-rm;
    if(rm<=tran(21,15))return 10;

    return tran(6,30)+1440-rm;
}

int Solve::waiting_weekendD(){

    int h=mtime.hour(),m=mtime.minute();
    int rm=tran(h,m);

    if(h<8)return tran(8,0)-rm;
    if(h==8){
        if(m==0)return tran(8,0)-rm;
        return tran(12,30)-rm;
    }
    if(h>=9&&h<=11)return tran(12,30)-rm;
    if(h==12){
        if(m<=30)return tran(12,30)-rm;
        return tran(18,30)-rm;
    }
    if(h>=13&&h<=17)return tran(18,30)-rm;
    if(h==18){
        if(m<=30)return tran(18,30)-rm;
        return tran(21,15)-rm;
    }
    if(rm<=tran(21,15))return tran(21,15)-rm;

    return tran(8,0)+1440-rm;
}

//求解最短路径
void Solve::Route(SolveGraph *G){

    for(int i=1;i<=50;i++)tr[i]=0;
    for(int i=1;i<=50;i++)track[i]=0;
    for(int i=1;i<=50;i++)line[i]=0;

    cnt=0;
    if(model == 0){
        dijkstra(u,G);
        int pos=v;
        track[cnt++]=v;
        while(pos!=u){
            track[cnt++]=tr[pos];
            pos=tr[pos];
        }
        for(int i=0;i<cnt;i++){
            line[i]=track[cnt-1-i];
        }
    }

    else if(model == 1){
        updateGraph(G);
        dijkstra(u,G);
        int pos=v;
        track[cnt++]=v;
        while(pos!=u){
            track[cnt++]=tr[pos];
            pos=tr[pos];
        }
        for(int i=0;i<cnt;i++){
            line[i]=track[cnt-1-i];
        }
        if(line[1]==2){
            if(mdate.dayOfWeek()>=1&&mdate.dayOfWeek()<=5){
                waitTime=waiting_weekdayK();
            }
            else waitTime=waiting_weekendK();
            way=1;
        }
        if(line[1]==3){
            if(mdate.dayOfWeek()>=1&&mdate.dayOfWeek()<=5){
                waitTime=waiting_weekdayD();
            }
            else waitTime=waiting_weekendD();
            way=1;
        }
        if(line[1]!=2&&line[1]!=3){
            waitTime=waiting_subway();
            way=0;
        }
    }
}

void Solve::dijkstra(int s,SolveGraph *G){

    //使用dijkstra算法求图G中的单源最短路径
    if(model == 0){
        int n=G->num;
        for(int i=1;i<=100;i++)dis[i]=1e4;
        for(int i=1;i<=100;i++)vis[i]=0;
        for(int i=1;i<=100;i++)tr[i]=0;
        dis[s]=0,tr[s]=s;
        for(int i=1;i<=n;i++){
            int nowdis=1e4,nowpos=0;
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    if(dis[j]<nowdis){
                        nowdis=dis[j];
                        nowpos=j;
                    }
                }
            }
            vis[nowpos]=1;
            for(int j=1;j<=n;j++){
                if(j==nowpos||G->g[nowpos][j]>=1e4)continue;
                if(nowdis+G->g[nowpos][j]<dis[j]){
                    dis[j]=nowdis+G->g[nowpos][j];
                    tr[j]=nowpos;
                }
            }
        }
    }

    //使用dijkstra算法求图T中的单源最短路径
    else if(model == 1){
        int n=G->num;
        for(int i=1;i<=100;i++)dis[i]=1e4;
        for(int i=1;i<=100;i++)vis[i]=0;
        for(int i=1;i<=100;i++)tr[i]=0;
        dis[s]=0,tr[s]=s;
        for(int i=1;i<=n;i++){
            int nowdis=1e4,nowpos=0;
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    if(dis[j]<nowdis){
                        nowdis=dis[j];
                        nowpos=j;
                    }
                }
            }
            vis[nowpos]=1;
            for(int j=1;j<=n;j++){
                if(j==nowpos||G->g[nowpos][j]>=1e4)continue;
                if(nowdis+G->g[nowpos][j]<dis[j]){
                    dis[j]=nowdis+G->g[nowpos][j];
                    tr[j]=nowpos;
                }
            }
        }
    }
}

int Solve::tran(int h,int m){
    return 60*h+m;
}

int Solve::getCount(){
    return cnt;
}

int* Solve::getRoute(){
    return line;
}

int Solve::getWaitTime(){
    return waitTime;
}

bool Solve::getWay(){
    return way;
}
