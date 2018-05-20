#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

#define N 100000
ll C[N];
void Calc(){
  C[0] = 1;
  for(int i=1; i<N; i++){
    C[i] = C[0] * i;
  }
}
ll Combination(int n, int m){
  if(n >= m){
    return C[n] / C[m] / C[n-m];
  } else {
    cout << "error n: " << n << " m: " << m << endl;
    return 0;
  }
}

int main(){
  Calc();
  int n;
  cin >> n;
  vector<int> A[n+1];
  int l, r;
  for(int i=0; i<n+1; i++){
    int in;
    cin >> in;
    if(A[in].size() != 0){
      l = A[in][0]; r = i+1;
    }
    A[in].push_back(i+1);
  }
  cout << l << ' ' << r << endl;
  for(int k=1; k<=n; k++){
    // n+1Ck - l-1+n-rCk-1
    cout << Combination(n+1, k) - Combination(l-1+n-r, k-1) << endl;
  }
  return 0;
}

