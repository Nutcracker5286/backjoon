#include<bits/stdc++.h>
using namespace std;

int c;
void solve(int a, int b ,int n){
    if(n==0)
        return ;
    solve(a,6-a-b,n-1);
    cout<<a<<" "<<b<<"\n";
    solve(6-a-b,b,n-1);
}

void solve2(int a, int b ,int n){
    c++;
    if(n==0)
        return ;
    solve2(a,6-a-b,n-1);
    // cout<<a<<" "<<b<<"\n";
    solve2(6-a-b,b,n-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    solve2(1,3,n);
    cout<<(c-1)/2<<"\n";
    solve(1,3,n);
}