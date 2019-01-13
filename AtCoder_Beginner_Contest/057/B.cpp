#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, M;
  cin >> N >> M;
  vector<ll> A(N), B(N);
  vector<ll> C(M), D(M);
  for(int i=0; i<N; i++)
    cin >> A[i] >> B[i];
  for(int i=0; i<M; i++)
    cin >> C[i] >> D[i];
  for(int i=0; i<N; i++) {
    ll dis = 1000000000;
    int ans = 0;
    for(int j=0; j<M; j++) {
      if(dis > abs(C[j] - A[i]) + abs(D[j] - B[i])) {
	dis = abs(C[j] - A[i]) + abs(D[j] - B[i]);
	ans = j+1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

