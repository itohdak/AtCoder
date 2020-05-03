#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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
