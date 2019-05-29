# ewu/shaykhsiddique
# repository link(updates(10-mar-2019)): github.com/shaykhsiddique/academic-/blob/master/CSE365/lab_codes/genetic_algorithm_n_queens.py
# complexity analysis: it runs on exponential complexity with number of queen

from array import *
from random import *
# data initialization
numOfqueens = 8
numOfData = 4
dataSetArray = []
maxFitness = 28

def data_set_generator(numOfData):
    global numOfqueens, dataSetArray
    # generating random values for each numOfData
    for i in range(0, numOfData):
        dataSetArray.append([])
        for j in range(0, numOfqueens):
            rand_number = randint(1, numOfqueens)
            dataSetArray[i].append(rand_number)

def crossOver(numOfdata):
    global numOfqueens, dataSetArray

    for indx in range(0, numOfdata, 2):
        randNum = randint(1, numOfqueens-1)
        # swapping elements of arrays
        dataSetArray[indx][randNum:], dataSetArray[indx+1][randNum:] = dataSetArray[indx+1][randNum:], dataSetArray[indx][randNum:]


def mutation(numOfdata):
    global numOfqueens, dataSetArray
    for indx in range(0, numOfdata):
        # finding the index of mutation 
        randindx = randint(0, numOfqueens-1)
        # finding the value of mutation 
        randNum = randint(1, numOfqueens)
        dataSetArray[indx][randindx] = randNum


def fitness(individual):
    # checking row wise attacking pair. calculating the fitness of a individual and return it.
    # complexity is O(1) per piece
    #.count return the number of repetation in same row
    horizontal_attack = sum([individual.count(queen)-1 for queen in individual])/2
  
    n = len(individual)
    # diagonal checking array one dimensional array
    left_diagonal = [0] * 2*n
    right_diagonal = [0] * 2*n
    for i in range(n):
        left_diagonal[i + individual[i] - 1] += 1
        right_diagonal[len(individual) - i + individual[i] - 2] += 1

    diagonal_attack = 0
    for i in range(2*n-1):
        attecker = 0
        # as when the value of left_diagonal will 0 there is no queen to attack
        if left_diagonal[i] > 1:
            attecker += left_diagonal[i]-1
        if right_diagonal[i] > 1:
            attecker += right_diagonal[i]-1
        # marge the left_diagonal and right_diagonal with diagonal_attack variables
        diagonal_attack += attecker / (n-abs(i-n+1))
    
    return int(maxFitness - (horizontal_attack + diagonal_attack))

def main():
    global numOfData, numOfqueens, dataSetArray
    flag = True
    version = 1
    # generate random dataSetArray 2D array
    data_set_generator(numOfData)
    while flag:
        crossOver(numOfData)
        print("After crossover: "+str(dataSetArray))
        mutation(numOfData)
        print("After mutation: "+str(dataSetArray))
        # for row of dataSetArray using fitness function 
        for x in dataSetArray:
            current_fitness = fitness(x)
            print("Fitness found: " + str(current_fitness))
            best_fit = (numOfqueens * (numOfqueens-1))/2
            if current_fitness == best_fit:
                ans = x
                flag = False
        version += 1
    print("Matched data found: "+str(ans)+ " with fitness:"+ str(best_fit) + " and version: "+ str(version))
main()
