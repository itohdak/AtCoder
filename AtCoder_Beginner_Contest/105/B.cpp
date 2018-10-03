#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  bool ok = false;
  for(int i=0; i<=N/7; i++){
    for(int j=0; j<=(N-i*7)/4; i++){
      if((N-i*7) % 4 == 0){
	ok = true;
	break;
      }
    }
    if(ok)
      break;
  }
  if(ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
	
  return 0;
}

