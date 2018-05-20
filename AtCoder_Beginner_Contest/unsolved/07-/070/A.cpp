#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> digits;
  while(N>0){
    int tmp = N % 10;
    digits.push_back(tmp);
    N /= 10;
  }
  int len = digits.size();
  bool ret = true;
  for(int i=0; i<len/2+1; i++){
    if(digits[i] != digits[len-i-1]){
      ret = false;
      break;
    }
  }
  if(ret)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

