#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
/*
단순 최단경로가 아닌 개수를 물어봄, 완전 탐색 2^100*2^100이라 불가능
따라서 dp사용
웅덩이는 0으로 두고 패스


테이블 정의
d[i][j] = i,j에 도달했을때 가능한 최단 경로의 개수

점화식
d[i][j] = d[i-1][j-1] + d[i-1][j] + d[i][j-1])

초기값
d[1][1] =1;
*/

int d[110][110];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    sort(puddles.begin(), puddles.end() , [](auto a, auto b){
        if(a[1]== b[1])
            return a[0]< b[0];
        return a[1]< b[1];
    }
        );
    
        set<pair<int,int>> pud;
    
    for(auto v: puddles){
        pud.insert({v[1],v[0]});
    }
    
    
    // 초기화
    d[1][1]=1;
        
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 && j==1) continue;
            if(pud.find({i,j})!= pud.end()) continue;
            d[i][j] = ( d[i-1][j]+d[i][j-1])%1000000007;
            
        }
        cout<<'\n';
    }
    
    return d[n][m];
}