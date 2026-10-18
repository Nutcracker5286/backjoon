#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int dx [] =  { 1,0,-1,0 };
int dy[]= {0,1,0,-1};
int n,maxCoreCnt,ans;
int brd[20] [20] ;
vector<pair<int,int>>  core;


bool oob(int x, int y){
	return x<0 || y<0 || x>= n || y>=n;
}



bool isConnect (int x, int y , int d){
    int nx =x +dx[d] , ny =y +dy[d];
	while(!oob(nx, ny)){
    	if(brd[nx][ny] != 0 ) return  false;
        nx +=dx[d];
        ny += dy[d] ;
    }
    return true;
}

int makeConnect(int x, int y, int d){
	    int nx =x +dx[d] , ny =y +dy[d];
    int cnt =0;
	while(!oob(nx, ny)){
        cnt++;
    	brd[nx][ny] = 2; 
        nx +=dx[d];
        ny += dy[d] ;
    }
    return cnt;
}
void  unConnect(int x, int y, int d){
	    int nx =x +dx[d] , ny =y +dy[d];
	while(!oob(nx, ny)){
    	brd[nx][ny] = 0 ;
        nx +=dx[d];
        ny += dy[d] ;
    }
    return ;

}

void  solve(int k, int  ccnt, int ecnt){
	if( k ==  core.size()) {
    	 if( ccnt  > maxCoreCnt ){
         	 ans = ecnt;
             maxCoreCnt = ccnt;
         } 
        if( ccnt  ==  maxCoreCnt)
            ans = min(ans,  ecnt);
        return  ;
    }
    
    // no  select 
    solve(k+1, ccnt, ecnt);
    
    	// select 
    for(int d=0; d<4; d++){
        int x , y;
    	tie(x,y )  = core[k];
        
        if( !isConnect(x,y,d )) continue;
        
      	int  add  =   makeConnect( x,y, d);
        solve(k+1, ccnt+1, ecnt +add);
        unConnect(x,y, d);
    }
    
    

}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
        
         cin >> n;
        maxCoreCnt = 0;
        ans = INT_MAX;
        core.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> brd[i][j];
                if (brd[i][j])
                {
                    // 가장자리면 벡터 추가 x
                    if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                        continue;
                    core.push_back({i, j});
                }
            }
        }
  	
 	solve( 0,0,0) ;       
        
        
        
        
		/////////////////////////////////////////////////////////////////////////////////////////////
        cout << "#"<<test_case <<" "<< ans<<"\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}