/*
dq로 시작
r이 입력되면 뒤에서 탐색하도록 변수 설정
d 하면 pop처리
*/
#include <bits/stdc++.h>
using namespace std;

int mp10(int ori, int size){
    if(size<=0)
    return ori;
    while (size--)
    {
        ori*=10;
    }
    return ori;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n;
    
    cin>>t;
    while (t--)
    {
        deque<int> operArr;
        string P,arr;
        
        cin>>P;
        cin>>n;
        cin>>arr;

        // 배열 파싱
        for(int i=0; i<arr.size(); i++){
            if(arr[i]=='[' || arr[i]==']') continue;
            string tmp;
            for (int j = i; arr[j] != ',' && arr[j]!=']'; j++)
            {
                tmp.push_back(arr[j]);
                i++;
            }
            int st=0;
            for(char c : tmp){
                st=st*10+c-'0';
            }
            operArr.push_back(st);
            
        }
        // 명령 수행
        bool isR = 0;
        bool isEr = 0;
        for (int i = 0; i < P.size(); i++)
        {
            if(P[i]=='R'){
                isR = !isR;
            }
            if(P[i]=='D' && isR== 0){
                if(operArr.empty()){
                    cout<<"error\n";
                    isEr=1;
                    break;
                }
                operArr.pop_front();
            }
            if(P[i]=='D' && isR== 1){
                if(operArr.empty()){
                    cout<<"error\n";
                    isEr=1;
                    break;
                }
                operArr.pop_back();
            }
        }
        if(isEr)
        continue;

        cout<<"[";
        if(isR==1){
            for (int i = operArr.size()-1; i >= 0; i--)
            {
                if(i!=0)
                cout<<operArr[i]<<",";
                else
                cout<<operArr[i];
            }
            
        }
        else
        for (int i = 0; i < operArr.size(); i++)
        {
            if(i!=operArr.size()-1)
                cout<<operArr[i]<<",";
                else
                cout<<operArr[i];
        }
        
        cout<<"]\n";
        

        
    }
    

}