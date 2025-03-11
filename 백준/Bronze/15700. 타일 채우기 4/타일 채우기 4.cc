#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, m;
    cin >> n >> m;
    
    // 전체 넓이를 2로 나누면 최대 타일 개수가 됩니다
    cout << (n * m) / 2 << '\n';
    
    return 0;
}