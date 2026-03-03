#include <bits/stdc++.h>
using namespace std;

/*
주어진 수의 순서 무시 x, 연산자의 자리를 배치해서 식의 최대 , 최소 값 구하기
np로 조합 구하기
덧셈을 0, 뺄셈을 1, 곱셈을 2, 나눗셈3으로  마스킹 생성 후 식을 계산
최댓값 최솟 값 갱신

음수를 양수로 나눌때는, 양수로 전환 뒤 몫을 취하고, 몫을 다시 음수로
*/

int n;
int op[4];
int arr[15];
int ansm = INT_MAX, ansM = INT_MIN;

void solve(int ans, int k)
{
    if (k == n)
    {
        ansm = min(ansm, ans);
        ansM = max(ansM, ans);
    }
    for (int i = 0; i < 4; i++)
    {
        if (op[i] == 0)
            continue;
        op[i]--;
        if (i == 0)
            solve(ans + arr[k], k + 1);
        if (i == 1)
            solve(ans - arr[k], k + 1);
        if (i == 2)
            solve(ans * arr[k], k + 1);
        if (i == 3)
            solve(ans / arr[k], k + 1);
        op[i]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    solve(arr[0], 1);
    cout << ansM << '\n'
         << ansm;
}