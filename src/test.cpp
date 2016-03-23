#include <iostream>
#include <vector>
#include "DE.h"

int main(int argc, char **argv) {
	std::vector<int> nnLayerLayout = { 1,2,3};
	int popSize = 2;

	DE* de = new DE(nnLayerLayout, popSize);

	if (argc > 1) {
		if (!strcmp(argv[1],"-v")) {
			std::cout << "Verbose activated" << std::endl;
		}
	}

	return 0;
}