#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
/*
n방 정방행렬에 m개의 나무를 심고 사계절마다 다른 액션을 취하는 상태
땅에 나무 중첩 가능

k년이 지난 후 살아있는 나무의 개수를 구하는 프로그램

처음 보드는 5로 시작
n,m,k 입력
n방 행렬에 겨울에 공급받는 양분 입력
m개의 나무 입력 위치,나이

k만큼 반복 시작
봄
나무가 나이만큼 양분 먹고 나이 1증가
중첩시 나이가 어린 나무부터 양분 섭취
나이만큼 양분 못 먹으면 즉시 사망

여름
죽은 나무가 양분으로
죽은 나무마다 나이/2 가 양분으로 추가

가을
나무 번식
단 나이가 5의 배수여야 함, 인접 8칸에 나이 1인 나무 생김

겨울
비료 배열 만큼 양분을 추가
*/
int brd[15][15], a[15][15];
int n, m, k;
deque<pair<int, int>> tree[15][15]; // 나이 , 생존 여부
vector<pair<int, int>> at;
// 0 죽음, 1생존

void birth(int x, int y)
{
    for (auto i : {-1, 0, 1})
    {
        for (auto j : {-1, 0, 1})
        {
            if (x + i < 0 || y + j < 0 || x + i >= n || y + j >= n)
                continue;
            if (i == 0 && j == 0)
                continue;
            tree[x + i][y + j].push_front({1, 1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&brd[0][0], &brd[0][0] + 15 * 15, 5);
    cin >> n >> m >> k;

    // 비료
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // 나무
    while (m--)
    {
        int r, c, z;
        cin >> r >> c >> z;
        tree[r - 1][c - 1].push_back({z, 1});
    }

    // k년 시뮬
    while (k--)
    {
        // 봄
        //  나무가 나이만큼 양분 먹고 나이 1증가
        //  중첩시 나이가 어린 나무부터 양분 섭취
        //  나이만큼 양분 못 먹으면 즉시 사망
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tree[i][j].empty())
                    continue;

                int stamina = brd[i][j];
                deque<pair<int, int>> nxt;
                int deadFood = 0;
                bool dead = false;

                for (auto &c : tree[i][j])
                {
                    int age = c.X;

                    if (!dead && stamina >= age)
                    {
                        stamina -= age;
                        nxt.push_back({age + 1, 1});
                    }
                    else
                    {
                        dead = true;
                        deadFood += age / 2;
                    }
                }

                stamina += deadFood;
                tree[i][j] = move(nxt);
                brd[i][j] = stamina;
            }
        }

        // 가을
        // 나무 번식
        // 단 나이가 5의 배수여야 함, 인접 8칸에 나이 1인 나무 생김
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tree[i][j].empty())
                    continue;

                int stamina = brd[i][j];
                for (auto c : tree[i][j])
                {
                    if (c.X % 5 != 0)
                        continue;
                    // 인접 8칸에 나이 1인 나무 생성
                    birth(i, j);
                }
            }
        }

        // 겨울
        // 비료 배열 만큼 양분 추가
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                brd[i][j] += a[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tree[i][j].empty())
                continue;
            for (auto c : tree[i][j])
            {
                ans += c.Y == 1;
            }
        }
    }
    cout << ans;
}