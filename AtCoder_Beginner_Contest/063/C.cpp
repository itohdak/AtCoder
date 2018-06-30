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
  vector<int> S(N);
  int sum = 0;
  for(int i=0; i<N; i++){
    cin >> S[i];
    sum += S[i];
  }
  sort(S.begin(), S.end());
  int tmp = 0;
  for(int i=0; i<N; i++)
    if(S[i] % 10 != 0){
      tmp = S[i];
      break;
    }
  if(sum % 10 == 0)
    cout << sum - tmp << endl;
  else
    cout << sum << endl;
  return 0;
}

