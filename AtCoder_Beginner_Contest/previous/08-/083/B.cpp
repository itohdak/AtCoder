#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  long long ret = 0;
  for(int i=1; i<=N; i++){
    int sum = (i/10000)%10 + (i/1000)%10 + (i/100)%10 + (i/10)%10 + (i/1)%10;
    if(sum >= A && sum <= B)
      ret += i;
  }
  cout << ret << endl;
  return 0;
}
