#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  ll Z, W;
  cin >> Z >> W;
  vector<ll> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  if(N == 1)
    cout << abs(A[0] - W) << endl;
  else
    cout << max(abs(A[N-1] - W), abs(A[N-2] - A[N-1])) << endl;
  return 0;
}

