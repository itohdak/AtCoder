#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll N;
  vector<ll> capacity(5);
  cin >> N;
  for(int i=0; i<5; i++)
    cin >> capacity[i];
  vector<ll>::iterator min_itr = min_element(capacity.begin(), capacity.end());
  ll min_cap = *min_itr;
  ll num = (ll)ceil(1.0 * N / min_cap);
  ll ans = (min_itr - capacity.begin()) + num + (capacity.end() - 1 - min_itr);
  cout << ans << endl;
  return 0;
}

