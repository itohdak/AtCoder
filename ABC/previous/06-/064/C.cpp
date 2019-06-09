#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  vector<bool> rate(8, false);
  int free = 0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    if(A[i] < 400)
      rate[0] = true;
    else if(A[i] < 800)
      rate[1] = true;
    else if(A[i] < 1200)
      rate[2] = true;
    else if(A[i] < 1600)
      rate[3] = true;
    else if(A[i] < 2000)
      rate[4] = true;
    else if(A[i] < 2400)
      rate[5] = true;
    else if(A[i] < 2800)
      rate[6] = true;
    else if(A[i] < 3200)
      rate[7] = true;
    else
      free++;
  }
  int ans = 0;
  for(int i=0; i<8; i++)
    if(rate[i])
      ans++;
  cout << max(ans, 1) << ' ' << ans+free << endl;
  return 0;
}
