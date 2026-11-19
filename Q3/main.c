#include <stdio.h>
#include <stddef.h>
size_t merge_desc(const int a[],size_t na,const int b[],size_t nb,int out[],size_t *comparisons){
    size_t i=0,j=0,k=0;*comparisons=0;
    while(i<na&&j<nb){++*comparisons;if(a[i]>=b[j])out[k++]=a[i++];else out[k++]=b[j++];}
    while(i<na)out[k++]=a[i++];while(j<nb)out[k++]=b[j++];return k;
}
int main(void){
    int a[]={98,91,85,72},b[]={95,91,80},out[7];size_t c,n=merge_desc(a,4,b,3,out,&c);
    for(size_t i=0;i<n;++i)printf("%d ",out[i]);printf("\ncomparisons=%zu\n",c);
    int empty[1],single[]={77},out2[1];n=merge_desc(empty,0,single,1,out2,&c);
    printf("empty-list test: %d (comparisons=%zu)\n",out2[0],c);return 0;
}