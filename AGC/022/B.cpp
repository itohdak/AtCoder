#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int NN[20000];
int LCM;
ll SUM;
vector<int> ELIM;

int vector_finder(std::vector<int> vec, int number){
  vector<int>::iterator itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int gcd(int m, int n){
  if ( ( 0 == m ) || ( 0 == n ) )
    return 0;
  while( m != n )
    {
      if ( m > n ) m = m - n;
      else         n = n - m;
    }
  return m;
}

int lcm(int m, int n){
  if ( ( 0 == m ) || ( 0 == n ) )
    return 0;
  return ((m / gcd(m, n)) * n);
}

bool prime_p(int num){
  for(int i=2; i<=floor(sqrt(num)); i++)
    if(num % i == 0)
      return false;
  return true;
}

void make(int num){
  int n = num;
  NN[num - n] = 2;
  LCM = 2;
  SUM = 2;
  n--;
  int tmp = 3;
  while(n > 0){
    if((!prime_p(tmp) || tmp == 3) && vector_finder(ELIM, tmp) == 0){
      NN[num - n] = tmp;
      SUM += tmp;
      n--;
      if(prime_p(tmp))
	LCM *= tmp;
    } else {
      for(int i=0; tmp*i<30000; i++)
	ELIM.push_back(tmp*i);
    }
    tmp++;
  }
}

int main(){
  int N;
  cin >> N;
  make(N-1);
  cout << LCM << ' ' << SUM << endl;
  int tmp2 = lcm(LCM, SUM);
  NN[N-1] = tmp2 - SUM;
  while(NN[N-1] < NN[N-2])
    NN[N-1] += tmp2;

  for(int i=0; i<N; i++)
    cout << NN[i] << ' ';
  cout << endl;

  return 0;
}

