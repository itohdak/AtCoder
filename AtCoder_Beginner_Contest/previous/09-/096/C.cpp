#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int H, W;
  cin >> H >> W;
  bool S[H][W];
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      char in;
      cin >> in;
      if(in == '#')
	S[i][j] = true;
      else
	S[i][j] = false;
    }
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(S[i][j]){
	bool ok = false;
	if(i > 0)
	  if(S[i-1][j])
	    ok = true;
	if(i < H-1)
	  if(S[i+1][j])
	    ok = true;
	if(j > 0)
	  if(S[i][j-1])
	    ok = true;
	if(j < W-1)
	  if(S[i][j+1])
	    ok = true;
	if(!ok){
	  cout << "No" << endl;
	  return 0;
	}
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}

