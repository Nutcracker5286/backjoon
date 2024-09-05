#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     
    int n;

    cin>>n;

    while (n--)
    {
        string s;
        stack<char> st;

        cin>>s;

        for(auto c: s){
            if(c==')'){
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    st.push(c);
            }
            else
                st.push(c);
        }

        if(st.empty()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    

}