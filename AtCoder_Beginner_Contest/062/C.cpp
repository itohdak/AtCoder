#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll H, W;
  cin >> H >> W;
  ll m = H * W;
  m = min(m, min(1LL, (H % 3)) * W); // 横に分ける
  m = min(m, min(1LL, (W % 3)) * H); // 縦に分ける
  ll a, b, c;
  switch(H % 2){
  case 0:
    switch(W % 3){
    case 0:
      m = min(m, 0LL);
      break;
    case 1:
      m = min(m, H / 2);
      break;
    case 2:
      m = min(m, H / 2);
      break;
    }
    break;
  case 1:
    switch(W % 3){
    case 0:
      m = min(m, W / 3 * 2);
      break;
    case 1:
      a = W / 3 * 2 + H / 2 + 1;
      b = H / 2;
      c = W / 3;
      m = min(m, max(a - b, a - c));

      a = W / 3 * 2;
      b = 0;
      c = W / 3 + H;
      m = min(m, max(c - b, a - b));
      break;
    case 2:
      a = W / 3 * 2 + H / 2 * 2 + 2;
      b = H / 2 * 2;
      c = W / 3;
      m = min(m, max(abs(a - b), max(abs(a - c), abs(b - c))));

      a = W / 3 * 2 + H / 2 + 1;
      b = H / 2;
      c = W / 3 + H;
      m = min(m, max(abs(a - b), max(abs(a - c), abs(b - c))));

      a = W / 3 * 2;
      b = 0;
      c = W / 3 + H * 2;
      m = min(m, max(abs(a - b), max(abs(a - c), abs(b - c))));
      break;
    }
    break;
  }
  switch(W % 2){
  case 0:
    switch(H % 3){
    case 0:
      m = min(m, 0LL);
      break;
    case 1:
      m = min(m, W / 2);
      break;
    case 2:
      m = min(m, W / 2);
      break;
    }
    break;
  case 1:
    switch(H % 3){
    case 0:
      m = min(m, H / 3 * 2);
      break;
    case 1:
      a = H / 3 * 2 + W / 2 + 1;
      b = W / 2;
      c = H / 3;
      m = min(m, max(a - b, a - c));

      a = H / 3 * 2;
      b = 0;
      c = H / 3 + W;
      m = min(m, max(c - b, a - b));
      break;
    case 2:
      a = H / 3 * 2 + W / 2 * 2 + 2;
      b = W / 2 * 2;
      c = H / 3;
      m = min(m, max(abs(a - b), max(abs(a - c), abs(b - c))));

      a = H / 3 * 2 + W / 2 + 1;
      b = W / 2;
      c = H / 3 + W;
      m = min(m, max(abs(a - b), max(abs(a - c), abs(b - c))));

      a = H / 3 * 2;
      b = 0;
      c = H / 3 + W * 2;
      m = min(m, max(abs(a - b), max(abs(a - c), abs(b - c))));
      break;
    }
    break;
  }
  cout << m << endl;
  return 0;
}

