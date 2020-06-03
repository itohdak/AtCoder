#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string A, B;
  cin >> A >> B;
  int N = A.size();
  string C = "", D = "";
  vector<int> cntA(26), cntB(26);
  rep(i, N) {
    cntA[A[i]-'a']++;
    cntB[B[i]-'a']++;
    if(A[i] != B[i]) {
      C += A[i];
      D += B[i];
    }
  }
  bool two = false;
  rep(i, 26) {
    if(cntA[i] >= 2) two = true;
    if(cntA[i] != cntB[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }

  function<bool(string&, string&, int)> dfs = [&](string& a, string& b, int rem) {
    if(rem == 0) return a == b;
    int n = a.size();
    rep(i, n) rep(j, n) if(i != j) {
      swap(b[i], b[j]);
      if(dfs(a, b, rem-1)) return true;
      swap(b[i], b[j]);
    }
    return false;
  };

  if(C.size() > 6) {
    cout << "NO" << endl;
  } else if(C.size() == 0) {
    cout << (two ? "YES" : "NO") << endl;
  } else if(C.size() == 2) {
    cout << "YES" << endl;
  } else if(C.size() == 3) {
    cout << (two ? "YES" : "NO") << endl;
  } else {
    cout << (dfs(C, D, 3) ? "YES" : "NO") << endl;
  }
  return 0;
}
