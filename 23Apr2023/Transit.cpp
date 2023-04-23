#include <iostream>
#include <string>;
#include <vector>

int main() {
	// get start time, end time, # of transit routes
	int s, t, n;
	std::vector<int> d, b, c;
	int time; // how much time he has to get to class
	int tot_time; // how much time it takes to get to class
	int ti = 0; // travel time after bus_i "completes" each route (walk time, bus route time, and waiting time)

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

	for (int i = 0; i < n; i++) {
		int wi, ci, x;

		ci = c.at(i);
		ti += d.at(i);
		if (ti % ci == 0) wi = 0;
		else {
			x = int(ti / ci) + 1;
			/*std::cout << "Debug: " << ti << ", " << ci << std::endl;
			std::cout << "Debug: " << x;*/
			wi = ci*x - ti;
		}

		/*std::cout << std::endl;
		std::cout << d.at(i) << ", " << b.at(i) << ", " << wi <<std::endl;*/

		ti += b.at(i) + wi;
	}

	time = t - s;
	tot_time = ti + d.at(d.size() - 1);
	/*std::cout << time << std::endl;
	std::cout << tot_time<<std::endl;*/

	if (time >= tot_time) std::cout << "yes";
	else std::cout << "no";

}