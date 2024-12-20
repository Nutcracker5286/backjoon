#include<bits/stdc++.h>
using namespace std;


int visit(int r, int c, int n){
    if(n==0) return 0;
    int half=1<<(n-1);
    if(r<half && c<half) return visit(r, c, n-1);
    if(r<half && c >= half) return half*half+visit(r, c-half, n-1);
    if(r>=half && c <half) return half*half*2+visit(r-half, c, n-1);
    return half*half*3+visit(r-half, c-half, n-1);
}
int main(){
    int n,r,c;
    cin>>n>>r>>c;
    cout<<visit(r,c,n);
}