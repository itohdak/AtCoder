#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <utility>

using namespace std;
#define ll long long

bool comp(pair<ll, int> p1, pair<ll, int> p2) {
  return p1.first < p2.first;
}

int main(){
  vector<pair<ll, int> > p;
  int N, M;
  cin >> N >> M;
  for(int i=0; i<N; i++) {
    ll a;
    int b;
    cin >> a >> b;
    p.push_back(make_pair(a, b));
  }
  sort(p.begin(), p.end(), comp);
  ll ans = 0LL;
  int i = 0;
  while(M > 0) {
    ans += p[i].first * min(M, p[i].second);
    M -= min(M, p[i].second);
    i++;
  }
  cout << ans << endl;
  return 0;
}

