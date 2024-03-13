#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s1,s2;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        int a[26]={};
        cin>>s1>>s2;

        for(auto c:s1) a[c-'a']++;
        for(auto c:s2) a[c-'a']--;

        bool isp=true;

        for(auto c:a) if(c!=0) isp=false;

        if(isp)cout<<"Possible\n";
        else cout<<"Impossible\n";
 
    }
    
}