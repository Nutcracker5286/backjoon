#include <bits/stdc++.h>
using namespace std;
/*
a가 -1
b가 0
c가 1
*/
int a_1, b, c_1;
/*
종이 한개 그대로 사용
종이가 모두 같은수 그대로 사용
다른 경우 종이 9등분 후 반복

*/
bool check(const vector<vector<int>>& a, int r, int c, int n){
    int comp=a[r][c];
    bool fl=true;
    for (int i = r; i < r+n; i++)
    {
        for (int j = c; j < c+n; j++)
        {
            if(comp!=a[i][j]) return false;
        }
    }
    return true;
}
void solve(const vector<vector<int>>& a, int r, int c, int n) {
    if (check(a, r, c, n)) {
        if (a[r][c] == -1) a_1++;
        if (a[r][c] == 0) b++;
        if (a[r][c] == 1) {c_1++;}
        return;
    }
    int nxt = n / 3;
    solve(a, r, c, nxt);
    solve(a, r + nxt, c, nxt);
    solve(a, r + 2 * nxt, c, nxt);
    solve(a, r, c + nxt, nxt);
    solve(a, r + nxt, c + nxt, nxt);
    solve(a, r + 2 * nxt, c + nxt, nxt);
    solve(a, r, c + 2 * nxt, nxt);
    solve(a, r + nxt, c + 2 * nxt, nxt);
    solve(a, r + 2 * nxt, c + 2 * nxt, nxt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n+1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    solve(board, 0, 0, n);

    cout << a_1 << '\n' << b << '\n' << c_1 << '\n';

    return 0;
}