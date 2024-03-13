#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    int a[26]={};
    int cnt=0;

    cin>>s1>>s2;

    for(auto c: s1) a[c-'a']++;
    for(auto c: s2) a[c-'a']--;

    for(auto c: a) cnt+=abs(c);
    cout<<cnt;

}