#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	
	srand(time(NULL));
	string num = argv[1];
	std::istringstream iss(num);
	long int n;
	iss >> n;
	int min = -10000;
	int max = 10000;
	srand(time(NULL));
	vector<double> v;
	for (long int i = 0; i < n*2; i++){
		double randNum = min + (max - min)*(double)rand() / RAND_MAX;
		v.push_back(randNum);
	}
	for (long int x = 0; x < n*2; x = x + 2) {
		cout << v[x] << " " << v[x+1] << endl;
	}

	return 0;
}