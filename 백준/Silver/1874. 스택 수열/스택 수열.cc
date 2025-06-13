#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    stack<int> st;
    string ans;

    cin>>n;

    int cur =1;
    while (n--)
    {
        int t;
        cin>>t;
        while(cur<=t) {
            st.push(cur++);
            ans+="+\n";
        }
        if(st.top()!=t){
            cout<<"NO\n";
            return 0;
        }
        st.pop();
        ans+="-\n";
    }
    cout<<ans;
}