#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <set>

using namespace std;
#define ll long long

struct data {
  ll time;
  bool start;
  ll x;
  data(ll t, bool start, ll x) : time(t), start(start), x(x) {}
};

bool comp(data d1, data d2) {
  if(d1.time == d2.time)
    return !(d1.start && !d2.start);
  else
    return d1.time < d2.time;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<ll> S(N), T(N), X(N);
  vector<data> A;
  for(int i=0; i<N; i++) {
    cin >> S[i] >> T[i] >> X[i];
    A.push_back(data(S[i]-X[i], true, X[i]));
    A.push_back(data(T[i]-X[i], false, X[i]));
  }
  sort(A.begin(), A.end(), comp);
  set<ll> Set;
  int tmp = 0;
  for(int i=0; i<Q; i++) {
    ll D;
    cin >> D;
    while(A[tmp].time <= D && tmp < A.size()) {
      if(A[tmp].start)
	Set.insert(A[tmp].x);
      else
	Set.erase(A[tmp].x);
      tmp++;
    }
    if(Set.empty())
      cout << -1 << endl;
    else
      cout << *Set.begin() << endl;
  }
  return 0;
}

