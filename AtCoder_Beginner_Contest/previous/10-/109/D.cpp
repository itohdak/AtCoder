#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int A[500][500];
struct data {
  int x;
  int y;
  int x_;
  int y_;
  data(int x, int y, int x_, int y_) : x(x), y(y), x_(x_), y_(y_) {}
};

int main(){
  int H, W;
  cin >> H >> W;
  vector<data> D;
  for(int i=0; i<H; i++)
    for(int j=0; j<W; j++)
      cin >> A[i][j];
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      if(A[i][j] % 2 == 1) {
	A[i][j]--;
	if(j == W-1) {
	  if(i != H-1) {
	    D.push_back(data(i+1, j+1, i+2, j+1));
	    A[i+1][j]++;
	  }
	} else {
	  D.push_back(data(i+1, j+1, i+1, j+2));
	  A[i][j+1]++;
	}
      }
    }
  }
  cout << D.size() << endl;
  for(int i=0; i<D.size(); i++)
    cout << D[i].x << ' ' << D[i].y << ' ' << D[i].x_ << ' ' << D[i].y_ << endl;
  return 0;
}

