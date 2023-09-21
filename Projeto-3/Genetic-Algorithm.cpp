#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Chromosome {
    double x;
    double fitness;
};

const int POPULATION_SIZE = 100;
const double MUTATION_RATE = 0.01;
const int MAX_GENERATIONS = 1000;
const double MIN_X = -10.0;
const double MAX_X = 10.0;

double objectiveFunction(double x) {
    return pow(x, 3);
}

// Initializar população com valores aleatórios
vector<Chromosome> initializePopulation() {
    vector<Chromosome> population(POPULATION_SIZE);
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        Chromosome chromosome{};
        chromosome.x = (MAX_X - MIN_X) * (rand() / static_cast<double>(RAND_MAX)) + MIN_X;
        population[i] = chromosome;
    }
    return population;
}

void calculateFitness(Chromosome& chromosome) {
    chromosome.fitness = objectiveFunction(chromosome.x);
}

void mutate(Chromosome& chromosome) {
    if (rand() / static_cast<double>(RAND_MAX) < MUTATION_RATE) {
        // Randomly perturb the value of x
        chromosome.x += (MAX_X - MIN_X) * (rand() / static_cast<double>(RAND_MAX)) + MIN_X;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    vector<Chromosome> population = initializePopulation();

    for (int generation = 0; generation < MAX_GENERATIONS; ++generation) {
        for (Chromosome& chromosome : population) {
            calculateFitness(chromosome);
        }
        Chromosome bestSolution = population[0];
        for (const Chromosome& chromosome : population) {
            if (chromosome.fitness > bestSolution.fitness) {
                bestSolution = chromosome;
            }
        }
        cout << "Generation " << generation << ": x = " << bestSolution.x << ", f(x) = " << bestSolution.fitness <<endl;
        for (Chromosome& chromosome : population) {
            mutate(chromosome);
        }
    }

    return 0;
}
