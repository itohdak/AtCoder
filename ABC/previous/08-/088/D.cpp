#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct pass{
  int src;
  int dst;
};

int main(){
  int H, W;
  cin >> H >> W;

  int C[H*W];
  for(int i=0; i<H*W; i++){
    if(i == 0)
      C[i] = 0;
    else
      C[i] = H*W+1;
  }

  vector<pass> P;

  int S[H][W];
  int n_white = 0;
  for(int i=0; i<H; i++){
    string in;
    cin >> in;
    for(int j=0; j<W; j++){
      if(in[j] == '#')
	S[i][j] = 0;
      else{
	S[i][j] = 1;
	n_white++;
      }
      if(!(i == 0 && j == 0)){
	if(!(i == 0)){
	  if(S[i][j] == 1 && S[i-1][j] == 1){
	    pass p1 = {i*W+j, (i-1)*W+j};
	    pass p2 = {(i-1)*W+j, i*W+j};
	    P.push_back(p1); P.push_back(p2);
	  }
	}
	if(!(j == 0)){
	  if(S[i][j] == 1 && S[i][j-1] == 1){
	    pass p1 = {i*W+j, i*W+(j-1)};
	    pass p2 = {i*W+(j-1), i*W+j};
	    P.push_back(p1); P.push_back(p2);
	  }
	}
      }
    }
  }

  for(int i=0; i<H*W; i++){
    for(int j=0; j<P.size(); j++){
      int s = P[j].src;
      int d = P[j].dst;
      if(C[d] > C[s] + 1)
	C[d] = C[s] + 1;
    }
  }

  if(C[H*W-1] == H*W+1)
    cout << -1 << endl;
  else
    cout << n_white - (C[H*W-1] + 1) << endl;

  return 0;
}
