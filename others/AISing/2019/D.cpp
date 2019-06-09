#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, Q;
  cin >> N >> Q;
  vector<ll> A(N), S(N, 0), E(N, 0), O(N, 0);
  ll sum = 0L;
  ll even = 0L, odd = 0L;
  for(int i=0; i<N; i++) {
    cin >> A[i];
    sum += A[i];
    if(i % 2 == 0)
      even += A[i];
    else
      odd += A[i];
    S[i] = sum;
    E[i] = even;
    O[i] = odd;
  }
  for(int i=0; i<Q; i++) {
    ll x;
    cin >> x;
    // int ix = 0;
    // while(ix < N && A[ix] < x)
    //   ix++;
    int r, l;
    int lb = N-floor(N/2.0), hb = N-1;
    while(lb < hb) {
      int mid = (lb + hb) / 2;
      r = N - mid - 1;
      l = r - mid;
      // if(l < 0)
      // 	break;
      if(A[r] - x < x - A[l]) {
	lb = mid+1;
      } else {
	hb = mid;
      }
    }
    cout << lb << endl;
    // for(int m=1; A[N-m]>=x && 2*m<N; m++) {
    //   r = N - m - 1;
    //   l = r - m;
    //   if(l < 0)
    // 	break;
    //   if(A[r] - x < x - A[l]) { // && A[l+1] - x < x - A[ix]
    // 	// cout << endl << l << ' ' << r << ' ' << m << endl;
    // 	break;
    //   }
    // }
    if(l < 0) {
      cout << S[N-1] - S[N/2-1] << endl;
    } else {
      if(l % 2 == 0)
	cout << S[N-1] - S[r] + E[l] << endl;
      else
	cout << S[N-1] - S[r] + O[l] << endl;
    }
  }
  // for(int i=0; i<N; i++)
  //   cout << A[i] << ' ' << S[i] << ' ' << E[i] << ' ' << O[i] << endl;
  return 0;
}

