#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    stack<pair<int,int>> st;
    st.push({100000002,0});

    int n;
    queue<int> ans;
    cin>>n;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;

        while(st.top().first<=t){
            st.pop();
        }
        ans.push(st.top().second);
        st.push({t,i+1});

    }
    while (!ans.empty())
    {
        cout<<ans.front()<<' ';
        ans.pop();
    }
    
    

}