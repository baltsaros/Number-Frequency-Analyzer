#include <iostream> // printing
#include <cstdlib> // srand(), time() and rand()
#include <map>

using namespace std;
int	a = 0;

// global variable is required to generate unique random numbers
// time() is used to produce a new output every time(almost) the program is launched
int	generateRanNum() {
	srand(time(NULL) + a);
	int	num = rand();
	// cout << num << endl;
	a++;
	return num;
}

int	parseParam(char *argv) {
	if (argv[0] == '0') {
		cout << "Error: Invalid parameter" << endl;
		exit(EXIT_FAILURE);
	}
	int	num = atoi(argv);
	if (num <= 0) {
		exit(EXIT_FAILURE);
		cout << "Error: Invalid parameter" << endl;
	}
	return num;
}

void	printMap(map<int, int> data) {
	for (map<int, int>::iterator it = data.begin(); it != data.end(); it++)
		cout << it->first << ": " << it->second << endl;
}

int		findNum(int range, int random) {
	int	num = random;
	while (num >= range)
		num = range;
	return num;
}

int	main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "Error: Invalid number of parameters" << endl;
		return 0;
	}
	int	random;
	int	range = parseParam(argv[1]);
	int	iterations = parseParam(argv[2]);
	cout << "range: " << range << endl;
	cout << "iters: " << iterations << endl;
	map<int, int>	data;
	map<int, int>::iterator	it;
	int	num;
	for (int i = 0; i != range; ++i)
		data[i] = 0;
	for (; iterations > 0; iterations--) {
		random = generateRanNum();
		num = random % range;
		// cout << "ran: " << random << endl;
		// cout << "num: " << num << endl;
		it = data.find(num);
		if (it == data.end()) {
			cout << "Error: Find() failed!!!" << endl;
			exit(EXIT_FAILURE);
		}
		it->second++;
	}
	printMap(data);
	return 0;
}