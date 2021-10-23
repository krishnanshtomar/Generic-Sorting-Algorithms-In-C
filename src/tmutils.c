#include<tmutils.h>
#include<stdlib.h>
#include<string.h>

int partitionPoint(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error)
{
int e,f;
void *g;
if(successful)    *successful=FAILED;
if(error)    *error=NO_ERROR;
if(x==NULL || p2f==NULL)
{
if(error)    *error=NULL_VALUE;
return 0;
}
if(es<=0)
{
if(error)    *error=ELEM_SIZE_ZERO;
return 0;
}
g=(void *)malloc(es);
if(g==NULL)
{
if(error)    *error=MEM_ALLOC_ERROR;
return 0;
}
e=lb;
f=ub;
while(e<f)
{
while(e<ub && p2f(x+(e*es),x+(lb*es))<=0)    e++;
while(p2f(x+(f*es),x+(lb*es))>0)    f--;
if(e<f)
{
memcpy(g,(const void *)(x+(e*es)),es);
memcpy(x+(e*es),(const void *)(x+(f*es)),es);
memcpy(x+(f*es),(const void *)g,es);
}
else
{
memcpy(g,(const void *)(x+(lb*es)),es);
memcpy(x+(lb*es),(const void *)(x+(f*es)),es);
memcpy(x+(f*es),(const void *)g,es);
}
}
free(g);
if(successful)    *successful=SUCCESSFUL;
return f;
}


void merge(void *x,int (*p2f)(void *,void *),int es,int lb1,int ub1,int lb2,int ub2,int *successful,int *error)
{
int size1,size2,size3;
void *tmp;
int i1,i2,i3;
if(successful)    *successful=FAILED;
if(error)    *error=NO_ERROR;
if(x==NULL || p2f==NULL)
{
if(error)    *error=NULL_VALUE;
return;
}
if(es<=0)
{
if(error)    *error=ELEM_SIZE_ZERO;
return;
}
size1=(ub1-lb1)+1;
size2=(ub2-lb2)+1;
size3=size1+size2;
tmp=(void *)malloc(es*size3);
if(tmp==NULL)
{
if(error)    *error=MEM_ALLOC_ERROR;
return;
}
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
if(p2f(x+(i1*es),x+(i2*es))<0)
{
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
}
else
{
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
}
i3++;
}
while(i1<=ub1)
{
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
i3++;
}
while(i2<=ub2)
{
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
memcpy(x+(i1*es),(const void *)(tmp+(i3*es)),es);
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
memcpy(x+(i2*es),(const void *)(tmp+(i3*es)),es);
i2++;
i3++;
}
free(tmp);
if(successful)    *successful=SUCCESSFUL;
}


void maxHeap(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error)
{
int y,ci,ri;
void *g;
if(successful)    *successful=FAILED;
if(error)    *error=NO_ERROR;
if(x==NULL || p2f==NULL)
{
if(error)    *error=NULL_VALUE;
return;
}
if(es<=0)
{
if(error)    *error=ELEM_SIZE_ZERO;
return;
}
g=(void *)malloc(es);
if(g==NULL)
{
if(error)    *error=MEM_ALLOC_ERROR;
return;
}
y=lb+1;
while(y<=ub)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(p2f(x+(ci*es),x+(ri*es))>0)
{
memcpy(g,(const void *)(x+(ri*es)),es);
memcpy(x+(ri*es),(const void *)(x+(ci*es)),es);
memcpy(x+(ci*es),(const void *)g,es);
ci=ri;
}
else
{
break;
}
}
y++;
}
free(g);
if(successful)    *successful=SUCCESSFUL;
}


void minHeap(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error)
{
int y,ci,ri;
void *g;
if(successful)    *successful=FAILED;
if(error)    *error=NO_ERROR;
if(x==NULL || p2f==NULL)
{
if(error)    *error=NULL_VALUE;
return;
}
if(es<=0)
{
if(error)    *error=ELEM_SIZE_ZERO;
return;
}
g=(void *)malloc(es);
if(g==NULL)
{
if(error)    *error=MEM_ALLOC_ERROR;
return;
}
y=lb+1;
while(y<=ub)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(p2f(x+(ci*es),x+(ri*es))<0)
{
memcpy(g,(const void *)(x+(ri*es)),es);
memcpy(x+(ri*es),(const void *)(x+(ci*es)),es);
memcpy(x+(ci*es),(const void *)g,es);
ci=ri;
}
else
{
break;
}
}
y++;
}
free(g);
if(successful)    *successful=SUCCESSFUL;
}