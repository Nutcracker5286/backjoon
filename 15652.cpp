#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
void solve(int t, int bef){
    if(t==m){
        for (int i = 0; i < m; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n'; return;        
    }
    for (int i = 1; i <=n; i++)
    {
        if(bef>i) continue;
        arr[t]=i;
        solve(t+1,i);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    solve(0,0);
}