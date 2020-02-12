#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
map<string, int> idx;
map<int, int> dict;
vector< tuple<int,int,int> > arr;
vector< pair<int,int> > arr2;
bool comp(tuple<int,int,int> a, tuple<int,int,int> b){
    int da = dict[get<2>(a)], db = dict[get<2>(b)];
    if( da > db) return true;
    else if(da == db){
        if(get<1>(a) > get<1>(b)) return true;
        else if(get<1>(a) == get<1>(b)){
            if(get<0>(a) < get<0>(b)) return true;
        }
    }
    return false;
}

bool comp2(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {

    int len = plays.size(), cnt=0;
    for(int i=0;i<len;i++){
        string temp = genres[i];
        if(idx[temp] == 0) idx[temp] = ++cnt;
        int temp2 = idx[temp];
        dict[temp2] += plays[i];
        arr.push_back(make_tuple(i,plays[i],temp2) );
    }
    sort( arr.begin(), arr.end(), comp);

    vector<int> answer;
    for(map<int,int>::iterator it=dict.begin();it!=dict.end();it++){
        arr2.push_back(make_pair(it->first,it->second));
    }
    sort( arr2.begin(), arr2.end(), comp2);
    for(int i=0;i<cnt;i++){
        int su = 0;
        for(int j=0;j<len;j++){
            int su2 = get<2>(arr[j]);
            if(su == 2) break;
            if(su2 == arr2[i].first){
                su++;
                answer.push_back(get<0>(arr[j]));
            }
        }
    }
    return answer;
}
 
