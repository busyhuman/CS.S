#include <bits/stdc++.h>
#include <map>
using namespace std;

map<long long, bool> dict;
// Complete the solve function below.

void fibo(){
    dict[0] = true;
    long long a=0,b=1,c;
    for(int i=0;i<=50;i++){
        dict[a+b] = true;
        c = a;
        a = b;
        b = b+c;
    }
}
string solve(long n) {
    return dict[n] ? "IsFibo" : "IsNotFibo";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    fibo();
    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
