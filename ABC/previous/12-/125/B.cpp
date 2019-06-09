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
  cin >> N;
  vector<int> V(N), C(N);
  for(int i=0; i<N; i++)
    cin >> V[i];
  for(int i=0; i<N; i++)
    cin >> C[i];
  int ans = 0;
  for(int i=0; i<N; i++)
    if(V[i] > C[i])
      ans += V[i] - C[i];
  cout << ans << endl;
  return 0;
}

