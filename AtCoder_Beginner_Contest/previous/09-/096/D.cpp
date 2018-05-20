#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool is_prime(const unsigned n){
  switch(n){
  case 0: // fall-through
  case 1: return false;
  case 2: // fall-through
  case 3: return true;
  } // n > 3 が保証された

  if(n%2 == 0) return false;
  if(n%3 == 0) return false;
  // 2と3の倍数でないので6の倍数ではないことが保証された

  if(n%6 != 1 && n%6 != 5) return false;
  // 6の倍数前後の数(素数かもしれない数)であることが保証された

  // 6の倍数前後の数を使って試し割りをする
  for(unsigned i=5;i*i<=n;i+=6){
    if(n%i     == 0) return false; // 6n-1
    if(n%(i+2) == 0) return false; // 6n+1
  }

  return true;
}

int main(){
  int N;
  cin >> N;
  int tmp = 31;
  for(int i=0; i<N; i++){
    while(!is_prime(tmp))
      tmp += 30;
    cout << tmp << ' ';
    tmp += 30;
  }
  cout << endl;
  return 0;
}

