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
  int ans = 0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    ll tmp = A[i];
    while(tmp % 2 == 0){
      tmp /= 2;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

