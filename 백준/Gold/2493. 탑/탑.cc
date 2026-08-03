#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    queue<int> q;

    cin>>n;
    for(int i=0; i<n; i++){
        q.push(i+1);
    }


    while (q.size()>1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<q.front();
    

}