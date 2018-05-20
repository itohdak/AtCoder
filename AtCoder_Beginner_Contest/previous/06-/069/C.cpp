#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  int mul4 = 0, mul2 = 0, mul1 = 0;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    if(in % 4 == 0) mul4++;
    else if(in % 2 == 0) mul2++;
    else mul1++;
  }

  if((N + 1) / 2 < mul1){
    cout << "No" << endl;
  } else if(N % 2 == 1 && (N + 1) / 2 == mul1){
    if(mul4 >= mul1 - 1)
      cout << "Yes" << endl;
  } else if(mul4 >= mul1){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}

