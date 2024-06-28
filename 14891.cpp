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


void rotate(int cog_num, int isclock){
    int temp[10]={};
    if(isclock){
        //시계 0 1, 1 2, 7 0
        for (int i = 0; i < 8; i++)
            temp[i]=cog[cog_num][i];
        for (int i = 0; i < 8; i++){
            int idx=(i+1)%8;
            cog[cog_num][idx]=temp[i];
        }
    }
    else{
        //반시계 0 7, 1 0, 2 1
        for (int i = 0; i < 8; i++)
            temp[i]=cog[cog_num][i];
        for (int i = 0; i < 8; i++){
            int idx=(i+7)%8;
            cog[cog_num][idx]=temp[i];
        }
    }
}


void go_rotate(int cog_num, int dir){
    int cog_rot[4]={};
    cog_rot[cog_num]=dir;

    // 왼쪽으로
    int idx=cog_num;
    while (idx>0 && cog[idx-1][2]!=cog[idx][6])
        {cog_rot[idx-1]=-cog_rot[idx]; idx--;}
        
    // 오른쪽으로
    idx=cog_num;
    while (idx<3 && cog[idx+1][6]!=cog[idx][2])
        {cog_rot[idx+1]=-cog_rot[idx]; idx++;}

    for (int i = 0; i < 4; i++)
    {
        if(cog_rot[i]==1)
            rotate(i,true);
        if(cog_rot[i]==-1)
            rotate(i,false);
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string a[4];
    for (int i = 0; i < 4; i++)
        cin>>a[i];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
        cog[i][j]=a[i][j]-'0';                

    cin>>k;
    while (k--)
    {
        cin>>numb>>dir;
        numb--;
        go_rotate(numb,dir);
    }
   
    int ans=cog[0][0]*1+cog[1][0]*2+cog[2][0]*4+cog[3][0]*8;
    cout<<ans;
}