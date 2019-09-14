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
  vector<string> W(N);
  bool ret = true;
  for(int i=0; i<N; i++) {
    cin >> W[i];
    if(ret && i != 0) {
      if(W[i][0] != W[i-1][W[i-1].size()-1] ||
	 find(W.begin(), W.begin()+i, W[i]) != W.begin()+i) {
	ret = false;
      }
    }
  }
  if(ret)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

