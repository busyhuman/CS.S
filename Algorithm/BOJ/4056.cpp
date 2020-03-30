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
int n = 9;
int arr[10][10];
bool garo[10][10],sero[10][10], sqr[10][10];
bool ans =false;
int square(int i, int j){
    return 3*(i/3) + (j/3);   
}
void dfs(){
    if(ans) {
        return;
    }
    int y=-1,x=-1;
    for(int i =0 ;i<n;i++){
        for(int j=0;j<n;j++){
            if(!arr[i][j]){
                y=i;
                x=j;
                break;
            }
        }
        if(y!=-1 && x!=-1){
            break;
        } 
    }
    if(y == -1 && x == -1){
        ans = true;
        return;
    }

    for(int i =1;i<=n;i++){
        int imsi = square(y,x);
        if(!garo[y][i] && !sero[x][i] && !sqr[imsi][i]){
            garo[y][i] = sero[x][i] = sqr[imsi][i] = true;
            arr[y][x]=i;
            dfs();
            if(ans){
                return;
            }
            arr[y][x] = 0;
             garo[y][i] = sero[x][i] = sqr[imsi][i] = false;
        }
    }
}

int main() {
	int t;
	cin >> t;
	while(t--){
		memset(sqr,false,sizeof(sqr));
		memset(garo,false,sizeof(garo));
		memset(sero,false,sizeof(sero));
		bool check = false;
		ans=false;
		for(int i=0;i<n;i++){
			string s;
			cin >> s;
			for(int j=0;j<n;j++){
				arr[i][j] = s[j] - '0';
				if(arr[i][j] && (garo[i][arr[i][j]] || sero[j][arr[i][j]] || sqr[square(i,j)][arr[i][j]]) ) check = true;
				garo[i][arr[i][j]]=true;
				sero[j][arr[i][j]]=true;
				sqr[square(i,j)][arr[i][j]]=true;
			}
		}
		if(check){
			cout << "Could not complete this grid.\n\n";
			continue;
		}
		dfs();
		if(ans){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout << arr[i][j];
				}
				cout << '\n';
			}
		}
		else
			cout << "Could not complete this grid.\n";
		cout << '\n';
	}
}
