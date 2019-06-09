#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <map>

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<int> S(N), C(N);
  for(int i=0; i<N; i++) {
    cin >> S[i] >> C[i];
    S[i]--;
  }
  int s;
  ll K;
  cin >> s >> K;
  s--;
  int cnt = 0;
  int tmp = s;
  ll ans = 0;
  map<int, pair<ll, int> > cost;
  bool loop_detected = false;
  while(K > 0) {
    if(!loop_detected) {
      map<int, pair<ll, int> >::iterator itr = cost.find(tmp);
      if(itr != cost.end()) {
	ll cost = itr->second.first;
	int count = itr->second.second;
	int loop_count = cnt - count;
	ll loop_cost = ans - cost;
	ans += loop_cost * (K / loop_count);
	K %= loop_count;
	loop_detected = true;
	// cout << "loop detected! " << tmp << endl;
	// cout << loop_count << " " << loop_cost << endl;
	if(K == 0) break;
      }
    }
    cost.insert(make_pair(tmp, make_pair(ans, cnt)));
    int next = S[tmp];
    ans += C[tmp];
    // cout << tmp << endl;
    tmp = next;
    cnt++;
    K--;
  }
  cout << ans << endl;
  return 0;
}

