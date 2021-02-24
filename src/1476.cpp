#include <iostream>
using namespace std;

int main() {
	int E, S, M;
	cin >> E >> S >> M;
	
    int year = 0;
    while (true) {
        year++;
        if (((year - E) % 15 == 0) 
            && ((year - S) % 28 == 0) 
            && ((year - M) % 19 == 0))
            break;
    }

    cout << year << endl;
	return 0;
}