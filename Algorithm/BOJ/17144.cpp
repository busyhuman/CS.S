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
int r,c,t;		// 행, 열, 시간
int topcleanerY, topcleanerX, botcleanerX, botcleanerY;	// 청소기 두 칸의 위치
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};		// 북동남서
int arr[51][51];		// 구사과의 집

// 입력받는다.
void input(){
	cin >> r >> c >> t;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin >> arr[i][j];
}

// 공기청정기를 찾는다.
void findAirCleaner(){
	for(int i=0;i<r;i++)
		if(arr[i][0] == -1){
			topcleanerY = i;
			botcleanerY = i+1;
			return;
		}
}

// 미세먼지를 확산시킨다.
void spreadMicroDirt(int y, int x, int (*dp)[51]){
	int amount = arr[y][x] / 5;		// 확산될 미세먼지의 양
	
	for(int i=0;i<4;i++){
		int imsiy = y+dy[i], imsix = x+dx[i];
		if(imsiy < 0 || imsiy >= r || imsix < 0 || imsix >= c) continue;
		if(arr[imsiy][imsix] == -1) continue;
		dp[y][x] -= amount;
		dp[imsiy][imsix] += amount;
	}
}

// 확산된 미세먼지를 구사과의 집에 적용시킨다.
void calculateMicroDirt(int (*dp)[51]){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			arr[i][j] += dp[i][j];
}

// 미세먼지들을 찾는다.
void findMircroDirt(){
	int dp[51][51]={0};
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			if(arr[i][j] > 0)	// 미세먼지가 있으면,
				spreadMicroDirt(i,j,dp);	// 미세먼지를 확산시킨다.
	
	calculateMicroDirt(dp);
}

void operateAirCleaner(){
	
	// 위쪽 공기청정기 작동
	for(int i=topcleanerY-1;i>0;i--){
		arr[i][topcleanerX] = arr[i-1][topcleanerX];
	}
	for(int i=0;i<c-1;i++){
		if(i == 0 && topcleanerY == 0) continue;
		arr[0][i] = arr[0][i+1];
	}
	for(int i=0;i<topcleanerY;i++){
		if(i == topcleanerY-1 && c-1 == topcleanerX) continue; 
		arr[i][c-1] = arr[i+1][c-1];
	}
	for(int i=c-1;i>1;i--){
		arr[topcleanerY][i] = arr[topcleanerY][i-1];
	}
	arr[topcleanerY][topcleanerX+1] = 0;
	
	
	// 아래쪽 공기청정기 작동
	for(int i=botcleanerY+1;i<r-1;i++){
		arr[i][botcleanerX] = arr[i+1][botcleanerX];
	}
	for(int i=0;i<c-1;i++){
		if(i == 0 && botcleanerY == r-1) continue;
		arr[r-1][i] = arr[r-1][i+1];
	}
	for(int i=r-1;i>botcleanerY;i--){
		if(i == botcleanerY+1 && c-1 == botcleanerX) continue;
		arr[i][c-1] = arr[i-1][c-1];
	}
	for(int i=c-1;i>1;i--){
		arr[botcleanerY][i] = arr[botcleanerY][i-1];
	}
	arr[botcleanerY][botcleanerX+1] = 0;
}

// 결과 출력
int output(){
	int sum = 0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			if(arr[i][j] > 0)
				sum += arr[i][j];
	return sum;
}

/*
void printArr(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}
*/

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	findAirCleaner();
	while(t--){
		findMircroDirt();
		operateAirCleaner();
	}
	cout << output();
}
