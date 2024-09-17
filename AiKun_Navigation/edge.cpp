#include "edge.h"

Edge::Edge(){

    start = 0;
    end = 0;
    distance = 0;
}

Edge::Edge(int _start ,int _end ,int _distance){

    start = _start;
    end = _end;
    distance = _distance;
}

Edge::~Edge(){
    return ;
}

int Edge::getStart(){
    return start;
}

int Edge::getEnd(){
    return end;
}

int Edge::getDistance(){
    return distance;
}

void Edge::setStart(int _start){
    start = _start;
}

void Edge::setEnd(int _end){
    end = _end;
}

void Edge::setDistance(int _distance){
    distance = _distance;
}
