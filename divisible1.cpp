#include<iostream>
#include<fstream>

using namespace std;

int rem = 0;
bool start = true;

bool is_divisible(char i) {
//	cout << rem << '\t' << i << '\t' << start << endl;
	if (start) {
		rem = i - '0';
		start = false;
		return !rem;
	} else {
		bool result;
		switch (rem) {
			case 0:
				result = !(i - '0');
				rem = result ? 0 : 1;
				break;	
			case 1:
				result = (i - '0');	
				rem = result ? 0 : 2;
				break;
			case 2:
				result = (i - '0');
				rem = result ? 2 : 1;
				break;
		}
		return result;
	}
}

int main() {
	char inp;

	cin >> inp;
	while (inp != 'b') {
		is_divisible(inp);
		//cout << inp;
		cin >> inp;
	}
	cout << !rem << endl;
}
