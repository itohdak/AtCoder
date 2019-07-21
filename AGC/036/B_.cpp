#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  vector<string> memo(N);
  vector<int> top(N);
  unordered_map<int, int> mp;
  string tmp;
  int tmpTop;
  for(int i=N-1; i>=0; i--) {
    unordered_map<int, int>::iterator itr = mp.find(A[i]);
    if(itr == mp.end()) {
      tmp = to_string(A[i]) + " " + tmp;
      tmpTop = A[i];
    } else {
      if(itr->second == N-1) {
        tmp = "";
        tmpTop = -1;
      } else {
        tmp = memo[itr->second+1];
        tmpTop = A[itr->second+1];
      }
    }
    memo[i] = tmp;
    top[i] = tmpTop;
    mp[A[i]] = i;
  }
  vector<int> memo2;
  set<int> s;
  int tmp2 = 0;
  while(s.find(tmp2) == s.end()) {
    memo2.push_back(tmp2);
    s.insert(tmp2);
    if(tmp2 == N || memo[tmp2] == "") {
      tmp2 = 0;
    } else {
      tmp2 = mp[top[tmp2]]+1;
    }
  }
  int k = memo2.size();
  K--;
  K %= k;
  if(memo2[K] == N)
    cout << endl;
  else {
    cout << memo[memo2[K]];
    cout << endl;
  }
  return 0;
}

