#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int> > A;
  rep(i, N) {
    int a;
    cin >> a;
    A.push_back(make_pair(a, i+1));
  }
  sort(A.begin(), A.end());
  rep(i, N)
    cout << A[i].second << ' ';
  cout << endl;
  return 0;
}

