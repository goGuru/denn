#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

class DE
{
public:
	std::vector<int> nnLayerLayout;
	int nnNrOfWeights;
	int popSize;
	std::vector<std::vector<double>> population;

public:
	DE(std::vector<int> nnl, int ps);
	~DE();

	void createInitialPopulation();
	std::vector<double> newIndividual();
	void showPopulation();
};

