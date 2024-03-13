#include <bits/stdc++.h>
using namespace std;

int main()
{
  int m;
  cin>>m;

  for(int t=0; t<m; t++)
  {
    list<char> L={};
    string s;
    cin>>s;
    auto p=L.begin();
    for(auto c:s) 
    {
      if(c=='<')
      {
        if(p!=L.begin()) p--;
      }


      else if(c=='>')
      {
        if(p!=L.end()) p++;
      }

      else if(c=='-')
      {
        if(p!=L.begin()) {p--; p=L.erase(p);}
      }

      else 
        L.insert(p,c);
    }

    for(auto c: L) cout<<c;
    cout<<"\n";
  }
}
