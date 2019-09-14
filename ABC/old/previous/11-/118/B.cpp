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
  vector<int> result(M, 0);
  for(int i=0; i<N; i++) {
    int K;
    cin >> K;
    for(int j=0; j<K; j++) {
      int A;
      cin >> A;
      result[A-1]++;
    }
  }
  int ans = 0;
  for(int i=0; i<M; i++)
    if(result[i] == N)
      ans++;
  cout << ans << endl;
  return 0;
}

