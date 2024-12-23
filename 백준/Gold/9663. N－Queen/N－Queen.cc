#include<bits/stdc++.h>
using namespace std;

bool isused_1[100];
bool isused_2[100];
bool isused_3[100];
int n;
int cnt;

void solve(int t){
    if(t==n){
        cnt++; return;
    }
    for (int i = 0; i < n; i++)
    {
        if(isused_1[i] || isused_2[t+i] || isused_3[t-i+n-1])
            continue;
        isused_1[i]=true;
        isused_2[t+i]=true;
        isused_3[t-i+n-1]=true;
        solve(t+1);
        isused_1[i]=false;
        isused_2[t+i]=false;
        isused_3[t-i+n-1]=false;
    }
    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    solve(0);
    cout<<cnt;

}