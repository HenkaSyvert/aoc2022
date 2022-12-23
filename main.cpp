#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;



void day1part1() {

	ifstream input;
	input.open("input/day1.txt");

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

void day1part2() {

	ifstream input;
	input.open("input/day1.txt");

	// I realise afterwards that saving the elf index is unnecessary
	vector<pair<int, int>> elfSums;

	int elf = 1;
	int sum = 0;

	string line;
	while (getline(input, line)) {

		if (line.length() <= 2) { // means it's an empty line (I hope). 

			elfSums.push_back({elf, sum});
			elf++;
			sum = 0;

		}
		else {
			int cal = atoi(line.c_str());
			sum += cal;

		}

	}

	//for (auto p : elfSums) cout << "{" << p.first << ", " << p.second << "}\n";

	sort(elfSums.begin(), elfSums.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });

	cout << endl;
	//for (auto p : elfSums) cout << "{" << p.first << ", " << p.second << "}\n";

	sum = 0;
	for (int i = 0; i < 3; i++) sum += elfSums[i].second;
	cout << sum;

}

#pragma warning(disable : 4996) //disable _CRT_SECURE_NO_WARNINGS, I do what I want!
void day2part1() {

	char theirMove;
	char myMove;
	int score = 0;

	FILE* input = fopen("input/day2part1.txt", "r");
	if (!input) cout << "sdfsdf";
	while (fscanf(input, "%c %c ", &theirMove, &myMove) != EOF) {

		//printf("%c %c\n", theirMove, myMove);

		score += myMove - 'X' + 1;	// score for selected
		if (theirMove - 'A' == myMove - 'X') score += 3;	// tie
		else if (myMove == 'X' && theirMove == 'C'
			|| myMove == 'Y' && theirMove == 'A'
			|| myMove == 'Z' && theirMove == 'B') {
			score += 6;	// victoire
		}

	}
	printf("%d", score);

	fclose(input);

}

void day2part2() {

	char theirMove;
	char desiredOutcome;
	int score = 0;

	FILE* input = fopen("input/day2.txt", "r");
	if (!input) cout << "sdfsdf";
	while (fscanf(input, "%c %c ", &theirMove, &desiredOutcome) != EOF) {

		switch (desiredOutcome) {
		case 'X': // lose
			score += 
				theirMove == 'A' ? 3 :
			    theirMove == 'B' ? 1 :
				2;
			break;
		case 'Y': // draw
			score += 3;
			score += theirMove - 'A' + 1;
			break;
		case 'Z': // win
			score += 6;
			score +=
				theirMove == 'A' ? 2 :
				theirMove == 'B' ? 3 :
				1;
			break;
		}

	}
	printf("%d", score);

	fclose(input);

}

void day3part1() {

	ifstream input;
	input.open("input/day3.txt");

	
	int prioritySum = 0;

	string line, l1, l2;
	while (getline(input, line)) {

		l1 = line.substr(0, line.size() / 2);
		l2 = line.substr(line.size() / 2, line.size() / 2);

		//cout << line << endl << l1 << endl << l2 << endl;

		char item;
		for (char c1 : l1) {
			for (char c2 : l2) {
				if (c1 == c2) {
					item = c1;
					goto done;
				}
			}
		}
	done:
		if ('a' <= item && item <= 'z') prioritySum += item - 'a' + 1;
		else prioritySum += item - 'A' + 27;

	}

	cout << prioritySum;


}

void day3part2() {

	ifstream input;
	input.open("input/day3.txt");


	int prioritySum = 0;

	string l1, l2, l3;
	while (getline(input, l1)) {
		getline(input, l2);
		getline(input, l3);

		char item;
		for (char c1 : l1) {
			for (char c2 : l2) {
				if (c1 == c2) {
					for (char c3 : l3) {
						if (c3 == c2) {
							item = c1;
							goto done;
						}
					}
				}
			}
		}
	done:
		if ('a' <= item && item <= 'z') prioritySum += item - 'a' + 1;
		else prioritySum += item - 'A' + 27;

	}

	cout << prioritySum;


}

void day4part1() {

	int amin, amax, bmin, bmax, totalOverlaps = 0;

	FILE* input = fopen("input/day4.txt", "r");

	while (fscanf(input, "%d-%d,%d-%d ", &amin, &amax, &bmin, &bmax) != EOF) {

		//printf("%d-%d,%d-%d\n", amin, amax, bmin, bmax);
		//getchar();

		if (bmin <= amin && bmin <= amax && amin <= bmax && amax <= bmax ||
			amin <= bmin && amin <= bmax && bmin <= amax && bmax <= amax) totalOverlaps++;

	}
	fclose(input);
	cout << totalOverlaps;
}

void day4part2() {

	int amin, amax, bmin, bmax, totalOverlaps = 0;

	FILE* input = fopen("input/day4.txt", "r");

	while (fscanf(input, "%d-%d,%d-%d ", &amin, &amax, &bmin, &bmax) != EOF) {

		int totalRange = max(amax, bmax) - min(amin, bmin);
		int aRange = amax - amin;
		int bRange = bmax - bmin;
		if (aRange + bRange >= totalRange) totalOverlaps++;

	}
	fclose(input);
	cout << totalOverlaps;
}

void day5part1() {


	vector<vector<char>> stacks;	// detta är onödigt men nu är den potentielly dynamisk iaf :)

	ifstream input;
	input.open("input/day5.txt");

	bool initStack = false;

	string line;
	while (getline(input, line)) {

		if (!initStack) {
			int numOfStacks = (line.size() + 1) / 4;
			for (int i = 0; i < numOfStacks; i++)
				stacks.push_back(vector<char>());
			initStack = true;
			//cout << numOfStacks;
		}

		if (line[1] == '1') break;

		for (int i = 0; i < (line.size()+1) / 4; i++) {
			if (line[i * 4] == '[') stacks[i].push_back(line[i * 4 + 1]);
		}


	}

	getline(input, line); //discard empty line
	/*
	for (auto s : stacks) {
		for (auto c : s) cout << c;
		cout << endl;
	}*/
	for (auto& s : stacks) reverse(s.begin(), s.end());
	/*for (auto s : stacks) {
		for (auto c : s) cout << c;
		cout << endl;
	}*/

	while (getline(input, line)) {

		int count, src, dst;
		sscanf(line.c_str(), "move %d from %d to %d ", &count, &src, &dst);
		//printf("move %d from %d to %d\n", count, src, dst);
		//getchar();

		for (int i = 0; i < count; i++) {
			stacks[dst - 1].push_back(stacks[src - 1].back());
			//cout << stacks[src - 1].back() << endl;
			//getchar();
			stacks[src - 1].pop_back();

		}
		//for (auto c : stacks[dst - 1])cout << c;

	}

	string result;
	for (auto s : stacks)result += s.back();
	cout << result;



}

void day5part2() {

	vector<vector<char>> stacks;

	ifstream input;
	input.open("input/day5.txt");

	bool initStack = false;

	string line;
	while (getline(input, line)) {

		if (!initStack) {
			int numOfStacks = (line.size() + 1) / 4;
			for (int i = 0; i < numOfStacks; i++)
				stacks.push_back(vector<char>());
			initStack = true;
		}

		if (line[1] == '1') break;

		for (int i = 0; i < (line.size() + 1) / 4; i++) {
			if (line[i * 4] == '[') stacks[i].push_back(line[i * 4 + 1]);
		}


	}

	getline(input, line);
	for (auto& s : stacks) reverse(s.begin(), s.end());

	while (getline(input, line)) {

		int count, src, dst;
		sscanf(line.c_str(), "move %d from %d to %d ", &count, &src, &dst);

		for (int i = count; i > 0; i--) {
			stacks[dst - 1].push_back(stacks[src - 1][stacks[src - 1].size() - i]);
		}
		for (int i = 0; i < count; i++) stacks[src - 1].pop_back();

		//for (auto c : stacks[dst - 1])cout << c << endl;
		//getchar();
		
	}

	string result;
	for (auto s : stacks)result += s.back();
	cout << result;



}

void day6part1() {

	FILE* f = fopen("input/day6.txt", "r");
	
	char buf[5] = "1234";
	buf[3] = getc(f);
	buf[2] = getc(f);
	buf[1] = getc(f);
	int index = 4;
	while ((buf[0] = getc(f)) != EOF) {

		//cout << buf << endl;
		//getchar();
		for (int i = 0; i < 3; i++) 
			if (buf[0] == buf[1+i]) goto notFound;
		
		for (int i = 0; i < 2; i++)
			if (buf[1] == buf[2 + i]) goto notFound;

		if (buf[2] == buf[3]) goto notFound;

		// found
		cout << buf << endl;
		cout << index;
		break;

	notFound:
		//cout << index << endl;
		index++;
		memcpy(buf + 1, buf, 3);
	}

	fclose(f);
}

void day6part2() {

	FILE* f = fopen("input/day6.txt", "r");

	char buf[15] = {'\0'};
	int index = 14;
	for (int i = 1; i < 14; i++) buf[i] = getc(f);	// reverse order but does not matter

	while ((buf[0] = getc(f)) != EOF) {

		//cout << buf << endl;
		//getchar();

		for (int i = 0; i < 13; i++) {
			for (int j = i + 1; j < 14; j++)
				if (buf[i] == buf[j]) goto notFound;
		}

		// found
		cout << index;
		break;


	notFound:
		memcpy(buf + 1, buf, 13);
		index++;
	}

	fclose(f);
}



int main() {

	day6part2();

	return 0;
}
