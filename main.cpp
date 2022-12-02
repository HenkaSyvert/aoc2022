#include <iostream>
#include <fstream>
#include <string>


using namespace std;



void dec1a() {

	ifstream input;
	input.open("input/dec1a.txt");

	int elf = 1;
	int maxElf = 1;
	int sum = 0;
	int maxSum = 0;

	string line;
	while (getline(input, line)) {
	
		if (line.length() <= 2) { // means it's an empty line (I hope). 
			
			if (sum > maxSum) {

				maxElf = elf;
				maxSum = sum;

			}

			elf++;
			sum = 0;
			cout << endl;

		}
		else {
			int cal = atoi(line.c_str());
			//cout << "elf " << elf << " " << sum << " + " << cal << " = " << sum + cal << endl;
			sum += cal;
			//getchar();

		}
	}

	cout << "elf " << maxElf << " had most total calories with " << maxSum << endl;
}




int main() {

	dec1a();



	return 0;
}
