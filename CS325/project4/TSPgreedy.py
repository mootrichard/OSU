import math

#read file into array of form [['index1', 'x1', 'y1'],...]
def readFile(fileName):
    f = open(fileName, 'r')
    points = []
    for line in f:
        points.append(line.split())
    return points


#find cartesian distance between two points
def dist(x1, y1, x2, y2):
    return round(math.sqrt(math.pow(x1 - x2, 2) + math.pow(y1-y2, 2)))


#find the point in array closest to curRow & return the point id and the distance between the two
def findClosest(curRow, array):
    closestD = float('inf')
    closestID = -1
    index = 0
    closestIndex = -1

    for row in array:
        curDist = dist(int(curRow[1]), int(curRow[2]), int(row[1]), int(row[2]))
        if (curDist < closestD):
            closestD = curDist
            closestID = int(row[0])
            closestIndex = index
        index += 1
    return closestID, closestD, closestIndex

def computeDistances(array, dArray):
    for i in range(len(array) - 1):
        dArray[i][i] = 0
        for j in range(i + 1, len(array)):
            dArray[i][j] = dArray[j][i] = dist(int(array[i][1]), int(array[i][2]), int(array[j][1]), int(array[j][2]))
    dArray[-1][-1] = 0


#return the distance and path of the greedy shortest path solution
def computeTSP(array):
        tDistance = 0
        path = []

        start = array.pop()
        path.append(start)
        cur = start
        while (len(array) > 0):
            nextID, nextD, nextIndex = findClosest(cur, array)
            tDistance += nextD
            path.append(array[nextIndex])
            cur = array.pop(nextIndex)

        #get distance back to start
        tDistance += dist(int(start[1]), int(start[2]), int(path[-1][1]), int(path[-1][2]))
        path.append(start)
        return tDistance, path


def computeShortest(start, finishIndices, dArray):
    shortest = float('inf')
    shortIndex = -1
    for finish in finishIndices:
        dist = dArray[start][finish]
        if (dist < shortest):
            shortest = dist
            shortIndex = finish

    return shortest, shortIndex

def computeGreedy(array, dArray):
    tDistance = 0
    path = []
    remainingIndices = []
    for i in range(1, len(array)):
        remainingIndices.append(i)

    start = 0
    path.append(start)
    cur = start
    while (len(remainingIndices) > 0):
        dist, index = computeShortest(cur, remainingIndices, dArray)
        tDistance += dist
        path.append(index)
        cur = index
        remainingIndices.remove(index)

    #go back to start
    tDistance += dArray[start][cur]
    path.append(start)
    return tDistance, path

#currently edges are (v1, v2) and (v3, v4).  check if other path combo
#return the distance savings and the "offest" of the vertex v1 should connect to (is initially 2)
def checkSwitch(dArray, v1, v2, v3, v4):
    curDist = dArray[v1][v2] + dArray[v3][v4]

    #edges (v1,v3) and (v2,v4)
    v1v3Dist = dArray[v1][v3] + dArray[v2][v4]


    if curDist <= v1v3Dist:
        return 0
    else:
        return (curDist - v1v3Dist)


#make pairwise exchange optimization
def pairwiseEx(dArray, path, distance):
    newD = distance
    for i in range(len(path) - 5):
        for j in range(i + 2, len(path) - 3):
            savings = checkSwitch(dArray, path[i], path[i+1], path[j], path[j+1])
            if (savings > 0):
                newD -= savings
                #rebuild path
                path[i+1:j+1] = path[j:i:-1]
    return newD

#filename = "C:/Users/cking/Desktop/Summer2016/Algorithms/Project4-TSP/tsp_example_1.txt"
#filename = "C:/Users/cking/Desktop/Summer2016/Algorithms/Project4-TSP/tsp_example_2.txt"
filename = "C:/Users/cking/Desktop/Summer2016/Algorithms/Project4-TSP/tsp_example_3.txt"
#filename = "C:/Users/cking/Desktop/Summer2016/Algorithms/Project4-TSP/testInput.txt"


array = readFile(filename)

dArray = []
for i in range(len(array)):
    dArray.append([0]* len(array))


computeDistances(array, dArray)


dist, path = computeGreedy(array, dArray)
print(dist)
#print(path)
print('\n\n')

newD = pairwiseEx(dArray, path, dist)
newD = pairwiseEx(dArray, path, newD)

print(newD)
#print(path)
