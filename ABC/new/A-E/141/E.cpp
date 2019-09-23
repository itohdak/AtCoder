#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void Zalgorithm(string S, vector<int>& res) {
  res[0] = S.size();
  int i = 1, j = 0;
  while (i < S.size()) {
    while (i+j < S.size() && S[j] == S[i+j]) ++j;
    res[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < S.size() && k+res[k] < j) res[i+k] = res[k], ++k;
    i += k; j -= k;
  }
}

int main() {
  int N;
  string S;
  cin >> N >> S;
  string Stmp = S;
  vector<int> A(N);
  int ans = 0;
  rep(i, N) {
    Zalgorithm(Stmp, A);
    rep(j, Stmp.size()) {
      ans = max(ans, min(A[j], j));
    }
    Stmp = Stmp.substr(1);
  }
  cout << ans << endl;
  return 0;
}

