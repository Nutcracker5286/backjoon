#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
int num[10]={100001};
bool isUsed[10];

void solve(int k){
    if(k==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<" ";
        cout<<'\n';
        return ;
    }
    for(int i=0; i<n; i++){
        if(isUsed[i])
            continue;
        isUsed[i]=1;
        arr[k]=num[i];
        solve(k+1);
        isUsed[i]=0;
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for (int  i = 0; i < n; i++)
        cin>>num[i];

    sort(num,num+n);

    solve(0);    
}