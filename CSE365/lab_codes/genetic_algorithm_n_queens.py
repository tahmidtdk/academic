#!/usr/bin/env python

import random
import string

maxFitness = 28
dataSetarray = [[2, 4, 7, 4, 8, 5, 5, 2], [3, 2, 7, 5, 2, 4, 1, 1], [2, 4, 4, 1, 5, 1, 2, 4]]
generation = 1

def print_data(x):
    print(str(x)+" Fitness: "+str(fitness(x)))
  

def fitness(individual):
    horizontal_collisions = sum([individual.count(queen)-1 for queen in individual])/2
  
    n = len(individual)
    left_diagonal = [0] * 2*n
    right_diagonal = [0] * 2*n
    for i in range(n):
        left_diagonal[i + individual[i] - 1] += 1
        right_diagonal[len(individual) - i + individual[i] - 2] += 1

    diagonal_collisions = 0
    for i in range(2*n-1):
        counter = 0
        if left_diagonal[i] > 1:
            counter += left_diagonal[i]-1
        if right_diagonal[i] > 1:
            counter += right_diagonal[i]-1
        diagonal_collisions += counter / (n-abs(i-n+1))
    
    return int(maxFitness - (horizontal_collisions + diagonal_collisions))

def probability(individual, fitness):
    return fitness(individual) / maxFitness

def random_pick(dataSetarray, probabilities):
    dataSetarrayWithProbabilty = zip(dataSetarray, probabilities)
    total = sum(w for c, w in dataSetarrayWithProbabilty)
    r = random.uniform(0, total)
    upto = 0
    for c, w in zip(dataSetarray, probabilities):
        if upto + w >= r:
            return c
        upto += w
  
        
def swap(x, y):
    n = len(x)
    c = random.randint(0, n - 1)
    return x[0:c] + y[c:n]

def mutate(x):
    n = len(x)
    c = random.randint(0, n - 1)
    m = random.randint(1, n)
    x[c] = m
    return x


def crossover(dataSetarray, probabilities):
    x = random_pick(dataSetarray, probabilities)
    y = random_pick(dataSetarray, probabilities)
    new_data = swap(x, y)
    return new_data

def genetic_queen(dataSetarray, fitness):
    mutation_probability = 0.03
    new_dataSetarray = []
    probabilities = [probability(n, fitness) for n in dataSetarray]
    for i in range(len(dataSetarray)):
        child = crossover(dataSetarray, probabilities)
        if random.random() < mutation_probability:
            child = mutate(child)
        print_data(child)
        new_dataSetarray.append(child)
        if fitness(child) == 28: break
    return new_dataSetarray


def main():
    global dataSetarray, generation
    while not 28 in [fitness(x) for x in dataSetarray]:
        print("=== Generation {} ===".format(generation))
        dataSetarray = genetic_queen(dataSetarray, fitness)
        print("Maximum fitness = {}".format(max([fitness(n) for n in dataSetarray])))
        generation += 1

    print("Solved in Generation {}!".format(generation-1))
    for x in dataSetarray:
        if fitness(x) == 28:
            print_data(x)


main()