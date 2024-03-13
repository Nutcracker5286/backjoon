#include <bits/stdc++.h>
using namespace std;


int main(){
    int s,y,n,k;
    int cnt=0;

    cin>>n>>k;

    int stu_m[7]={};
    int stu_w[7]={};

    for (int i = 0; i < n; i++)
    {
        cin>>s>>y;
        // 남자라면
        if(s) stu_m[y]++;
        // 여자라면
        else stu_w[y]++;
    }
    
    for (int i = 1; i < 7; i++)
    {
        cnt=cnt+(stu_m[i]+k-1)/k+(stu_w[i]+k-1)/k;

    }
    cout<<cnt;
}