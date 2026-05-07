#include <string>
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    vector<pair<int,int>> p(4);
    for(int i=0; i<4; i++)
        p[i] = {dots[i][0],dots[i][1]};
    
    sort(p.begin(),p.end());
    int x = p[2].X-p[0].X;
    int y = p[1].Y-p[0].Y;
    
    return x*y;
}