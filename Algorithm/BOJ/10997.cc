#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <bitset>
#include <set>
#include <map>
using namespace std;
#define inf 2000000000
#define mod 1000000007
bool arr[430][430];
int n,last;

void f(int col, int row,int len, int direction, int onemore,int cnt){
    if(cnt == last+1){
        return;
    }
    if(cnt == last){
        len -= 2;
    }
    if(onemore==1){
        onemore=2;
    }else if(onemore==2){
        onemore=1;
        len+=2;
    } else if(onemore==0){
        onemore=1;   
    }
    if(direction == 1){
        for(int i=0;i<len;i++){
               arr[col-i][row]=true;
        }
        f(col-len+1,row,len,(direction%4)+1,onemore,cnt+1);
    } else if(direction == 2){
        for(int i=0;i<len;i++){
               arr[col][row+i]=true;
        }
        f(col,row+len-1,len,(direction%4)+1,onemore,cnt+1);
    } else if(direction == 3){
        for(int i=0;i<len;i++){
               arr[col+i][row]=true;
        }
        f(col+len-1,row,len,(direction%4)+1,onemore,cnt+1);
    } else if(direction == 4){
        for(int i=0;i<len;i++){
               arr[col][row-i]=true;
        }
        f(col,row-len+1,len,(direction%4)+1,onemore,cnt+1);
    }
    
}

int main(){
    cin >> n;
    last = 4*n-2;
    if(n==1){
        cout << '*';
        return 0;
    }
    f(n*2+1,n*2-1,3,1,0,1);
    for(int i=1;i<=4*n-1;i++){
        for(int j=1;j<4*n-2;j++){
            if(i==2 && j>1){
                continue;
            }
            if(arr[i][j]){
                cout << '*';
            }
            else{
                cout << ' ';
            }
        }
        cout << '\n';
    }
}