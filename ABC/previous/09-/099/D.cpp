#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, C;
  cin >> N >> C;
  vector< vector<int> > D(C, vector<int>(C));
  vector< vector<int> > Co(N, vector<int>(N));
  for(int i=0; i<C; i++)
    for(int j=0; j<C; j++)
      cin >> D[i][j];
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cin >> Co[i][j];
  vector<int> dp0(C, 0);
  vector<int> dp1(C, 0);
  vector<int> dp2(C, 0);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      for(int c=0; c<C; c++){
	if((i + j) % 3 == 0){
	  dp0[c] += D[Co[i][j]-1][c];
	} else if((i + j) % 3 == 1){
	  dp1[c] = dp1[c] + D[Co[i][j]-1][c];
	} else if((i + j) % 3 == 2){
	  dp2[c] = dp2[c] + D[Co[i][j]-1][c];
	}
      }
    }
  }
  int ans = 1000 * 500 * 500;
  for(int i=0; i<C; i++)
    for(int j=0; j<C; j++)
      if(i != j)
	for(int k=0; k<C; k++)
	  if(i != k && j != k)
	    ans = min(ans, dp0[i] + dp1[j] + dp2[k]);
  cout << ans << endl;
  return 0;
}

