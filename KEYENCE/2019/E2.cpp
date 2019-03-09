#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct edge {
  int from;
  int to;
  ll cost;
  edge(int f, int t, ll c) : from(f), to(t), cost(c){};
};

int main(){
  int N;
  ll D;
  vector<edge> E;
  cin >> N >> D;
  vector<ll> A(N);
  vector<ll> left(N, 0);
  vector<ll> right(N, 0);
  vector<ll> minl(N, 0);
  vector<ll> minr(N, 0);
  for(int i=0; i<N; i++) {
    cin >> A[i];
    left[i] = A[i] - i * D;
    right[i] = A[i] + i * D;
  }
  for(int i=0; i<N; i++) {
    if(i == 0)
      minl[0] = left[i];
    minl[i] = min(minl[i-1], left[i]);
  }
  for(int i=N-1; i>=0; i--) {
    if(i == N-1)
      minr[N-1] = right[i];
    minr[i] = min(minr[i+1], right[i]);
  }

  ll ans = 0;
  ll M = 0;
  for(int i=0; i<N; i++) {
    ll trgt = min(A[i] + i * D + left[i-1], A[i] - i * D + right[i+1]);
    cout << trgt << endl;
    if(M < trgt)
      M = trgt;
    ans += trgt;
  }
  cout << ans - M << endl;
  return 0;
}

