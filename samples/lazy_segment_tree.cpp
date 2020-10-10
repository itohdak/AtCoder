#include "header.hpp"

struct lazy_segment_tree{
  int N;
  vector<int> count;
  vector<ll> sum;
  vector<ll> sqsum;
  vector<ll> lazy;
  lazy_segment_tree(vector<ll> &A){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    count = vector<int>(N * 2 - 1, 1);
    sum = vector<ll>(N * 2 - 1, 0);
    sqsum = vector<ll>(N * 2 - 1, 0);
    lazy = vector<ll>(N * 2 - 1, 0);
    for (int i = 0; i < n; i++){
      sum[N - 1 + i] = A[i];
      sqsum[N - 1 + i] = A[i] * A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      count[i] = count[i * 2 + 1] + count[i * 2 + 2];
      sum[i] = sum[i * 2 + 1] + sum[i * 2 + 2];
      sqsum[i] = sqsum[i * 2 + 1] + sqsum[i * 2 + 2];
    }
  }
  void eval(int i){
    if (i < N - 1){
      lazy[i * 2 + 1] += lazy[i];
      lazy[i * 2 + 2] += lazy[i];
    }
    sqsum[i] = sqsum[i] + 2 * sum[i] * lazy[i] + count[i] * lazy[i] * lazy[i];
    sum[i] = sum[i] + count[i] * lazy[i];
    lazy[i] = 0;
  }
  void range_add(int L, int R, int x, int i, int l, int r){
    eval(i);
    if (R <= l || r <= L){
      return;
    } else if (L <= l && r <= R){
      lazy[i] += x;
      eval(i);
    } else {
      int m = (l + r) / 2;
      range_add(L, R, x, i * 2 + 1, l, m);
      range_add(L, R, x, i * 2 + 2, m, r);
      sum[i] = sum[i * 2 + 1] + sum[i * 2 + 2];
      sqsum[i] = sqsum[i * 2 + 1] + sqsum[i * 2 + 2];
    }
  }
  void range_add(int L, int R, int x){
    range_add(L, R, x, 0, 0, N);
  }
  ll range_sqsum(int L, int R, int i, int l, int r){
    eval(i);
    if (R <= l || r <= L){
      return 0;
    } else if (L <= l && r <= R){
      return sqsum[i];
    } else {
      int m = (l + r) / 2;
      return range_sqsum(L, R, i * 2 + 1, l, m) + range_sqsum(L, R, i * 2 + 2, m, r);
    }
  }
  ll range_sqsum(int L, int R){
    return range_sqsum(L, R, 0, 0, N);
  }
};
