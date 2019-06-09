#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include<iomanip>

using namespace std;
#define ll long long

double calcDistance(pair<int, int> d1, pair<int, int> d2) {
  return sqrt(pow(d1.first-d2.first, 2) + pow(d1.second-d2.second, 2));
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<pair<int, int> > X, Xm;
  vector<int> R(N);
  for(int i=0; i<N; i++) {
    int x, y;
    cin >> x >> y;
    X.push_back(make_pair(x, y));
    cin >> R[i];
  }
  for(int i=0; i<M; i++) {
    int x, y;
    cin >> x >> y;
    Xm.push_back(make_pair(x, y));
  }
  vector<double> minX(M, 500);
  for(int i=0; i<M; i++) {
    for(int j=0; j<N; j++) {
      minX[i] = min(minX[i], calcDistance(Xm[i], X[j]) - R[j]);
    }
  }
  for(int i=0; i<M; i++) {
    for(int j=i+1; j<M; j++) {
      double dis = calcDistance(Xm[i], Xm[j]);
      if(dis < minX[i]) {
	minX[i] = dis / 2.0;
	if(minX[j] > dis / 2.0)
	  minX[j] = dis / 2.0;
      }
    }
  }
  cout << setprecision(10);
  if(M == 0)
    cout << *min_element(R.begin(), R.end()) << endl;
  else if(N == 0)
    cout << *min_element(minX.begin(), minX.end()) << endl;
  else
    cout << min((double)*min_element(R.begin(), R.end()),
		*min_element(minX.begin(), minX.end())) << endl;
  return 0;
}

