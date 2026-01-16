#include <iostream>

using namespace std;

int main()
{
int n;
int a[100];
int ta;
int ans=0;

cin>>n;
for(int i=0; i<n; i++)
{
  cin>>a[i];
}
cin>>ta;

for(int i=0; i<n; i++)
{
  if(ta==a[i]) ans++;
}
cout<<ans;
}