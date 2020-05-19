#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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
  map<char, set<int>> mp;
  rep(i, N) {
    if(A[i] != B[i]) mp[B[i]].insert(i);
  }
  int cnt = 3;
  rep(i, N) {
    if(A[i] != B[i]) {
      if(cnt == 0) {
        cout << "NO" << endl;
        return 0;
      } else {
        int j = *mp[A[i]].begin();
        swap(B[i], B[j]);
        mp[A[i]].erase(j);
        mp[B[j]].erase(i);
        if(A[j]!=B[j]) mp[B[j]].insert(j);
        cnt--;
      }
    }
  }
  map<char, int> cntAlpha;
  rep(i, N) cntAlpha[A[i]]++;
  bool two = false;
  for(auto c: cntAlpha) if(c.second >= 2) two = true;
  if(cnt == 0) cout << "YES" << endl;
  else if(cnt == 1) {
    cout << (two ? "YES" : "NO") << endl;
  } else if(cnt == 2) {
    cout << "YES" << endl;
  } else {
    cout << (two ? "YES" : "NO") << endl;
  }
  return 0;
}
