#include <bits/stdc++.h>
using namespace std;

/*
n/2 팀 2개

팀원을 뽑아서 두팀의 점수 차가 최솟값이 되는경우

조합으로 절반의 인원을 뽑아서 팀생성
각 팀별로 이중 포문으로 점수 합
*/

int s[25][25];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }

    // 마스킹
    vector<int> mask(n, 0);
    fill(mask.begin() + n / 2, mask.end(), 1);

    int ans = INT_MAX;
    // 뽑기 시작
    do
    {
        vector<int> st;
        vector<int> li;

        for (int i = 0; i < n; i++)
        {
            if (mask[i])
            {
                st.push_back(i);
            }
            else
            {
                li.push_back(i);
            }
        }

        // 각팀의 능력치 계산, 팀에 속한 모든 쌍의 능력 치 합
        int stSum = 0, liSum = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                stSum += s[st[i]][st[j]];
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                liSum += s[li[i]][li[j]];
            }
        }

        ans = min(ans, abs(stSum - liSum));

    } while (next_permutation(mask.begin(), mask.end()));
    cout << ans;
}
