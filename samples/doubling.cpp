#include "header.hpp"

class Doubling {
public:
  int N;
  int logK;
  vector<vector<int>> next;

  Doubling(int N, vector<int>& ini, ll K) {
    logK = log2(K);
    next = vector<vector<int>>(logK+1, vector<int>(N));
    rep(i, N) next[0][i] = ini[i];
    rep(k, logK) {
      rep(i, N) {
        next[k+1][i] = (next[k][i] == -1 ? -1 : next[k][next[k][i]]);
      }
    }
  }

  int query(int p, ll q) {
    for(int k=logK; k>=0; k--) {
      if(p == -1) break;
      if((q>>k)&1) p = next[k][p];
    }
    return p;
  }
};

class DoublingVal {
public:
  int N;
  int logK;
  vector<vector<pair<int, ll>>> next;

  DoublingVal(int N, vector<int>& ini, vector<ll>& A, ll K) {
    logK = log2(K);
    next = vector<vector<pair<int, ll>>>(logK+1, vector<pair<int, ll>>(N));
    rep(i, N) {
      next[0][i].first = ini[i];
      next[0][i].second = A[i];
    }
    rep(k, logK) {
      rep(i, N) {
        next[k+1][i].first = next[k][next[k][i].first].first;
        next[k+1][i].second = next[k][i].second + next[k][next[k][i].first].second;
      }
    }
  }

  pair<int, ll> query(int p, ll q) {
    ll sum = 0;
    for(int k=logK; k>=0; k--) {
      if(p == -1) break;
      if((q>>k)&1) {
        sum += next[k][p].second;
        p = next[k][p].first;
      }
    }
    return make_pair(p, sum);
  }
};
