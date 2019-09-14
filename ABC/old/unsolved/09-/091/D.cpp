#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

#define MAX 28
#define NMAX 200000

vector<ll> A(NMAX, 0);
vector<ll> B(NMAX, 0);
vector<ll> Bmod(NMAX, 0);

int binary_search(int n, int target){
  int left = 0;
  int right = n-1;
  int mid;

  while(left <= right){
    mid = (left + right) / 2;
    if(Bmod[mid] <= target){
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left;
}

int main(){
  int N;
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> A[i];
  for(int i=0; i<N; i++)
    cin >> B[i];
  sort(B.begin(), B.begin()+N);
  ll ans = 0;
  for(int k=0; k<28; k++){
    for(int i=0; i<N; i++){
      ll a = A[i];
      ll T = (1 << k);
      ll amod = a % T;
      for(int i=0; i<N; i++)
	Bmod[i] = B[i] % T;
      int t1 = binary_search(N, T-a);
      int t2 = binary_search(N, 2*T-a);
      int t3 = binary_search(N, 3*T-a);
      int t4 = binary_search(N, 4*T-a);
      if(k == 0){
	cout << a << endl;
	cout << t1 << t2 << t3 << t4 << endl;
      }
      if((t2 - t1 + t4 - t3) % 2 == 1)
	ans += (1 << k);
    }
  }
  cout << ans << endl;
  return 0;
}
