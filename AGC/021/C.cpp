#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, M;
  int A, B;
  cin >> N >> M >> A >> B;
  char map[N][M];
  int c = 0, r = 0;
  while(A > 0){
    map[c][r] = '<';
    map[c][r+1] = '>';
    if(c == N){
      c = 0; r += 2;
    } else {
      c++;
    }
    A--;
  }
  while(B > 0){
    if(c+1 < N);
    map[c][r] = '^';
    map[c+1][r] = 'v';
    B--;
  }
  return 0;
}

