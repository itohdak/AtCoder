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
  vector<ll> A(N);
  vector<ll> B(M);
  vector<bool> Aex(N);
  vector<bool> Bex(N);
  bool ok = true;
  for(int i=0; i<N; i++) {
    cin >> A[i];
    if(Aex[A[i]-1] == true)
      ok = false;
    Aex[A[i]-1] = true;
  }
  for(int i=0; i<M; i++) {
    cin >> B[i];
    if(Bex[B[i]-1] == true)
      ok = false;
    Bex[B[i]-1] = true;
  }

  if(!ok) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
  return 0;
}

