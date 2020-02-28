#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
char arr[6][6];
bool wall[27][27], visit[6][6], bisit[6][6];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};	// 상 우 하 좌
double hx[27][27];
const int mapSize = 5;
void Init(){
 
	// 미로 생성
	for(int i=0;i<mapSize;i++)
		for(int j=0;j<mapSize;j++)
			arr[i][j] = (char)(i*mapSize + j + 'A');
 
	// 휴리스틱 함수
	printf("H(x)\n");
	for(int i=0;i<mapSize;i++){
		for(int j=0;j<mapSize;j++){
			double r = mapSize- 1 - i, c = mapSize - 1 - j;
			hx[i][j] = sqrt(r*r + c*c);
			printf("%.2lf ", hx[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	// 미로 내부의 벽
	wall[1][6] = wall[6][1] = true;
	wall[3][8] = wall[8][3] = true;
	wall[4][9] = wall[9][4] = true;
	wall[6][7] = wall[7][6] = true;
	wall[7][8] = wall[8][7] = true;
	wall[10][11] = wall[11][10] = true;
	wall[11][12] = wall[12][11] = true;
	wall[12][13] = wall[13][12] = true;
	wall[12][17] = wall[17][12] = true;
	wall[13][14] = wall[14][13] = true;
	wall[15][16] = wall[16][15] = true;
	wall[16][21] = wall[21][16] = true;
	wall[17][18] = wall[18][17] = true;
	wall[18][19] = wall[19][18] = true;
	wall[21][22] = wall[22][21] = true;
	wall[23][24] = wall[24][23] = true;
 
}
 
void BFS(){
	queue<int> y,x;
	y.push(0);
	x.push(0);
	visit[0][0] = true;
 
	while(!x.empty()){
		int qlen = y.size();
 
		for(int l=0;l<qlen;l++){
			int yf = y.front(), xf = x.front();
			y.pop(), x.pop();
 
			printf("%c", (char)(yf*mapSize + xf + 'A'));
 
			// 종료조건. 탈출한 경우
			if(yf == mapSize-1 && xf == mapSize-1) break;
 
			vector<char> v;
 
			for(int i=0;i<4;i++){
				int goY = yf+dy[i], goX = xf+dx[i];
 
				// 미로의 외벽이면 큐에 넣지 않는다.
				if(goY < 0 || goY >= mapSize || goX < 0 || goX >= mapSize) continue;
 
				// 방문했던 곳도 큐에 넣지 않는다.
				if(visit[goY][goX]) continue;
 
				// 미로의 내벽이 있으면 큐에 넣지 않는다.
				if(wall[yf*mapSize + xf][goY*mapSize + goX]) continue;
 
				v.push_back(arr[goY][goX]);
			}
 
			// 알파벳 순서대로 정렬한다.
			sort(v.begin(), v.end());
 
			int len = v.size();
 
			// 큐에 넣어주고 방문을 체크한다.
			for(int i=0;i<len;i++){
				v[i] -= 'A';
				y.push(v[i] / mapSize);
				x.push(v[i] % mapSize);
				visit[v[i] / mapSize][v[i] % mapSize] = true;
			}
		}
		printf("\n");
	}
}
 
void Astar(){
	priority_queue< tuple<double, int, int, int> > pq;
	pq.push( make_tuple(0, 0, 0, 0));
	bisit[0][0] = true;
	while(!pq.empty()){
		int yf = get<1>(pq.top()), xf = get<2>(pq.top()), lf = get<3>(pq.top());
		pq.pop();
		printf("%c\n", (char)(yf*mapSize + xf + 'A'));
 
		// 종료조건. 탈출한 경우
		if(yf == mapSize-1 && xf == mapSize-1) break;
 
		for(int i=0;i<4;i++){
			int goY = yf+dy[i], goX = xf+dx[i];
 
			// 미로의 외벽이면 큐에 넣지 않는다.
			if(goY < 0 || goY >= mapSize || goX < 0 || goX >= mapSize) continue;
 
			// 방문했던 곳도 큐에 넣지 않는다.
			if(bisit[goY][goX]) continue;
 
			// 미로의 내벽이 있으면 큐에 넣지 않는다.
			if(wall[yf*mapSize + xf][goY*mapSize + goX]) continue;
 
			// 방문 체크
			bisit[goY][goX] = true;
 
			// 현재까지 이동한 거리 + 휴리스틱 함수, 이동할 y좌표, 이동할 x좌표, 이동 수
			pq.push( make_tuple(-(lf+hx[goY][goX]), goY, goX, lf+1));
 
		}
	}
}
 
int main(){
	Init();
 
	printf("[BFS 결과]\n");
	BFS();
	printf("\n");
 
	printf("[Astar 결과]\n");
	Astar();
}
