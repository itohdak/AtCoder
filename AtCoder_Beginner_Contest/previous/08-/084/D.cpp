#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  int Q;
  cin >> Q;
  vector<int> L, R;
  int max = 0;
  for(int i=0; i<Q; i++){
    int l, r;
    cin >> l >> r;
    L.push_back(l);
    R.push_back(r);
    if(max < r)
      max = r;
  }
  vector<int> prime;
  bool memo[max];
  for(int i=0; i<max; i++)
    memo[i] = true;
  memo[0] = false;
  int tmp = 1;
  for(int i=0; i<max; i++){
    if(memo[i]){
      prime.push_back(i+1);
      for(int j=(i+1); j<max; j+=(i+1))
	memo[j-1] = false;
    }
  }
  // for(int i=0; i<prime.size(); i++)
  //   cout << prime[i] << ' ';
  // cout << endl;

  int memo2[max];
  memo2[0] = 0;
  for(int i=1; i<max; i++){
    int tmp = i+1;
    if(tmp % 2 == 1 &&
       (find(prime.begin(), prime.end(), tmp) != prime.end()) &&
       (find(prime.begin(), prime.end(), (tmp+1)/2) != prime.end()))
	memo2[i] = memo2[i-1] + 1;
    else
      memo2[i] = memo2[i-1];
  }
  // for(int i=0; i<max; i++)
  //   cout << memo2[i] << ' ';
  // cout << endl;

  for(int i=0; i<Q; i++){
    int l = L[i]; int r = R[i];
    cout << memo2[r-1] - memo2[l-1-1] << endl;
  }
  return 0;
}

