#include <iostream>
#include <algorithm>

typedef struct interval interval;

struct interval {
	int ai, bi;
};

bool cmp(interval interval1, interval interval2) {
	if (interval1.ai == interval2.ai) {
		return interval1.bi < interval2.bi;
	}
	
	return interval1.ai < interval2.ai;
}

int main(int argc, char* argv[]) {
	interval intervals[50000];

	int n = 0;
	std::cin >> n;

	//Input all the initial intervals
	int i = 0;
	for (i = 0; i < n; i++) {
		std::cin >> intervals[i].ai >> intervals[i].bi;
	}

	//Sort
	std::sort(intervals, intervals + n, cmp);

	//Merge and output
	interval current = { 0, 0 };
	for (i = 0; i < n; i++) {
		int a = intervals[i].ai;
		int b = intervals[i].bi;
		if (!i) {
			current = intervals[i];
			continue;
		}
		else if (current.bi < a) {
			std::cout << current.ai << ' ' << current.bi << std::endl;
			current = intervals[i];
		}
		else {
			if (current.bi < b) {
				current.bi = b;
			}
		}
	}
	std::cout << current.ai << ' ' << current.bi << std::endl;

	return 0;
}
