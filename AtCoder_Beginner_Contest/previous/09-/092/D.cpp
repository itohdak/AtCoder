#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

const int MAXN = 100;
char grid[MAXN+5][MAXN+5];

int main(){
  int A, B;
  cin >> A >> B;
  for(int i=0; i<MAXN/2; i++){
    for(int j=0; j<MAXN; j++){
      grid[i][j] = '.';
    }
  }
  for(int i=MAXN/2; i<MAXN; i++){
    for(int j=0; j<MAXN; j++){
      grid[i][j] = '#';
    }
  }
  A--, B--;
  for(int i=MAXN-1; A; i-=2){
    for(int j=0; j<MAXN && A; j+=2){
      grid[i][j] = '.';
      A--;
    }
  }
  for(int i=0; B; i+=2){
    for(int j=0; j<MAXN && B; j+=2){
      grid[i][j] = '#';
      B--;
    }
  }
  cout << MAXN << " " << MAXN << endl;
  for(int i=0; i<MAXN; i++){
    cout << grid[i] << endl;
  }
  cout << endl;
  return 0;
}
