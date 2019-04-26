#include <iostream>
#include <ctime>
#define N 123456789
using namespace std;

int main() {
    
	int start;
    int j = 1;
    bool k = true;
	
	start = clock();
	for (int i = 0; i < N; i++)
		if(j);
	cout << clock() - start << endl;

	start = clock();
	for (int j = 0; j < N; j++)
		if(k);
	cout << clock() - start << endl;

	return 0;
}
