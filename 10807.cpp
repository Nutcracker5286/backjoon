#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,v;
    int cnt=0;
    int *a=new int[n];
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cin>>v;

    for (int i = 0; i < n; i++)
    {
        if(a[i]==v) cnt++;
    }
    cout<<cnt;
    
    delete a;
}