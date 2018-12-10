#define ll long long

/*
  階乗
*/
int factorial(int N, int buf=1) {
  if(N == 1) {
    return buf;
  } else {
    return factorial(N-1, buf*N);
  }
}


/*
  最大公約数
*/
ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}
/*
  最小公倍数
*/
ll lcm(ll x, ll y) {
  ll g = gcd(x, y);
  return (x / g) * (y / g);
}

