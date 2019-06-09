#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct data {
  string name;
  int point;
  int index;
  data(string S, int P, int i) : name(S), point(P), index(i) {}
};
bool comp(data d1, data d2) {
  if(d1.name == d2.name)
    return d1.point > d2.point;
  else
    return d1.name < d2.name;
}

int main() {
  int N;
  cin >> N;
  vector<data> D;
  for(int i=0; i<N; i++) {
    string S; int P;
    cin >> S >> P;
    D.push_back(data(S, P, i+1));
  }
  sort(D.begin(), D.end(), comp);
  for(int i=0; i<N; i++)
    cout << D[i].index << endl;
  return 0;
}

