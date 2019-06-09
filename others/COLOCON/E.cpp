#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void print(long long x, long long y){
  cout << x << ' ' << y << endl;
}

int main(){
  long long K;
  cin >> K;
  K--;
  long long x = -999999999;
  long long y = -999999999;
  long long k = K % 2000000000;
  if(K <= 2000000000){
    cout << 2 * K + 2 << endl;
    print(x, y);
    y += K;
    print(x, y);
    x++;
    print(x, y);
    bool plus = false;
    for(int i=0; i<K-1; i++){
      y--;
      print(x, y);
      if(plus){
	x += 2;
	plus = false;
      } else {
	x -= 2;
	plus = true;
      }
      print(x, y);
    }
    y--;
    print(x, y);
  } else {
    cout << 0 << endl;
  }
  return 0;
}

