#include <string>
#include <bits/stdc++.h>

using namespace std;
int t;
bool cmp(int a, int b){
    if(abs(a-t)==abs(b-t)) return a>b;
    return abs(a-t)<abs(b-t);
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    t=n;
    sort(numlist.begin(),numlist.end(), cmp);
    return numlist;
}