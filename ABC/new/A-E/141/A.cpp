#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string S;
  cin >> S;
  if(S == "Sunny")
    cout << "Cloudy" << endl;
  else if(S == "Cloudy")
    cout << "Rainy" << endl;
  else
    cout << "Sunny" << endl;
  return 0;
}

