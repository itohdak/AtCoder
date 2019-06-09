#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void dp(const vector<int>::iterator &begin, const vector<int>::iterator &end, int x, int n){
  int size = end - begin;
  int intel[n][size];
  for(int i=0; i<n; i++)
    for(int j=0; j<size; j++)
      intel[i][j] = -1;

  for(int i=0; i<n; i++){
    for(int j=0; j<size; j++){
      if(i == 0){
	intel[i][j] = x;
      } else {
	for(int k=0; k<j; k++){
	  intel[i][j] = max(intel[i-1][k] + min(*(begin+j)-*(begin+k), x), intel[i][j]);
	}
      }
    }
  }

  // cout << endl;
  // for(int i=0; i<n; i++){
  //   for(int j=0; j<size; j++){
  //     cout << intel[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  for(int k=0; k<n; k++)
    cout << intel[k][size-1] << endl;
}

int main(){
  int N, X;
  cin >> N >> X;
  vector<int> T;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    T.push_back(in);
  }
  dp(T.begin(), T.end(), X, N);
  return 0;
}

