#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vector<int> sumDays(13);
  rep(i, 12) sumDays[i+1] = sumDays[i]+days[i];
  set<int> st;
  {
    int tmp = 1;
    while(tmp <= 366) {
      st.insert(tmp);
      if(tmp-1) st.insert(tmp-1);
      tmp += 7;
    }
  }
  rep(i, n) {
    string s; cin >> s;
    int sla = s.find('/');
    int m = atoi(s.substr(0, sla).c_str());
    int d = atoi(s.substr(sla+1).c_str());
    int day = sumDays[m-1]+d;
    while(st.count(day)) day++;
    if(day <= 366) st.insert(day);
  }
  // cout << st << endl;
  int ans = 0;
  int l = 1, r;
  while(l <= 366) {
    while(l <= 366 && !st.count(l)) l++;
    if(l == 367) break;
    r = l;
    while(r < 366 && st.count(r) && st.count(r+1)) r++;
    ans = max(r-l+1, ans);
    l = r+1;
  }
  cout << ans << endk;
  return 0;
}
