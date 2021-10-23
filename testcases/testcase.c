#include<stdio.h>
#include<stdlib.h>
#include<tmsort.h>

//we can use the sorting algoriths like this. you just need to provide a comparator function.
//In comparator function set a return type based on data type you are comparing for.
//In this example we are sorting integers. Therefore, we are setting int as a return type for intComparator() function.

/*
void bubbleSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error);
void linearSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error);
void selectionSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error);
void insertionSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error);
void quickSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error);
void mergeSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error);
void heapSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error);
void shellSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error);
*/
int initComparator(void *left,void *right)
{
return (*((int *)left))-(*((int *)right));
}
int main()
{
int *x,y,req,lb,ub;
int isSuccessful,errorNumber;
printf("Enter Requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Inavalid Requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
lb=0;
ub=req-1;
mergeSort((void *)x,initComparator,sizeof(int),lb,ub,&isSuccessful,&errorNumber);
for(y=0;y<req;y++)     printf("%d\n",x[y]);
return 0;
}

//For compiling i have provided a batch file named as cmp.bat
//Just type cmp in testcases folder in command prompt