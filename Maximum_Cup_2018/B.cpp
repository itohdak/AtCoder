#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool C[15][15];
bool R[15][15][15][15][4];

int main(){
  int a, b, h, w;
  cin >> a >> b >> h >> w;
  for(int i=0; i<w; i++){
    for(int j=0; j<h; j++){
      char in;
      cin >> in;
      if(in == '.'){
	C[j][i] = true;
      } else if (in == '#'){
	C[j][i] = false;
      }
    }
  }
  R[1][1][0][0][2] = true;

  return 0;
}

