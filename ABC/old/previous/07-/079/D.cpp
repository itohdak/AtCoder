#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  int C[10][10];
  for(int i=0; i<10; i++)
    for(int j=0; j<10; j++)
      cin >> C[i][j];
  int A[H][W];
  for(int i=0; i<H; i++)
    for(int j=0; j<W; j++)
      cin >> A[i][j];

  for(int w=0; w<10; w++)
    for(int u=0; u<10; u++)
      for(int v=0; v<10; v++)
	C[u][v] = min(C[u][v], C[u][w] + C[w][v]);

  int mp = 0;
  for(int i=0; i<H; i++)
    for(int j=0; j<W; j++)
      if (A[i][j] != -1)
	mp += C[A[i][j]][1];

  cout << mp << endl;

  return 0;
}

