#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x;
    int num[10]={};

    cin>>a>>b>>c;
    x=a*b*c;

    while (x)
    {
        num[x%10]++;
        x=x/10;
    }
    
    for(auto c:num)
    {
        cout<<c<<"\n";
    }


}