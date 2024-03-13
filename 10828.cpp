#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    int n;
    cin>>n;
    while (n--)
    {
        string a;
        cin>>a;

        if(a=="push"){
            int t;
            cin>>t;
            s.push(t);
        }
        else if(a=="pop"){
            if(s.empty()){
                cout<<-1<<"\n";
            }
            else{
                cout<<s.top()<<"\n";
                s.pop();
            }
        }
        else if(a=="size"){
            cout<<s.size()<<"\n";
        }
        else if(a=="empty"){
            if(s.empty()){
                cout<<1<<"\n";
            }
            else cout<<0<<"\n";
        }
        else{
            if(s.empty()){
                cout<<-1<<"\n";
            }
            else
                cout<<s.top()<<"\n";
        }
    }
    
}