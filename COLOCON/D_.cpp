#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void dp(const vector<int>::iterator &begin, const vector<int>::iterator &end, int x, int n){
  int i2j_list[n];
  for(int i=0; i<n; i++){
    int j = i;
    while(*(begin+i) + x > *(begin+j) && j < n-1) j++;
    i2j_list[i] = j;
  }
  int intel[n][n]; // iteration, data_number
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i == 0) intel[i][j] = x;
      else intel[i][j] = 0;
    }
  }
  for(int k=0; k<n-1; k++){
    for(int i=0; i<n; i++){
      int j = i2j_list[i];
      intel[k+1][j-1] = max(intel[k][i] + min(*(begin+j-1)-*(begin+i), x), intel[k+1][j-1]);
      intel[k+1][j] = max(intel[k][i] + min(*(begin+j)-*(begin+i), x), intel[k+1][j]);
      intel[k+1][n-1] = max(intel[k][i] + min(*(begin+n-1)-*(begin+i), x), intel[k+1][n-1]);
    }
  }
  for(int k=0; k<n; k++)
    cout << intel[k][n-1] << endl;
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
