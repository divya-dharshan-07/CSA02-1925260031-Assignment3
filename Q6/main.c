#include <stdio.h>
#include <string.h>
#define MAX 500
#define LEN 30
static void strip_newline(char *s){s[strcspn(s,"\\n")]='\\0';}
static void sort_names(char names[][LEN],int n,long *comp,long *copies){for(int i=1;i<n;++i){char key[LEN];strcpy(key,names[i]);*copies+=(long)strlen(key)+1;int j=i-1;while(j>=0){++*comp;if(strcmp(names[j],key)<=0)break;strcpy(names[j+1],names[j]);*copies+=(long)strlen(names[j])+1;--j;}strcpy(names[j+1],key);*copies+=(long)strlen(key)+1;}}
static int binary_find(char names[][LEN],int n,const char *key,long *comp){int lo=0,hi=n-1;*comp=0;while(lo<=hi){int mid=lo+(hi-lo)/2;++*comp;int c=strcmp(names[mid],key);if(c==0)return mid;if(c<0)lo=mid+1;else hi=mid-1;}return -1;}
int main(void){char names[ MAX ][LEN]={"Divya","Arun","Meena","Bala","Meena"};int n=5;long c=0,m=0;sort_names(names,n,&c,&m);printf("Sorted names:\n");for(int i=0;i<n;++i)printf("%s\n",names[i]);printf("sort strcmp calls=%ld character copies=%ld\n",c,m);long sc;int p=binary_find(names,n,"Meena",&sc);printf("Search Meena: index=%d comparisons=%ld\n",p,sc);puts("Duplicates:");for(int i=1;i<n;++i)if(strcmp(names[i-1],names[i])==0)printf("%s\n",names[i]);return 0;}
