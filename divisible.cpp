#include<iostream>
#include<fstream>

using namespace std;

int rem = 0;
bool start = true;

bool is_divisible(char i) {
	if (start) {
		rem = i - '0';
		start = false;
		return !rem;
	} else {
		bool result;
		switch (rem) {
			case 0:
				result = !(i - '0');
				rem = result ? : rem = 1;
				break;	
			case 1:
				result = (i - '0');	
				rem = result ? rem = 0 : rem = 2;
				break;
			case 2:
				result = (i - '0');
				rem = result ? : rem = 1;
				break;
		}
		return result;
	}
}

int main() {
	string inp;
	ifstream myfile;
	myfile.open ("1.dat", ios :: in);
	
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			// String  retrieved.
			getline(myfile, inp);
			cout << inp; 
	
			start = true;
			rem = 0;

			if (inp.empty()) {
				break;
			}
			// Perform analysis.
			int i = 0;
			for (; i < inp.length() - 1; i++) {
				is_divisible(inp.at(i));
			}

			cout << '\t' << is_divisible(inp.at(i)) << endl;
		}
		myfile.close();
	}
}
