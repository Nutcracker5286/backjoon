#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    stack<int> s;
    cin>>k;
    while (k--)
    {
        int t;
        cin>>t;

        if(t==0){
            s.pop();
        }
        else{
            s.push(t);
        }
    }
    int total=0;
    while (!s.empty())
    {
        total+=s.top();
        s.pop();
    }
    cout<<total;
    
}