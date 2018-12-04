#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<ll> > s(N, vector<ll>(N));
  vector<vector<ll> > c(N, vector<ll>(N));
  for(int i=0; i<M; i++) {
    int L, R;
    cin >> L >> R;
    L--; R--;
    s[L][R]++;
  }
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      if(j == 0)
	c[i][j] = s[i][j];
      else
	c[i][j] = c[i][j-1] + s[i][j];

  for(int a=0; a<Q; a++) {
    int p, q;
    cin >> p >> q;
    p--; q--;

    int count = 0;
    for(int i=p; i<=q; i++) {
      if(p == 0)
	count += c[i][q];
      else
	count += c[i][q] - c[i][p-1];
    }
    cout << count << endl;
  }

  return 0;
}

