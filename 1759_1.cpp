#include<bits/stdc++.h>
using namespace std;

int L,C;
char s[20];

bool aeiou(char t){
   return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>L>>C;
  for (int i = 0; i < C; i++)
  {
    cin>>s[i];
  }
  sort(s, s+C);
  vector<int> brute(C);
  for (int i = L; i < C; i++)
  {
    brute[i]=1;
  }
  do
  {
    string ans;
    int cnt1=0;
    int cnt2=0;
    for (int i = 0; i < C; i++)
    {
        if(brute[i]==0){
            ans+=s[i];
            if(aeiou(s[i])) cnt1++;
        }
    }
     if(cnt1 < 1 || L - cnt1 < 2) continue;
    cout << ans << '\n';
  } while (next_permutation(brute.begin(),brute.end()));
  
  
}
