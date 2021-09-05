#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b) {
  if (a==0){
   return b;
 }else{
   return gcd_fast(b%a,a);
 }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << (long long)(a)*b/gcd_fast(a, b) << std::endl;
  return 0;
}
