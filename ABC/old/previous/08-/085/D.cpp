#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll N, H;
  cin >> N >> H;
  vector<ll> A, B, B_greater;
  ll a_max = 0;
  ll b_sum = 0;
  for(int i=0; i<N; i++){
    ll a, b;
    cin >> a >> b;
    A.push_back(a);
    if(a_max < a)
      a_max = a;
    B.push_back(b);
    B_greater.push_back(b);
    b_sum += b;
  }
  sort(B_greater.begin(), B_greater.end(), greater<ll>());
  int it = 0;
  while(it < B_greater.size() && B_greater[it] > a_max){
    it++;
  }
  for(int i=it; i<B_greater.size(); i++){
    b_sum -= B_greater[i];
  }
  if(b_sum > H){
    int ret = 0;
    ll sum = 0;
    while(sum < H){
      sum += B_greater[ret];
      ret++;
    }
    cout << ret << endl;
  } else {
    H -= b_sum;
    cout << N-(B_greater.size()-it) + (ll)ceil((H / (double)a_max)) << endl;
  }
  return 0;
}

