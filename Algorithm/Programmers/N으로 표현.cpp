#include <vector>
#include <algorithm>
using namespace std;

int answer = 9;
void dfs(int now, int cnt, int N, int number){
    if(now == number){
        answer = min(answer, cnt);
        return;
    }
    
    int su = N;
    for(int i=0;i<8-cnt;i++){
        dfs(now+su,cnt+1+i,N,number);
        dfs(now-su,cnt+1+i,N,number);
        dfs(now*su,cnt+1+i,N,number);
        dfs(now/su,cnt+1+i,N,number);
        su = su*10+N;
    }
    
}
int solution(int N, int number) {
    dfs(0,0,N,number);
    return answer > 8 ? -1 : answer;
}
