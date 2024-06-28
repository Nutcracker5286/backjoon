#include <bits/stdc++.h>
using namespace std;

/*
다리위에 올라온 트럭 무게 합<= 다리 최대 하중 L
다리위에 올라올 수 있는 트럭 수 w, 트럭 수 n
다리 들어갈때, 다리 나올때 무게 합 계산
한칸씩 움직일때마다 다리 하중 계산
*/
int n, w, L;
int timeLap;
queue<int> truck;
int bridge[105];

int weight(){
    int sum=0;
    for (int i = 0; i < w; i++)
        sum+=bridge[i];
    return sum;    
}

void move(){
    for (int i = 0; i < w; i++)
    {
        bridge[i]=bridge[i+1];
    }
    bridge[w-1]=0;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>w>>L;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        truck.push(a);
    }

    do
    {
       if(weight()<=L){
        move();
        if((weight()+truck.front()<=L)&&!truck.empty()){
            bridge[w-1]=truck.front(); truck.pop();
        }
       }
       timeLap++;
    } while (weight()!=0);
    cout<<timeLap;
    
}
