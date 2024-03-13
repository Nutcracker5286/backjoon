#include<bits/stdc++.h>
using namespace std;

bool isused_1[100];
bool isused_2[100];
bool isused_3[100];
int n;
int cnt;

void solve(int t){
    if(t==n){
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(isused_1[i]||isused_2[i+t]||isused_3[t-i+n-1])
        continue;
        isused_1[i]=1;
        isused_2[i+t]=1;
        isused_3[t-i+n-1]=1;
        solve(t+1);
        isused_1[i]=0;
        isused_2[i+t]=0;
        isused_3[t-i+n-1]=0;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    solve(0);
    cout<<cnt;
}