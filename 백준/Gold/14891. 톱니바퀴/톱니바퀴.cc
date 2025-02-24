#include <bits/stdc++.h>
using namespace std;

int isRot[4];
int wh[5][10];

int ans;

void isRotate(int num, int dir) {
  fill(isRot, isRot+4, 0);
  isRot[num] = dir;
  
  // 왼쪽으로 전파
  for(int i = num; i > 0; i--) {
      if(wh[i][6] != wh[i-1][2]) {
          isRot[i-1] = -isRot[i];
      } else {
          break;
      }
  }
  
  // 오른쪽으로 전파
  for(int i = num; i < 3; i++) {
      if(wh[i][2] != wh[i+1][6]) {
          isRot[i+1] = -isRot[i];
      } else {
          break;
      }
  }
}

void rotate(){
    for(int i=0; i<4; i++){
        if(isRot[i]==1){ // 시계
          int tmp = wh[i][7];
          for(int j=7; j>0; j--)
            wh[i][j]=wh[i][j-1];
          wh[i][0]= tmp;
        }
        else if(isRot[i]==-1){
          int tmp = wh[i][0];
          for(int j=0; j<7; j++)
          wh[i][j]=wh[i][j+1];
          wh[i][7]=tmp;
        }
    }
}


void compute(){
    int score[4]={0};
    for(int i=0; i<4; i++){
        if(!wh[i][0]) score[i]=0;
        else{
            score[i]=1<<i;
        }
        ans+=score[i];
    }
}

int main(){
    ios::sync_with_stdio(0);

    cin.tie(0);

    string s[4];
    for(int i=0; i<4; i++)
    cin>>s[i];

    for(int i=0; i<4; i++)
        for(int j=0; j<8; j++)
            wh[i][j]=s[i][j]=='0'?0:1;
    
    int k;

    cin>>k;

    while(k--){
        int n, dir;
        cin>>n>>dir;
        isRotate(n-1,dir);
        rotate();
    }
    compute();
    cout<<ans;
}