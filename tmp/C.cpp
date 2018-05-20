#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct data{
  ll c;
  ll v;
  bool sold;
};

bool comp(data d1, data d2){
  if(d1.c == d2.c){
    return d1.v <= d2.v;
  } else {
    return d1.c < d2.c;
  }
}

int main(){
  int N;
  cin >> N;
  data tmp = {0, 0, true};
  vector<ll> T;
  vector<data> A(N, tmp);
  for(int i=0; i<N; i++){
    ll in;
    cin >> in;
    T.push_back(in);
  }
  for(int i=0; i<N; i++){
    ll in;
    cin >> in;
    A[i].c = in;
  }
  for(int i=0; i<N; i++){
    ll in;
    cin >> in;
    A[i].v = in;
  }
  sort(A.begin(), A.end(), comp);

  int iter = 0;
  ll money = 0;
  while(iter < N){
    ll csum = 0;
    ll vsum = 0;
    for(int i=0; i<N; i++){
      if(A[i].sold){
	csum += A[i].c;
	vsum += A[i].v;
      }
    }
    // cout << money << ' ' << csum << ' ' << vsum << endl;
    if(money < csum){
      money += T[iter];
      int it = 0;
      while(it < N){
	if(A[it].c > money) break;
	else it++;
      }
      if(it != 0) it--;
      while(it > 0){
	if(A[it].sold) break;
	else it--;
      }
      A[it].sold = false;
      iter++;
    } else {
      cout << vsum << endl;
      break;
    }
  }

  if(iter == N)
    cout << 0 << endl;

  return 0;
}

