#include "header.hpp"

// i番目のビットを取り出す
int getBit(ll num, int i) {
  return ((num & (1 << i)) != 0);
}

// i番目のビットに1を立てる
ll setBit(ll num, int i) {
  return num | (1 << i);
}

// i番目のビットを0にする
ll clearBit(ll num, int i) {
  int mask = ~(1 << i);
  return num & mask;
}
