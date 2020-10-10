#include "header.hpp"

template <class S, S (*op)(S, S), S (*e)()> struct SparseTable {
public:
  SparseTable() : SparseTable(0) {}
  SparseTable(int n) : SparseTable(vector<vector<S>>(n, e())) {}
  SparseTable(const vector<vector<S>>& v) : h(int(v.size())), w(int(v[0].size())) {
    logH = logW = 1;
    while(1LL<<logH < h) logH++;
    while(1LL<<logW < w) logW++;
    init(v);
  }
  void init(const vector<vector<S>>& v) {
    d = vector<vector<vector<vector<S>>>>(logH, vector<vector<vector<S>>>(h, vector<vector<S>>(logW, vector<S>(w, e()))));
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) d[0][i][0][j] = v[i][j];
      for(int logj=1; logj<logW; logj++) {
        for(int j=0; j+(1<<(logj-1))<w; j++) {
          d[0][i][logj][j] = op(d[0][i][logj-1][j], d[0][i][logj-1][j+(1<<(logj-1))]);
        }
      }
    }
    for(int logi=1; logi<logH; logi++) {
      for(int i=0; i+(1<<(logi-1))<h; i++) {
        for(int logj=0; logj<logW; logj++) {
          for(int j=0; j<w; j++) {
            d[logi][i][logj][j] = op(d[logi-1][i][logj][j], d[logi-1][i+(1<<(logi-1))][logj][j]);
          }
        }
      }
    }
  }
  S query(int x1, int y1, int x2, int y2) {
    assert(x2-x1 != 0);
    assert(y2-y1 != 0);
    int lenX = x2-x1;
    int lenY = y2-y1;
    int logX = 0, logY = 0;
    while(1LL<<(logX+1) <= lenX) logX++;
    while(1LL<<(logY+1) <= lenY) logY++;
    S res1 = op(d[logX][x1][logY][y1], d[logX][x1][logY][y2-(1<<logY)]);
    S res2 = op(d[logX][x2-(1<<logX)][logY][y1], d[logX][x2-(1<<logX)][logY][y2-(1<<logY)]);
    return op(res1, res2);
  }
private:
  int h, w, size, logH, logW;
  vector<vector<vector<vector<S>>>> d;
};
int op(int a, int b) {
  return max(a, b);
}
int e() {
  return 0;
}
