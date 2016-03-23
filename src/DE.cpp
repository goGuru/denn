#include "DE.h"

DE::DE(std::vector<int> nnl, int ps) :
	nnLayerLayout(nnl),
	popSize(ps),
	population(NULL)
{
	for (int i = 0; i < nnLayerLayout.size(); i++) {
		if (i == 0) {
			nnNrOfWeights = nnLayerLayout[0];
		}
		else {
			nnNrOfWeights *= nnLayerLayout[i];
		}
	}

	createInitialPopulation();
	showPopulation();
}


DE::~DE()
{
}

void DE::createInitialPopulation() {
	for (int i = 0; i < popSize; i++) {
		population.push_back(newIndividual());
	}
}

std::vector<double> DE::newIndividual() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> distribution(-1.0, 1.0);

	std::vector<double> tmpVec;
	for (int i = 0; i < nnNrOfWeights; i++) {
		tmpVec.push_back(distribution(generator));
	}

	return tmpVec;
}

void DE::showPopulation() {
	for (int r = 0; r < population.size(); r++) {
		std::cout << "Individual " << r << ": ";
		for (int c = 0; c < population[0].size(); c++) {
			std::cout << population[r][c] << " ";
		}
		std::cout << std::endl;
	}
}