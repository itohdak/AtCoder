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
  vector<ll> A;
  ll ret = 0;
  ll ret_sub = 0;
  ll start = 0;
  ll end = 0;
  bool ok = true;
  for(int i=0; i<N; i++){
    ll in;
    cin >> in;
    A.push_back(in);
    ret += in;

    if((i == 0 && in != 0) ||
       (i != 0 && A[i-1] + 1 < in))
      ok = false;

    if(ok){
      if(in == end + 1){
	end = in;
      } else {
	ret_sub += (start + end - 1) * (end - start) / 2;
	start = end = in;
      }

      if(i == N-1){
	ret_sub += (start + end - 1) * (end - start) / 2;
	start = end = in;
      }
    }
  }

  if(ok)
    cout << ret - ret_sub << endl;
  else
    cout << -1 << endl;

  return 0;
}

