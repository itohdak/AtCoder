#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int sub(int n, int m, int prev){// n : box, m : ball
  if(n == 1){
    return 1;
  } else {
    int ret = 0;
    for(int i=ceil(m*1.0/n); i<=min(prev, m); i++){
      ret += sub(n-1, m-i, i);
    }
    return ret;
  }
}

ll dp(const int sum, const vector<int>& cat){
  int ncat = cat.size();
  ll death2[ncat][sum+1];
  for(int i=0; i<ncat; i++){
    for(int j=0; j<sum+1; j++){
      if(i == 0)
	death2[i][j] = sub(cat[i], j, j);
      else
	death2[i][j] = 0;
    }
  }
  for(int i=1; i<ncat; i++){
    for(int j=0; j<sum+1; j++){
      for(int k=0; k<=j; k++){
	death2[i][j] += death2[i-1][j-k] * sub(cat[i], k, k);
      }
    }
  }
  return death2[ncat-1][sum];
}

int main(){
  int N, M;
  cin >> N >> M;
  int sumA = 0, sumB = 0;
  vector<int> catA, catB;
  int prev = -1;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    sumA += in;
    if(prev != in){
      catA.push_back(1);
    } else {
      catA[catA.size()-1]++;
    }
    prev = in;
  }
  prev = -1;
  for(int i=0; i<M; i++){
    int in;
    cin >> in;
    sumB += in;
    if(prev != in){
      catB.push_back(1);
    } else {
      catB[catB.size()-1]++;
    }
    prev = in;
  }
  cout << (dp(sumB, catA) * dp(sumA, catB)) % 1000000007 << endl;
  return 0;
}

