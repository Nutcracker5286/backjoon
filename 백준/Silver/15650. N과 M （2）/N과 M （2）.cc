#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[9];
bool isUsed[9];

void solve(int k, int prev){
    if(k==m){
        for(int i=0; i<m; i++)
                cout<<arr[i]<<' ';
        cout<<'\n';
    }

    for(int i=1; i<=n; i++){
        if(!isUsed[i] && i>prev){
            isUsed[i]=1;
            arr[k]=i;
            solve(k+1, i);
            isUsed[i]=0;

        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    solve(0,0);
}
