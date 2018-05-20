#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  int digit;
  digit = floor(log10(N)) + 1;
  int sum = 0;
  for(int i=0; i<digit; i++){
    sum += (int)(N / pow(10, i)) % 10;
  }
  if(N % sum == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

