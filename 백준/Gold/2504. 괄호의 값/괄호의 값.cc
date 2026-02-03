/*
괄호 안헹 있으면 각 괄호에 해당하는 값의 곱이 계속 곱해짐
따라서 들어가는 괄호면 특정 값에 계속 곱해주면 됨
닫는 괄호 나오면 해당 괄호값에 따라 나누기
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long ans = 0;
    long long tmp = 1;
    string s;

    cin >> s;

    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        // 2배 여는 괄호
        if (s[i] == '(')
        {
            tmp *= 2;
            st.push(s[i]);
        }
        // 3배 여는 괄호
        else if (s[i] == '[')
        {
            tmp *= 3;
            st.push(s[i]);
        }
        // 2배 닫는 괄호
        else if (s[i] == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                // 불량 이면
                cout << 0;
                return 0;
            }
            // 중첩이 아니고 바로 숫자변환이면
            if (s[i - 1] == '(')
                ans += tmp;
            tmp /= 2;
            st.pop();
        }
        // 3배 닫는 괄호
        else
        {
            if (st.empty() || st.top() != '[')
            {
                // 불량 이면
                cout << 0;
                return 0;
            }
            // 중첩이 아니고 바로 숫자변환이면
            if (s[i - 1] == '[')
                ans += tmp;
            tmp /= 3;
            st.pop();
        }
    }

    if (!st.empty())
    {
        cout << 0;
        return 0;
    }
    cout << ans;
}