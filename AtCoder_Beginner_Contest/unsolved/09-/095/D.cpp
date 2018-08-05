#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  ll C;
  cin >> N >> C;
  vector<ll> X(N+1, 0), V(N);
  for(int i=0; i<N; i++)
    cin >> X[i+1] >> V[i];
  vector<ll> sum(N+1, 0);
  sum[0] = 0;
  for(int i=1; i<=N; i++)
    sum[i] = sum[i-1] + V[i-1];
  vector<ll> F(N+1, 0);
  for(int i=0; i<=N; i++)
    F[i] = sum[i] - X[i];
  vector<ll> G(N+1, 0);
  vector<ll> Gpos(N+1, 0);
  G[0] = 0;
  Gpos[0] = 0;
  G[1] = 0;
  Gpos[1] = 0;
  for(int j=2; j<=N; j++)
    if(G[j-1] < F[j-1]){
      G[j] = F[j-1];
      Gpos[j] = j-1;
    } else {
      G[j] = G[j-1];
      Gpos[j] = Gpos[j-1];
    }
  ll ans = 0;
  for(int j=1; j<=N; j++){
    ll tmp = sum[N] - sum[j-1] - (C - X[j]) + G[j] - min(C - X[j], X[Gpos[j]]);
    if(tmp > ans){
      ans = tmp;
    }
    ll tmp2 = sum[j] - X[j];
    if(tmp2 > ans){
      ans = tmp2;
    }
  }
  // for(int i=0; i<=N; i++){
  //   for(int j=i; j<=N; j++){
  //     ll tmp = 0;
  //     if(i == 0){
  // 	if(j == 0){
  // 	  tmp = 0;
  // 	} else {
  // 	  tmp = max(sum[j] - X[j], (sum[N] - sum[j-1]) - (C - X[j]));
  // 	}
  //     } else if(i != j){
  // 	tmp = (sum[N] - sum[j-1] + sum[i]) - (C - X[j] + X[i]) - min(C - X[j], X[i]);
  //     }
  //     if(tmp > ans){
  // 	ans = tmp;
  // 	// cout << i << ' ' << j << endl;
  //     }
  //   }
  // }
  cout << ans << endl;
  return 0;
}

