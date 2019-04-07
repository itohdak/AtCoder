#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <queue>

using namespace std;
#define ll long long

int main(){
  int N, K;
  cin >> N >> K;
  priority_queue<pair<ll, int>,
		 vector<pair<ll, int> >,
		 less<pair<ll, int> > > P; // candidates
  priority_queue<pair<ll, int>,
		 vector<pair<ll, int> >,
		 greater<pair<ll, int> > > Q; // selected
  for(int i=0; i<N; i++) {
    int t;
    ll d;
    cin >> t >> d;
    t--;
    P.push(make_pair(d, t));
  }
  ll value = 0LL;
  vector<int> selected(N, 0);
  ll nType = 0;
  for(int i=0; i<K; i++) {
    pair<ll, int> p = P.top();
    P.pop();
    value += p.first;
    if(selected[p.second] == 0)
      nType++;
    selected[p.second]++;
    Q.push(p);
  }
  ll ans = value + nType * nType;

  while(!P.empty()) {
    pair<ll, int> p = P.top();
    P.pop();
    if(selected[p.second] == 0) {
      pair<ll, int> q;
      while(!Q.empty()) {
	pair<ll, int> tmpQ = Q.top();
	Q.pop();
	if(selected[tmpQ.second] > 1) {
	  q = tmpQ;
	  break;
	}
      }
      if(q.first == 0) continue;
      value += p.first - q.first;
      nType++;
      selected[p.second]++;
      selected[q.second]--;
      Q.push(p);
      ans = max(ans, value + nType * nType);
    }
  }
  cout << ans << endl;
  return 0;
}

