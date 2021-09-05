#include <iostream>
#include <vector>
using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}


long long get_fibonacci_last_digit_fast(int n)
{
	vector<long long> vec(n + 1);
	vec[0] = 0;
	vec[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		vec[i] = (vec[i - 1]%10 + vec[i - 2]%10)%10;
	}
	return vec[n];
}

int main() {
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
