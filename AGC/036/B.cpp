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
  vector<vector<int> > memo(N);
  vector<pair<int, int> > memo3(N);
  unordered_map<int, int> mp;
  vector<int> tmp;
  int tmpTop;
  int next;
  for(int i=N-1; i>=0; i--) {
    unordered_map<int, int>::iterator itr = mp.find(A[i]);
    if(itr == mp.end()) {
      if(i == N-1)
        next = -1;
      else
        next = i+1;
      tmpTop = A[i];
    } else {
      if(itr->second == N-1) {
        next = -1;
        tmpTop = -1;
      } else {
        next = memo3[itr->second+1].second;
        tmpTop = memo3[itr->second+1].first;
      }
    }
    memo3[i].first = tmpTop;
    memo3[i].second = next;
    mp[A[i]] = i;
  }
  vector<int> memo2;
  set<int> s;
  int tmp2 = 0;
  while(s.find(tmp2) == s.end()) {
    memo2.push_back(tmp2);
    s.insert(tmp2);
    if(tmp2 == N || memo3[tmp2] == make_pair(-1, -1)) {
      tmp2 = 0;
    } else {
      tmp2 = mp[memo3[tmp2].first]+1;
    }
  }
  int k = memo2.size();
  K--;
  K %= k;
  if(memo2[K] == N)
    cout << endl;
  else {
    tmp2 = memo2[K];
    while(memo3[tmp2].second != -1) {
      cout << memo3[tmp2].first << ' ';
      tmp2 = memo3[tmp2].second;
    }
    if(memo3[tmp2].first != -1)
      cout << memo3[tmp2].first << ' ';
    cout << endl;
  }
  return 0;
}

