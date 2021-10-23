#ifndef __tmsort__
#define __tmsort__ 234
#include<tmconst.h>
#include<tmerr.h>
#include<tmstack.h>
#include<tmutils.h>
void bubbleSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error);
void linearSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error);
void selectionSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error);
void insertionSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error);
void quickSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error);
void mergeSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error);
void heapSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error);
void shellSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error);
#endif