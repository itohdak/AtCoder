#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  int max_x = X;
  int min_y = Y;
  for(int i=0; i<N; i++) {
    int x;
    cin >> x;
    if(x > max_x)
      max_x = x;
  }
  for(int i=0; i<M; i++) {
    int y;
    cin >> y;
    if(y < min_y)
      min_y = y;
  }
  if(max_x < min_y)
    cout << "No War" << endl;
  else
    cout << "War" << endl;
  return 0;
}

