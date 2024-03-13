#include <bits/stdc++.h>
using namespace std;

int arr[23];
int n,s;
int cnt;

void solve(int t, int sum){
    if(t==n){
        if(sum==s)
            cnt++;
        return;
    }
    solve(t+1,sum);
    solve(t+1,sum+arr[t]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>s;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    solve(0,0);
    if(s==0) cnt--;
    cout<<cnt;
}