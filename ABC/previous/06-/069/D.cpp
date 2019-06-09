#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  int H, W, N;
  cin >> H >> W >> N;
  int A[N];
  for(int i=0; i<N; i++)
    cin >> A[i];
  int ret[H][W];
  int row_t = 0;
  int col_t = 0;
  for(int i=0; i<N; i++){
    int num = A[i];
    while(num > 0){
      ret[row_t][col_t] = i + 1;
      if(row_t % 2 == 0){
	if(col_t == W - 1)
	  row_t++;
	else
	  col_t++;
      } else {
	if(col_t == 0)
	  row_t++;
	else
	  col_t--;
      }
      num--;
    }
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cout << ret[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}

