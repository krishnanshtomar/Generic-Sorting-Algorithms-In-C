#include<tmsort.h>
#include<string.h>
#include<stdlib.h>


void bubbleSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error)
{
int e,f,m;
void *a,*b,*c;
if(es==0)
{
*error=ELEM_SIZE_ZERO;
return;
}
if(successful)    *successful=FAILED;
if(error)     *error=NO_ERROR;
c=(void *)malloc(sizeof(es));
if(c==NULL)
{
*error=MEM_ALLOC_ERROR;
return;
}
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=x+(f*es);
b=x+(e*es);
if(p2f(a,b)<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
e++;
f++;
}
m--;
}
free(c);
if(successful)     *successful=SUCCESSFUL;
}


void linearSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error)
{
int e,f,g,ub1,ub2;
void *a,*b,*c;
if(es==0)
{
*error=ELEM_SIZE_ZERO;
return;
}
if(successful)    *successful=FAILED;
if(error)     *error=NO_ERROR;
c=(void *)malloc(es);
if(c==NULL)
{
*error=MEM_ALLOC_ERROR;
return;
}
ub1=cs-2;
ub2=cs-1;
e=0;
while(e<=ub1)
{
f=e+1;
while(f<=ub2)
{
a=x+(f*es);
b=x+(e*es);
if((p2f(a,b))<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
f++;
}
e++;
}
free(c);
if(successful)     *successful=SUCCESSFUL;
}


void selectionSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error)
{
int e,f,si,ub1,ub2;
void *a,*b,*c;
if(es==0)
{
*error=ELEM_SIZE_ZERO;
return;
}
if(successful)    *successful=FAILED;
if(error)     *error=NO_ERROR;
c=(void *)malloc(es);
if(c==NULL)
{
*error=MEM_ALLOC_ERROR;
return;
}
ub1=cs-2;
ub2=cs-1;
e=0;
while(e<=ub1)
{
si=e;
f=e+1;
while(f<=ub2)
{
a=x+(f*es);
b=x+(si*es);
if((p2f(a,b))<0 )
{
si=f;
}
f++;
}
a=x+(e*es);
b=x+(si*es);
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
e++;
}
free(c);
if(successful)     *successful=SUCCESSFUL;
}


void insertionSort(void *x,int es,int cs,int (*p2f)(void *,void *),int *successful,int *error)
{
int y,z,ep;
void *block;
ep=cs-1;
block=(void *)malloc(es);
y=1;
while(y<=ep)
{
memcpy(block,(void *)(x+(y*es)),es);
z=y-1;
while(z>=0 && p2f(x+(z*es),block)>0)
{
memcpy(x+((z+1)*es),(const void *)(x+(z*es)),es);
z--;
}
//x[z+1]=num;
memcpy(x+((z+1)*es),(const void *)block,es);
y++;
}
free(block);
}


void quickSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error)
{
struct LBUB
{
int lb,ub;
};
int isSuccessful,errorNumber;
struct LBUB lbub;
Stack stack;
int pp;
if(successful)    *successful=FAILED;
if(error)     *error=NO_ERROR;
initStack(&stack,sizeof(struct LBUB),&isSuccessful,&errorNumber);
lbub.lb=lowerbound;
lbub.ub=upperbound;
push(&stack,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack,&isSuccessful,&errorNumber);
return;
}
while(!isEmpty(&stack,&isSuccessful,&errorNumber))
{
pop(&stack,(void *)&lbub,&isSuccessful,&errorNumber);
//No Verification Required
lowerbound=lbub.lb;
upperbound=lbub.ub;
pp=partitionPoint(x,p2f,es,lowerbound,upperbound,&isSuccessful,&errorNumber);
if(pp+1<upperbound)
{
lbub.lb=pp+1;
lbub.ub=upperbound;
push(&stack,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack,&isSuccessful,&errorNumber);
return;
}
}
if(lowerbound<pp-1)
{
lbub.lb=lowerbound;
lbub.ub=pp-1;
push(&stack,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack,&isSuccessful,&errorNumber);
return;
}
}
}
}


void mergeSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error)
{
struct LBUB
{
int lb,ub;
};
int isSuccessful,errorNumber;
struct LBUB lbub;
int a,b;
Stack stack1;
Stack stack2;
int mid;
if(successful)    *successful=FAILED;
if(error)     *error=NO_ERROR;
initStack(&stack1,sizeof(struct LBUB),&isSuccessful,&errorNumber);
initStack(&stack2,sizeof(struct LBUB),&isSuccessful,&errorNumber);
lbub.lb=lowerbound;
lbub.ub=upperbound;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
while(!isEmpty(&stack1,&isSuccessful,&errorNumber))
{
pop(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
//No Verification Required
push(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
}
while(!isEmpty(&stack2,&isSuccessful,&errorNumber))
{
pop(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
merge(x,p2f,es,a,mid,mid+1,b,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
if(successful)     *successful=SUCCESSFUL;
}


void heapSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error)
{
int y,ri,lci,rci,swi;
int isSuccessful,errorNumber;
void *g;
if(es==0)
{
*error=ELEM_SIZE_ZERO;
return;
}
if(successful)    *successful=FAILED;
if(error)     *error=NO_ERROR;
maxHeap(x,p2f,es,lowerbound,upperbound,&isSuccessful,&errorNumber);
g=(void *)malloc(es);
if(g==NULL)
{
*error=MEM_ALLOC_ERROR;
return;
}
y=upperbound;
while(y>0)
{
memcpy(g,(const void *)(x+(lowerbound*es)),es);
memcpy(x+(lowerbound*es),(const void *)(x+(y*es)),es);
memcpy(x+(y*es),(const void *)g,es);
y--;
ri=0;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y)    break;
rci=lci+1;
if(rci>y)
{
swi=lci;
}
else
{
if(p2f(x+(lci*es),x+(rci*es))>0)    swi=lci;
else    swi=rci;
}
if(p2f(x+(swi*es),x+(ri*es))>0)
{
memcpy(g,(const void *)(x+(ri*es)),es);
memcpy(x+(ri*es),(const void *)(x+(swi*es)),es);
memcpy(x+(swi*es),(const void *)g,es);
ri=swi;
}
else
{
break;
}
}
}
free(g);
if(successful)     *successful=SUCCESSFUL;
}


void shellSort(void *x,int (*p2f)(void *,void *),int es,int lowerbound,int upperbound,int *successful,int *error)
{
int y,z,size,diff;
void *g;
if(es==0)
{
*error=ELEM_SIZE_ZERO;
return;
}
if(successful)    *successful=FAILED;
if(error)     *error=NO_ERROR;
g=(void *)malloc(es);
if(g==NULL)
{
*error=MEM_ALLOC_ERROR;
return;
}
size=(upperbound-lowerbound)+1;
diff=size/2;
while(diff>=1)
{
y=lowerbound+diff;
while(y<=upperbound)
{
z=y-diff;
memcpy(g,(void *)x+(y*es),es);
while(z>=0 && p2f(x+(z*es),g)>0)
{
memcpy(x+((z+diff)*es),(const void *)(x+(z*es)),es);
z=z-diff;
}
memcpy(x+((z+diff)*es),(const void *)g,es);
y=y+diff;
}
diff=diff/2;
}
free(g);
if(successful)     *successful=SUCCESSFUL;
}