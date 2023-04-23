#include <iostream>
#include <vector>

int main() {
	// get start time, end time, # of transit routes
	int s, t, n;
	std::vector<int> d, b, c, w;
	std::cin >> s >> t >> n;

	// get walk travel times
	for (int i = 0; i < n + 1; i++) {
		int x = 0;
		std::cin >> x;
		d.push_back(x);
	}

	//get bus travel times
	for (int i = 0; i < n; i++) {
		int x = 0;
		std::cin >> x;
		b.push_back(x);
	}

	// get bus arrival interval times
	for (int i = 0; i < n; i++) {
		int x = 0;
		std::cin >> x;
		c.push_back(x);
	}

	// how long it takes to wait for each bus
	int ti = 0;

	for (int i = 0; i < n; i++) {
		int wi, ci, x;
		
		ti += d.at(i) + b.at(i) + w.at(i);
		ci = c.at(i);
		
		if (ti % ci == 0) wi = 0;
		else {
			x = int(ti / ci) + 1;
			wi = ci*x - ti;
		}
		w.push_back(wi);

	}


	

	int time = t - s; // how much time he has to get to class
	int tot_time = 0; // how much time it takes to get to class




}