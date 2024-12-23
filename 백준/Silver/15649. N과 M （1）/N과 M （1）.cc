#include <bits/stdc++.h>
using namespace std;

int m,n;
int arr[10];
bool isUsed[10];

void solve(int k){
    if(k==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return ;
    }

    for (int  i = 1; i <= n; i++)
    {
        if(!isUsed[i]){
            arr[k]=i;
            isUsed[i]=1;
            solve(k+1);
            isUsed[i]=0;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    solve(0);
}