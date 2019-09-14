#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll w[200];
ll v[200];

ll sum = 0;
ll M = 0;
ll W;
ll w0;
vector<vector<ll> > A(4, vector<ll>(0));
void calc(int n=0, ll tmp=0LL, ll tmp_w=W, ll w0=w0) {
  if(n == 4) {
    if(tmp > M)
      M = tmp;
    return;
  } else {
    for(int i=0; i<=min((int)(tmp_w/(w0+n)), (int)A[n].size()); i++) {
      calc(n+1, tmp+accumulate(A[n].begin(), A[n].begin()+i, 0LL),
	   tmp_w-(w0+n)*i, w0);
    }
  }
}

int main(){
  int N;
  cin >> N >> W;
  for(int i=0; i<N; i++) {
    cin >> w[i] >> v[i];
    if(i == 0) {
      w0 = w[0];
      A[0].push_back(v[0]);
    } else {
      A[w[i]-w0].push_back(v[i]);
    }
  }
  for(int i=0; i<4; i++)
    sort(A[i].begin(), A[i].end(), greater<ll>());
  calc();
  cout << M << endl;
  return 0;
}

