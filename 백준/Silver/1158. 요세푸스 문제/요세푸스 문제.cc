#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    list<int> L;
    for(int i = 1; i <= N; i++){
        L.push_back(i);
    }

    auto p = L.begin();

    cout << "<";

    while(!L.empty()){
        //  K-1번 이동
        for(int i = 0; i < K-1; i++){
            p++;
            if(p == L.end()) 
                p = L.begin();
        }

        // 출력
        cout << *p;
        if(L.size() > 1) cout << ", ";

        //  제거 → p는 자동으로 다음 위치
        p = L.erase(p);

        // 만약 erase로 end가 되었으면 begin으로 보정
        if(p == L.end()) 
            p = L.begin();
    }

    cout << ">";
}