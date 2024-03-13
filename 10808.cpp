#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    
    int freq[26];
    fill(freq, freq+26,0);

    for(auto c: s)
    {
        freq[c-'a']++;
    }
    for(int i=0; i<26; i++) cout<<freq[i]<<" ";
}