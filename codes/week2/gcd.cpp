#include <iostream>

int gcd_naive(int a, int b) {
  int current_r =3;
  while(current_r>0){
  current_r=a % b;
  a=b;
  b=current_r;
  }
  return a;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
