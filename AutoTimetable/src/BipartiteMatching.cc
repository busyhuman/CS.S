// SKU 20150887 Kang Hyeon Dae
// C++14 GNU
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int classCnt = 9;
const int dayCnt = 5;
const int maxSubject = 100;
int TimeTable[dayCnt][classCnt], day, start, length, subNum, subCnt;			// 시간표, 시작 시간, 강의 시간
int subNumArr[maxSubject];
string subName, dayStr[dayCnt] = {"월", "화", "수", "목", "금"};		// 과목명, 요일
vector< tuple< int, int, int, int > > subjectArr[maxSubject];	// 과목정보( 과목명, 요일, 시작시간, 강의 시간 )
bool visit[maxSubject];	// 매칭 시 방문체크. 
vector< bool > isFull[maxSubject];
map< int, string > mp;

// Using Bipartite Matching. 현재 노드, 간선 호
int makeTimeTable(int now, int mow){
	if(visit[now]) return 0;
	visit[now] = true;

	int curLen = subjectArr[now].size();
	for(int i=mow;i<curLen;i++){
		int curDay = get<1>(subjectArr[now][i]), curStart = get<2>(subjectArr[now][i]), curLength = get<3>(subjectArr[now][i]);
		int nowNum = TimeTable[curDay][curStart];

		if( isFull[now][i] ) continue;
		
		if( ( nowNum == 0 ) || ( visit[nowNum] == false && makeTimeTable( nowNum, i) )  ){
	
			if(nowNum != 0){
				int imsi = curStart;
				while( TimeTable[curDay][imsi] == nowNum){
			
					TimeTable[curDay][imsi] = 0;
					imsi++;
				}
				imsi = curStart-1;
				while( TimeTable[curDay][imsi] == nowNum){
			
					TimeTable[curDay][imsi] = 0;
					imsi--;
				}
			} 
			for(int i=curStart;i<curStart+curLength;i++)
				TimeTable[curDay][i] = now;
			return 1;
		}
			
	}
	return 0;
}

// 모든 간선 순회
void BipartiteMatching(){
	for( map<int, string>::iterator it = mp.begin();it != mp.end();it++){
		memset(visit, false, sizeof(visit) );
		makeTimeTable(it->first, 0);
	}
}

// 입력 받음
void setSub(){
	cin >> subCnt;
	
	for(int i=0;i<subCnt;i++){
		cin >> subName;
		cin >> subNum >> day >> start >> length;
		mp[subNum] = subName;
		isFull[subNum].push_back(false);
		subjectArr[subNum].push_back( make_tuple( subNum, day, start-1, length ) );
	}
}

// 노드 번호, 노드 간선 저장
void getFilledSub(){
	int fullCnt;
	cin >> fullCnt;
	
	for(int i=0;i<fullCnt;i++) {
		int imsi, imsi2;
		cin >> imsi >> imsi2;
		isFull[imsi][imsi2] = true;
	}
}

// 결과 출력
void printTimeTable(){
	cout << "  ";
	for(int i=0;i<dayCnt;i++)
		cout << dayStr[i] << " ";
	cout << '\n';
	for(int i=0;i<classCnt;i++){
		cout << i+1 << ' ';
		for(int j=0;j<dayCnt;j++){
			if( TimeTable[j][i] ) cout << mp[TimeTable[j][i]] << ' ';
			else cout << "-- ";
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(TimeTable, 0, sizeof(TimeTable) );
	setSub();
	getFilledSub();
	BipartiteMatching();
	printTimeTable();
}
