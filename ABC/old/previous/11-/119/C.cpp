#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> L(N);
  for(int i=0; i<N; i++)
    cin >> L[i];
  int ans = 1000000;
  for(int i=0; i<pow(4,N); i++) {
    vector<int> As, Bs, Cs;
    int ii = i;
    for(int j=0; j<N; j++) {
      int jj = ii % 4;
      if(jj == 0)
	As.push_back(L[j]);
      else if(jj == 1)
	Bs.push_back(L[j]);
      else if(jj == 2)
	Cs.push_back(L[j]);
      ii /= 4;
    }
    if(As.size() != 0 && Bs.size() != 0 && Cs.size() != 0) {
      int tmp =
	abs(A - accumulate(As.begin(), As.end(), 0)) + 10 * (As.size() - 1) +
	abs(B - accumulate(Bs.begin(), Bs.end(), 0)) + 10 * (Bs.size() - 1) +
	abs(C - accumulate(Cs.begin(), Cs.end(), 0)) + 10 * (Cs.size() - 1);
      if(tmp < ans)
	ans = tmp;
    }
  }
  cout << ans << endl;
  return 0;
}

