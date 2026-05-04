#include <string>
#include <vector>

using namespace std;

int solution(int a) {
    int an = 0;
    
    if(a>0  && a<90)  an=1;
    else if( a == 90 ) an=2;
    else if( a > 90 && a<180) an=3;
    else an=4;
    
    return an;
}