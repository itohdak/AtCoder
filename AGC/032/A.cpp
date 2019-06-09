#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

vector<int> res;
bool bfs(vector<int> B, vector<int> C) {
  vector<bool> done(B.size(), false);
  for(int n=0; n<B.size(); n++) {
    // for(int i=0; i<C.size(); i++)
    //   cout << C[i] << ' ';
    // cout << endl;

    for(int i=B.size()-1; i>=0; i--) {
      if(!done[i]) {
	if(C[i] > 0) {
	  C[i]--;
	} else if(C[i] == 0) {
	  res.push_back(B[i]);
	  // cout << i+1 << ' ' << B[i] << endl;
	  done[i] = true;
	  break;
	} else {
	  return false;
	}
      }
    }
  }

  for(int i=0; i<C.size(); i++) {
    if(!done[i])
      return false;
  }
  return true;
}

int main(){
  int N;
  cin >> N;
  vector<int> B(N), C(N);
  for(int i=0; i<N; i++) {
    cin >> B[i];
    C[i] = (i+1) - B[i];
  }

  if(bfs(B, C)) {
    for(int i=res.size()-1; i>=0; i--)
      cout << res[i] << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}

