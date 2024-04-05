#include <iostream>
#include <string>
using namespace std;

int hitungDivsum(int n) {
	if (n == 1)
		return 0;

	int sum = 0;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			sum = sum + i;
			if (i != 1) {
				if (n / i == i)
					break;
				sum += n / i;
			}
		}	
	}

	return sum;
}

int main() {
	int t, x;
	cin >> t;
	while (t--) {
		cin >> x;
		cout << hitungDivsum(x) << endl;
	}

	return 0;
}