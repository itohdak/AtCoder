#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool A[100][100];

int main(){
  int W, H, N;
  cin >> W >> H >> N;
  for(int i=0; i<N; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    if(a == 1) {
      for(int p=0; p<x; p++)
	for(int q=0; q<H; q++)
	  A[p][q] = true;
    } else if(a == 2) {
      for(int p=x; p<W; p++)
	for(int q=0; q<H; q++)
	  A[p][q] = true;
    } else if(a == 3) {
      for(int p=0; p<W; p++)
	for(int q=0; q<y; q++)
	  A[p][q] = true;
    } else if(a == 4) {
      for(int p=0; p<W; p++)
	for(int q=y; q<H; q++)
	  A[p][q] = true;
    }
  }
  int count = 0;
  for(int p=0; p<W; p++)
    for(int q=0; q<H; q++)
      if(!A[p][q])
	count++;
  cout << count << endl;
  return 0;
}

