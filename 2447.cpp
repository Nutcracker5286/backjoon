#include<bits/stdc++.h>
using namespace std;

const int MAXN = 210000;
string s[MAXN];

void blank(int n, int r, int c) {
    for (int i = r; i < r+n; i++) {
        for (int j = c; j < c+n; j++) {
            s[i][j] = ' ';
        }
    }
    return;
}

void solve(int n, int r, int c) {
    if (n == 3) {
        s[r][c] = s[r][c + 1] = s[r][c + 2] = '*';
        s[r + 1][c] = s[r + 1][c + 2] = '*'; s[r+1][c+1]=' ';
        s[r + 2][c] = s[r + 2][c + 1] = s[r + 2][c + 2] = '*';
        return;
    }

    int nxt = n / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!(i == 1 && j == 1)) {
                solve(nxt, r + i * nxt, c + j * nxt);
            }
            else{
                blank(nxt, r+nxt,c+nxt);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        s[i] = string(n + 1, '\n');
    }

    solve(n, 0, 0);

    for (int i = 0; i < n; i++) {
        cout << s[i];
    }

    return 0;
}
