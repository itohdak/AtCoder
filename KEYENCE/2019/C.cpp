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
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> D;
  int ans = 0;
  ll minus = 0;
  ll sumA = 0;
  ll sumB = 0;
  for(int i=0; i<N; i++) {
    cin >> A[i];
    sumA += A[i];
  }
  for(int i=0; i<N; i++) {
    cin >> B[i];
    sumB += B[i];
    if(A[i] < B[i]) {
      ans++;
      minus += B[i] - A[i];
    } else if(A[i] > B[i]) {
      D.push_back(A[i] - B[i]);
    }
  }
  if(sumA < sumB) {
    cout << -1 << endl;
  } else {
    sort(D.begin(), D.end(), greater<ll>());
    int i = 0;
    while(minus > 0) {
      ans++;
      minus -= D[i];
      i++;
    }
    cout << ans << endl;
  }
  return 0;
}

