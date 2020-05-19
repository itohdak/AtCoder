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

template<typename T>
vector<T> slide_min(const vector<T>& v, int k) {
  deque<int> deq;
  vector<T> ret;
  for(int i=0; i<v.size(); i++) {
    while(!deq.empty() && v[deq.back()] >= v[i]) deq.pop_back();
    deq.push_back(i);
    if(i-k+1 >= 0) {
      ret.push_back(v[deq.front()]);
      if(deq.front() == i-k+1) deq.pop_front();
    }
  }
  return ret;
}
template<typename T>
vector<T> slide_max(const vector<T>& v, int k) {
  deque<int> deq;
  vector<T> ret;
  for(int i=0; i<v.size(); i++) {
    while(!deq.empty() && v[deq.back()] <= v[i]) deq.pop_back();
    deq.push_back(i);
    if(i-k+1 >= 0) {
      ret.push_back(v[deq.front()]);
      if(deq.front() == i-k+1) deq.pop_front();
    }
  }
  return ret;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  rep(i, N) cin >> P[i];
  vector<int> ord(N-1);
  rep(i, K-1) if(P[i+1]-P[i]>0) ord[0]++;
  REP(i, 1, N-K+1) {
    ord[i] = ord[i-1];
    if(P[i]-P[i-1]>0) ord[i]--;
    if(P[i+K-1]-P[i+K-2]>0) ord[i]++;
  }
  int cntOrd = 0;
  rep(i, N-K+1) if(ord[i] == K-1) cntOrd++;

  int cnt = 0;
  vector<int> mn = slide_min(P, K+1);
  vector<int> mx = slide_max(P, K+1);
  rep(i, N-K) if(ord[i+1] != K-1 && P[i] == mn[i] && P[i+K] == mx[i]) cnt++;

  cout << N-K+1-max(cntOrd-1, 0)-cnt << endl;
  return 0;
}
