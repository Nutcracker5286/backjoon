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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    int ansm = INT_MAX, ansM = INT_MIN;

    vector<int> mask; // 0, 1, 2 ,3 + - * /
    // 연산자 별로 마스킹 백터 삽입
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < op[i]; j++)
        {
            mask.push_back(i);
        }
    }

    // 조합 시작
    do
    {
        int sum = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (mask[i - 1] == 0)
            { // 0, 덧셈
                sum += arr[i];
            }
            else if (mask[i - 1] == 1)
            { // 1, 빼기
                sum -= arr[i];
            }
            else if (mask[i - 1] == 2)
            { // 2, 곱셈
                sum *= arr[i];
            }
            else
            { // 3,나눗셈
                 sum /= arr[i];
            }
        }
        ansM = max(sum, ansM);
        ansm = min(sum, ansm);

    } while (next_permutation(mask.begin(), mask.end()));
    cout << ansM << '\n'
         << ansm;
}