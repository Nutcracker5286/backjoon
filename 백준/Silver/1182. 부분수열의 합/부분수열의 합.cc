#include <bits/stdc++.h>
using namespace std;

int n,s,cnt;
int arr[21];

void solve(int k, int sum){
    if(k==n){
        if(sum==s)
            cnt++;
        return ;
    }
    solve(k+1,sum);
    solve(k+1,sum+arr[k]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    solve(0,0);
    if(s==0) cnt--;
    cout<<cnt;

    }