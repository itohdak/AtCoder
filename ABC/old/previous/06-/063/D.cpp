#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll calc_rest_time(ll N, ll A, ll B, const vector<ll> &H, int t){
  ll sub = A - B;
  ll ret = 0;
  for(int i=0; i<N; i++)
    if(H[i] - t * B > 0)
      ret += (ll)ceil(1.0 * (H[i] - t * B) / sub);
  return ret;
}

int main(){
  int N;
  ll A, B;
  cin >> N >> A >> B;
  vector<ll> H(N);
  for(int i=0; i<N; i++)
    cin >> H[i];
  sort(H.begin(), H.end());
  int low = 0, high = (int)ceil(1.0 * H[N-1] / B);
  while(low < high){
    int mid = (low + high) / 2;
    if(calc_rest_time(N, A, B, H, mid) <= mid)
      high = mid;
    else
      low = mid + 1;
  }
  cout << high << endl;
  return 0;
}

