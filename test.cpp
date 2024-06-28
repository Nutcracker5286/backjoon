#include<bits/stdc++.h>
using namespace std;

// n극 0, s극 1
int cog[4][8];

//dir=1 시계 -1 반시계
int k, numb, dir; 

/*
1번은 2
2번은 6,2
3번은 6,2
4번은  ,6
*/
void rotate(int cog_num, int cog_dir){
    if(cog_dir==1){
        // 시계방향 0 1, 1 2, 2 3 ...
        int tmp[8]={};
        for (int i = 0; i < 8; i++)
            tmp[i]=cog[cog_num][i];
        for (int i = 0; i < 8; i++)
        {
            int idx=(i+1)%8;
            cog[cog_num][idx]=tmp[i];
        }
    }
    else{
        // 반시계방향 0 7, 1 0, 2 1 ...
        int tmp[8]={};
        for (int i = 0; i < 8; i++)
            tmp[i]=cog[cog_num][i];
        for (int i = 0; i < 8; i++)
        {
            int idx=(i+7)%8;
            cog[cog_num][idx]=tmp[i];
        }

    }
}


int main(){
    unsigned int var1 = 10;
    unsigned int var2 = 20;
    unsigned int var3 = 30;
    unsigned int var4;

    var4=var1--(var2+var3);
    
 }
