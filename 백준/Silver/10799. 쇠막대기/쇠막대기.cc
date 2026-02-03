#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<char> st;
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push('(');
        }
        else
        { // ')'
            if (s[i - 1] == '(')
            { // 레이져인 경우
                st.pop();
                ans += st.size();
            }
            else
            { // 남은 막대기의 경우
                st.pop();
                ans++;
            }
        }
    }

    cout << ans;
}