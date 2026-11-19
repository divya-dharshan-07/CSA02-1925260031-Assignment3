#include <stdio.h>
#define R 3
#define C 4
static void analyse(const double rain[R][C]){
    double row[R]={0},col[C]={0},sum=0,max=-1;int mr=0,mc=0;
    for(int i=0;i<R;++i)for(int j=0;j<C;++j){double v=rain[i][j];row[i]+=v;col[j]+=v;sum+=v;if(v>max){max=v;mr=i;mc=j;}}
    double avg=sum/(R*C);
    printf("State average: %.2f mm\nWettest: district %d, month %d = %.1f mm\n",avg,mr+1,mc+1,max);
    for(int i=0;i<R;++i)printf("District %d annual total: %.1f mm%s\n",i+1,row[i],row[i]<0.6*avg?" DEFICIENT":"");
    for(int j=0;j<C;++j)printf("Month %d average: %.2f mm\n",j+1,col[j]/R);
}
int main(void){
    const double rain[R][C]={{80,45,60,90},{30,40,35,50},{100,120,110,95}};
    analyse(rain);
    printf("Row-major offset rain[2][3] = %d elements from rain[0][0]\n",2*C+3);
    return 0;
}