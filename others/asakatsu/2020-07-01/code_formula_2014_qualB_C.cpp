#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string A, B;
  cin >> A >> B;
  vector<int> cntA(26), cntB(26);
  vector<set<int>> pos(26);
  string a, b;
  int N = A.size();
  int cur = 0;
  rep(i, N) {
    cntA[A[i]-'a']++;
    cntB[B[i]-'a']++;
    if(A[i] != B[i]) {
      a += A[i]; b += B[i];
      pos[B[i]-'a'].insert(cur++);
    }
  }
  bool ok = true;
  rep(j, 26) if(cntA[j] != cntB[j]) ok = false;
  if(!ok) {
    cout << "NO\n";
    return 0;
  }
  int n = a.size();
  int cnt = 0;
  rep(i, n) {
    // cout << a << ' ' << b << endl;
    if(a[i] == b[i]) {
      pos[a[i]].erase(i);
      continue;
    }
    int j = *pos[a[i]-'a'].begin();
    // cout << j << endl;
    swap(b[i], b[j]);
    pos[a[i]-'a'].erase(j);
    pos[b[j]-'a'].insert(j);
    cnt++;
  }
  // cout << cnt << endl;
  if(cnt > 3) {
    cout << "NO\n";
  } else if(cnt == 3) {
    cout << "YES\n";
  } else if(cnt == 2) {
    bool ok = false;
    for(int c: cntA) if(c > 1) ok = true;
    cout << (ok ? "YES" : "NO") << "\n";
  } else if(cnt == 1) {
    cout << "YES\n";
  } else {
    if(N >= 3 || A[0]==A[1]) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
