#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> A(M);
  vector<int> B(M);
  for(int i=0; i<M; i++)
    cin >> B[i];
  int ans = 0;
  for(int i=0; i<N; i++) {
    int tmp = C;
    for(int i=0; i<M; i++) {
      cin >> A[i];
      tmp += A[i] * B[i];
    }
    if(tmp > 0) ans++;
  }
  cout << ans << endl;
  return 0;
}

