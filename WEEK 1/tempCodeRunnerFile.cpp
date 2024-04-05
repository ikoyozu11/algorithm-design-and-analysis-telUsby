

using namespace std;

// Function to find the sum of proper divisors of a number
int sumOfProperDivisors(int n) {
  int sum = 1; // Include 1 as a proper divisor

  // Iterate only up to the square root of n
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      // If i is a divisor, add both i and n/i (if distinct)
      sum += (i == n / i) ? i : (i + n / i);
    }
  }

  return sum;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    cout << sumOfProperDivisors(n) << endl;
  }

  return 0;
}