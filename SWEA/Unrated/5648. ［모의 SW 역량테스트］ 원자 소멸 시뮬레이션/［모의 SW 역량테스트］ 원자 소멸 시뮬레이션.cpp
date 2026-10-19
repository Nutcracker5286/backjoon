#include <bits/stdc++.h>
using namespace std;

struct Atom {
    int x, y;
    int dir;
    int energy;
};

// 상, 하, 좌, 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

const int OFFSET = 2000;
const int MAX = 4000;

// 현재 위치에 도착한 원자 수
// N <= 1000이므로 unsigned short로 충분
unsigned short cnt[4001][4001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        int n;
        cin >> n;

        vector<Atom> atoms;
        atoms.reserve(n);

        // 초기 원자 정보 입력
        for (int i = 0; i < n; i++) {
            int x, y, dir, energy;
            cin >> x >> y >> dir >> energy;

            // 좌표 2배 확대 + 음수 좌표 보정
            x = x * 2 + OFFSET;
            y = y * 2 + OFFSET;

            atoms.push_back({x, y, dir, energy});
        }

        vector<Atom> moved;
        vector<Atom> next;

        moved.reserve(n);
        next.reserve(n);

        int ans = 0;

        // 한 번 반복 = 0.5초
        for (int t = 1; t <= 4000; t++) {

            // 원자가 1개 이하면 더 이상 충돌 불가능
            if (atoms.size() <= 1)
                break;

            moved.clear();
            next.clear();

            // 1. 모든 원자를 동시에 이동
            for (Atom a : atoms) {

                a.x += dx[a.dir];
                a.y += dy[a.dir];

                // 범위를 벗어나면 이후 충돌 불가능
                if (a.x < 0 || a.x > MAX ||
                    a.y < 0 || a.y > MAX)
                    continue;

                // 현재 좌표에 도착한 원자 수 기록
                cnt[a.x][a.y]++;

                moved.push_back(a);
            }

            // 2. 충돌 판정
            for (const Atom& a : moved) {

                // 같은 위치에 원자가 2개 이상 존재
                if (cnt[a.x][a.y] >= 2) {
                    ans += a.energy;
                }
                else {
                    // 충돌하지 않은 원자만 보존
                    next.push_back(a);
                }
            }

            // 3. 이번 시간에 사용한 좌표 초기화
            for (const Atom& a : moved) {
                cnt[a.x][a.y] = 0;
            }

            // 4. 다음 시간에 사용할 원자 목록 갱신
            atoms.swap(next);
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}