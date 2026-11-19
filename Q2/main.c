#include <stdio.h>
#include <string.h>
typedef struct { long comparisons, moves; } Stats;
static void bubble(int a[], int n, Stats *s) {
    for(int end=n-1;end>0;--end){int changed=0;for(int j=0;j<end;++j){++s->comparisons;if(a[j]>a[j+1]){int t=a[j];a[j]=a[j+1];a[j+1]=t;s->moves+=3;changed=1;}}if(!changed)break;}
}
static void selection(int a[], int n, Stats *s) {
    for(int i=0;i<n-1;++i){int m=i;for(int j=i+1;j<n;++j){++s->comparisons;if(a[j]<a[m])m=j;}if(m!=i){int t=a[i];a[i]=a[m];a[m]=t;s->moves+=3;}}
}
static void insertion(int a[], int n, Stats *s) {
    for(int i=1;i<n;++i){int key=a[i],j=i-1;while(j>=0){++s->comparisons;if(a[j]<=key)break;a[j+1]=a[j];++s->moves;--j;}a[j+1]=key;++s->moves;}
}
static void run(const char *name,const int src[],int n,void(*sorter)(int*,int,Stats*)){
    int a[32];memcpy(a,src,(size_t)n*sizeof(int));Stats s={0,0};sorter(a,n,&s);
    printf("%-10s comparisons=%ld moves=%ld result:",name,s.comparisons,s.moves);
    for(int i=0;i<n;++i)printf(" %d",a[i]);puts("");
}
int main(void){
    int sorted[]={1,2,3,4,5,6},near[]={1,2,4,3,5,6},reverse[]={6,5,4,3,2,1},random[]={4,1,6,2,5,3};
    const int *data[]={sorted,near,reverse,random};const char *labels[]={"sorted","nearly","reverse","random"};
    for(int k=0;k<4;++k){printf("\n%s input\n",labels[k]);run("bubble",data[k],6,bubble);run("selection",data[k],6,selection);run("insertion",data[k],6,insertion);}
    return 0;
}