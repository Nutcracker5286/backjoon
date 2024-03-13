#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[100001]={};
    int n,x;
    int cnt=0;
    int count[2000000]={};

    cin>>n;
    for (int i = 0; i < n; i++) cin>>a[i];
    cin>>x;

    for (int i = 0; i < n; i++){
        
        if(count[x-a[i]]==1){cnt++;}
        count[a[i]]=1;
    }
    cout<<cnt;
}