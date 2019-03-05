from array import *
from random import *
# data initialization
numOfqueens = 8
numOfData = 4
dataSetArray = [[2, 4, 7, 4, 8, 5, 5, 2], [3, 2, 7, 5, 2, 4, 1, 1], [2, 4, 4, 1, 5, 1, 2, 4], [2, 4, 7, 4, 8, 5, 5, 2]]


def crossOver(numOfdata):
    global numOfqueens, dataSetArray

    for indx in range(0, numOfdata, 2):
        randNum = randint(1, numOfqueens-1)
        if(indx<len(dataSetArray)):
            # swapping elements of arrays
            dataSetArray[indx][randNum:], dataSetArray[indx+1][randNum:] = dataSetArray[indx+1][randNum:], dataSetArray[indx][randNum:]


def mutation(numOfdata):
    global numOfqueens, dataSetArray
    for indx in range(0, numOfdata):
        randNum = randint(1, numOfqueens-1)
        while(randNum==dataSetArray[indx][randNum]):
            randNum = randint(1, numOfqueens)
        dataSetArray[indx][randNum] = randNum



def fitnessCalculation(numOfdata, ind_num=0):
    global numOfqueens, dataSetArray
    # making a grid
    grid = []
    for i in range(0, numOfqueens):
        grid.append([])
        for j in range(0, numOfqueens):
            if(j==dataSetArray[ind_num][i]-1):
                grid[i].append(1)
            else:
                grid[i].append(0)




def main():
    global numOfData, numOfqueens, dataSetArray
    if(numOfData<2):
        print("Number of data is less then two, Program terminated.")
        return
    if(numOfData%2==1):
        # odd number of dataset. need to copy one set and make dataset even
        dataSetArray.insert(numOfData, dataSetArray[0])
        numOfData+=1

    crossOver(numOfData)
    print("After crossover: "+str(dataSetArray))
    mutation(numOfData)
    print("After mutation: "+str(dataSetArray))
    fitnessCalculation(numOfData)

main()
