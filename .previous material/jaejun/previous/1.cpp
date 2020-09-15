/* O3옵션은 필수! */
#pragma GCC optimize ("O3")
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int start = clock();
	int c = 0;
	long long sum = 0;

	/*
	for (int x = 0; x < 251; x++) {
		for (int y = 0; y < 251; y++) {
			if (x == 125 || y == 125)
				continue;
			c++;
			sum += (2500 - (2375 + x))*(2500 - (2375 + x)) + (2500 - (2375 + y))*(2500 - (2375 + y));
		}
	}
	*/

	/* x==125일때 조건을 체크하지 말고 아래처럼 for문을 쪼갠다 */
	for (int x = 0; x < 125; x++) {
		for (int y = 0; y < 125; y++) {
			c++;
			sum += (2500 - (2375 + x))*(2500 - (2375 + x)) + (2500 - (2375 + y))*(2500 - (2375 + y));
		}
		for (int y = 126; y < 251; y++) {
			c++;
			sum += (2500 - (2375 + x))*(2500 - (2375 + x)) + (2500 - (2375 + y))*(2500 - (2375 + y));
		}
	}

	for (int x = 126; x < 251; x++) {
		for (int y = 0; y < 125; y++) {
			c++;
			sum += (2500 - (2375 + x))*(2500 - (2375 + x)) + (2500 - (2375 + y))*(2500 - (2375 + y));
		}
		for (int y = 126; y < 251; y++) {
			c++;
			sum += (2500 - (2375 + x))*(2500 - (2375 + x)) + (2500 - (2375 + y))*(2500 - (2375 + y));
		}
	}

	sum *= 4;
	c *= 4;
	cout << sum << endl;
	if (sum > 1000000000)
		cout << "Fail" << endl;
	else
		cout << "Success" << endl;
	cout << c << endl;
	cout << clock() - start << endl;
	cin >> sum;
}