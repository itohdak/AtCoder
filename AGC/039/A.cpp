#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string S;
  ll K;
  cin >> S >> K;
  int N = S.size();
  ll cnt = 0;
  char tmp = S[0];
  vector<int> memo;
  int same = 1;
  REP(i, 1, N) {
    if(S[i] == tmp) same++;
    else {
      cnt += same / 2;
      memo.push_back(same);
      tmp = S[i];
      same = 1;
    }
  }
  cnt += same / 2;
  memo.push_back(same);
  if(same == N) {
    cout << N * K / 2 << endl;
  } else {
    if(S[0] == S[N-1] && memo[0] % 2 == 1 && memo.back() % 2 == 1)
      cout << cnt * K + K-1 << endl;
    else
      cout << cnt * K << endl;
  }
  return 0;
}

