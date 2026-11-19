#include <stdio.h>
#define MAX_CANDIDATES 12
#define MAX_VOTES 500000
typedef struct {int id;int votes;} Result;
static void sort_results(Result a[],int n){for(int i=1;i<n;++i){Result x=a[i];int j=i-1;while(j>=0&&a[j].votes<x.votes){a[j+1]=a[j];--j;}a[j+1]=x;}}
int main(void){
    int candidates=4;int votes[]={1,2,2,3,0,5,-1,4,4,2,3,1,4,4};int n=(int)(sizeof votes/sizeof votes[0]);
    int count[MAX_CANDIDATES+1]={0},valid=0,invalid=0;
    for(int i=0;i<n;++i){if(votes[i]<1||votes[i]>candidates)++invalid;else{++count[votes[i]];++valid;}}
    Result r[MAX_CANDIDATES];for(int i=0;i<candidates;++i){r[i].id=i+1;r[i].votes=count[i+1];}
    sort_results(r,candidates);printf("Valid votes: %d\nInvalid votes: %d\n",valid,invalid);
    puts("Candidate results (descending):");for(int i=0;i<candidates;++i)printf("Candidate %d: %d\n",r[i].id,r[i].votes);
    if(candidates==0||valid==0){puts("No valid votes; no winner.");return 0;}
    int tied=0;for(int i=1;i<candidates;++i)if(r[i].votes==r[0].votes)tied=1;
    if(tied)printf("Tie for first place with %d votes.\n",r[0].votes);else printf("Winner: Candidate %d with %d votes.\n",r[0].id,r[0].votes);
    return 0;
}