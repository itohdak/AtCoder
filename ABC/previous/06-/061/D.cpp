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
  vector<int> A(M), B(M);
  vector<ll> C(M);
  for(int i=0; i<M; i++){
    cin >> A[i] >> B[i] >> C[i];
    A[i]--; B[i]--;
  }
  vector<ll> V(N);
  for(int i=0; i<N; i++)
    if(i == 0)
      V[i] = 0;
    else
      V[i] = -(1LL << 50);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      int src = A[j];
      int dst = B[j];
      if(V[dst] < V[src] + C[j])
	V[dst] = V[src] + C[j];
    }
  }
  // for(int i=0; i<N; i++)
  //   cout << V[i] << ' ';
  // cout << endl;

  vector<bool> ok(N, true);
  for(int j=0; j<M; j++){
    int src = A[j];
    int dst = B[j];
    if(V[src] + C[j] > V[dst])
      ok[dst] = false;
    if(!ok[src])
      ok[dst] = false;
  }

  if(ok[N-1])
    cout << V[N-1] << endl;
  else
    cout << "inf" << endl;
  return 0;
}

