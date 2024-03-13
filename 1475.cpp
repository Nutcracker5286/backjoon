#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num[10] = {};
    int n;
    int ans = 0;

    cin >> n;
    if (n == 0)
        num[0]++;
    while (n)
    {
        num[n % 10]++;
        n = n / 10;
    }

    for (int i = 0; i < 10; i++)
    {
        // 6, 9 제외 우선 처리
        if (i == 6 || i == 9)
            continue;
        ans = max(ans, num[i]);
    }
    // 6,9 고려 후 데이터 처리
    int tmp = num[6] + num[9];
    if (tmp != 0)
    {
        if (tmp % 2 == 0) // 짝수일때
            num[6] = tmp/2;
        else
            num[6] = (tmp + 1)/2;
    }
    ans = max(ans, num[6]);


    cout  << ans;
}