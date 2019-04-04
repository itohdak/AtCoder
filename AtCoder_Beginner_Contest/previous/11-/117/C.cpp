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
  vector<int> X(M);
  vector<int> D(M-1);
  for(int i=0; i<M; i++)
    cin >> X[i];
  sort(X.begin(), X.end());
  for(int i=1; i<M; i++)
    D[i-1] = X[i] - X[i-1];
  sort(D.begin(), D.end());
  if(N >= M)
    cout << 0 << endl;
  else
    cout << accumulate(D.begin(), D.begin() + M - N, 0) << endl;
  return 0;
}

