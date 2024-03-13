#include <bits/stdc++.h>
using namespace std;
int n,m;

bool isused[10];
int arr[10];

void solve(int t, int bef){
    if(t==m){
        for (int i = 0; i < m; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if(!isused[i]){
            if(bef>i) continue;
            arr[t]=i;
            isused[i]=1;
            solve(t+1,i);
            isused[i]=0;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    solve(0,0);
}