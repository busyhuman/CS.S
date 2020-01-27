#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
bool check[2001][2001];

bool bfs(int& a, int& b, int& c){
    queue<int> x,y;
    x.push(0);
    y.push(0);
    check[0][0] = true;
    x.push(a);
    y.push(b);
    check[a][b] = true;
    memset(check,false,sizeof(check));

    while(!y.empty()){
        int xf = x.front(), yf = y.front();
        x.pop(), y.pop();

        if(xf == c || yf == c) return true;
        
        if(!check[xf][0]){
            check[xf][0] = true;
            x.push(xf);
            y.push(0);
        }


        if(!check[xf][b]){
            check[xf][b] = true;
            x.push(xf);
            y.push(b);
        }

        if(!check[0][yf]){
            check[0][yf] = true;
            x.push(0);
            y.push(yf);
        }

        if(!check[a][yf]){
            check[a][yf] = true;
            x.push(a);
            y.push(yf);
        }

        int temp = min(a - xf, yf);
        if(!check[xf + temp][yf - temp]){
            check[xf + temp][yf - temp] = true;
            x.push(xf + temp);
            y.push(yf - temp);
        }

        temp = min(xf, b - yf);
        if(!check[xf - temp][yf + temp]){
            check[xf - temp][yf + temp] = true;
            x.push(xf - temp);
            y.push(yf + temp);
        }
    }
    return false;
}
string solve(int a, int b, int c) {
    return bfs(a,b,c) ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string abc_temp;
        getline(cin, abc_temp);

        vector<string> abc = split_string(abc_temp);

        int a = stoi(abc[0]);

        int b = stoi(abc[1]);

        int c = stoi(abc[2]);

        string result = solve(a, b, c);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
