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
  int n, k; cin >> n >> k;
  vector<pair<ll, int>> S(n);
  rep(i, n) {
    cin >> S[i].second >> S[i].first;
    S[i].second--;
  }
  sort(all(S), greater<pair<ll, int>>());
  ll cur = 0;
  vector<ll> ans(n+1, -longinf);
  priority_queue<pair<ll, int>> q1;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q2;
  set<int> se;
  rep(i, n) {
    if(i < k) {
      cur += S[i].first;
      if(se.count(S[i].second)) q2.push(S[i]);
      se.insert(S[i].second);
    } else {
      if(!se.count(S[i].second)) q1.push(S[i]);
    }
  }
  ans[se.size()] = cur + se.size()*se.size();
  while(!q1.empty()) {
    auto ele = q1.top(); q1.pop();
    if(se.count(ele.second)) continue;
    if(q2.empty()) break;
    auto ele2 = q2.top(); q2.pop();
    cur += ele.first - ele2.first;
    se.insert(ele.second);
    ans[se.size()] = cur + se.size()*se.size();
  }
  cout << *max_element(all(ans)) << "\n";
  return 0;
}
