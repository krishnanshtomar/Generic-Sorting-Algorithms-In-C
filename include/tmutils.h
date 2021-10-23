#ifndef __tmutils__
#define __tmutils__ 234
#include<tmconst.h>
#include<tmerr.h>
int partitionPoint(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void merge(void *x,int (*p2f)(void *,void *),int es,int lb1,int ub1,int lb2,int ub2,int *successful,int *error);
void maxHeap(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void minHeap(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
#endif