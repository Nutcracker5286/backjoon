#include <bits/stdc++.h>
using namespace std;

int isRot[4];
int wh[5][10];

int ans;

bool isRotate(int num, int dir){
    fill(isRot,isRot+4,0);
    switch(num){
        case 0:
        if(wh[0][2]==wh[1][2]){ // 0번만 회전
            isRot[0]=dir;
        }
        else{
            if(wh[1][2]==wh[2][6]){ // 0,1 회전
                isRot[0]=dir;
                isRot[1]=-dir;
            }
            else{
            if(wh[2][2]==wh[3][6]){//0,1,2 회전
                isRot[0]=isRot[2]=dir;
                isRot[1]=-dir;
            }
            else{
                isRot[0]=isRot[2]=dir;
                isRot[1]=isRot[3]=-dir;
            }
            }
        }
        break;

        case 1:
        if(wh[0][2]==wh[1][2] && wh[1][6]==wh[2][6]) // 1번만 회전
            {isRot[1]=dir;}
        else if(wh[0][2]!=wh[1][2] && wh[1][6]==wh[2][6]) // 0,1 회전
            {   isRot[1]=dir;
                isRot[0]=-dir;}
        else{
            if(wh[2][2]==wh[3][6]) // 0,1,2 회전
                {   isRot[1]=dir;
                    isRot[0]=isRot[2]=-dir;
                }
            else{
                    isRot[1]=isRot[3]=dir;
                    isRot[0]=isRot[2]=-dir;
            }
        }
        break;

        case 2:
        if(wh[1][2]==wh[2][6] && wh[2][2]==wh[3][6]) // 2번만 회전
            isRot[2]=dir;
        else if(wh[2][2]!=wh[3][6] && wh[2][6]==wh[1][2]) // 2,3 회전
            {isRot[2]=dir; isRot[3]=-dir;}
        else{
            if(wh[0][2]==wh[1][6]) // 1,2,3 회전
                {isRot[1]=isRot[3]=-dir; isRot[2]= dir;}
            else{
                isRot[1]=isRot[3]=-dir;
                isRot[0]=isRot[2]=dir;
        }
        }

        break;

        case 3:
        if(wh[2][2]==wh[3][6]){ // 3번만 회전
            isRot[3]=dir;
        }
        else{
            if(wh[1][2]==wh[2][6]){ // 2,3 회전
                isRot[2]=-dir; isRot[3]=dir;
            }
            else{
            if(wh[0][2]==wh[1][6]){//1,2,3 회전
                isRot[1]=isRot[3]=dir; isRot[2]=-dir;
            }
            else {
                isRot[1]=isRot[3]=dir;
                isRot[0]=isRot[2]=-dir;
        }
            }
        }

        break;
    }
}

void rotate(){
    for(int i=0; i<4; i++){
        if(isRot[i]!=0){ // 회전 가능 하면
            
            if(isRot[i]==1){ //시계 방향
                stack<int> st;
                for(int j=0; j<8; j++)
                st.push(wh[i][j]);
                int idx=0;
                while(!st.empty()) {wh[i][idx++]=st.top(); st.pop();}
            }
            else{// 반시계
                queue<int> q;
                for(int j=0; j<8; j++)
                q.push(wh[i][j]);
                int idx=0; int tmp= q.front(); q.pop();
                while(!q.empty()){wh[i][idx++]=q.front(); q.pop();}
                wh[i][7]=tmp; 
            }

        }
    }
}


void compute(){
    int score[4];
    for(int i=0; i<4; i++){
        if(wh[i][0]) score[i]=0;
        else{
            score[i]=1<<i;
        }
        ans+=score[i];
    }
}

int main(){
    ios::sync_with_stdio(0);

    cin.tie(0);

    for(int i=0; i<4; i++)
        for(int j=0; j<8; j++)
            cin>>wh[i][j];
    
    int k;
    cin>>k;

    while(k--){
        int n, dir;
        cin>>n>>dir;
        if(isRotate(n,dir));
            rotate();
    }
    compute();
    cout<<ans;
}