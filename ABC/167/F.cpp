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
  int N;
  cin >> N;
  vector<string> S(N);
  int cntl=0, cntr=0;
  vector<pair<int, int>> pp, pm, mp, mm;
  rep(i, N) {
    int diffMin=0, diffAll=0;
    cin >> S[i];
    for(char c: S[i]) {
      if(c == '(') {
        cntl++;
        diffAll++;
      } else {
        cntr++;
        diffAll--;
      }
      diffMin = min(diffAll, diffMin);
    }
    if(diffAll >= 0) {
      if(diffMin >= 0) pp.emplace_back(diffMin, diffAll);
      else             pm.emplace_back(diffMin, diffAll);
    } else {
      diffMin -= diffAll;
      diffAll *= -1;
      if(diffMin >= 0) mp.emplace_back(diffMin, diffAll);
      else             mm.emplace_back(diffMin, diffAll);
    }
  }

  if(cntl != cntr) {
    cout << "No" << endl;
    return 0;
  }

  {
    ll tmp = 0;
    for(auto p: pp) tmp += p.second;
    sort(all(pm), greater<pair<int, int>>());
    for(auto p: pm) {
      if(tmp + p.first < 0) {
        cout << "No" << endl;
        return 0;
      }
      tmp += p.second;
    }
  }
  {
    ll tmp = 0;
    for(auto p: mp) tmp += p.second;
    sort(all(mm), greater<pair<int, int>>());
    for(auto p: mm) {
      if(tmp + p.first < 0) {
        cout << "No" << endl;
        return 0;
      }
      tmp += p.second;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
