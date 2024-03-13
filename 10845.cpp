#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    queue<int> s;
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
            if(!s.empty()){
                cout<<s.front()<<"\n";
                s.pop();
            }
            else{
                cout<<"-1\n";
            }
        }
        else if(a=="size"){
            cout<<s.size()<<"\n";
        }

        else if(a=="empty"){
            if(s.empty()){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }

        else if(a=="front"){
            if(s.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<s.front()<<"\n";
            }
        }
        else if(a=="back"){
            if(s.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<s.back()<<"\n";
            }
            
        }
    }
    


}