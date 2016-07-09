from datetime import datetime

def recursiveFib(n):
    if n == 1 or n == 2:
        return 1
    else:
        return recursiveFib(n - 1) + recursiveFib(n - 2)

def iterativeFib(n):
    a,b = 1,1
    for i in range(n-1):
        a,b = b,a+b
    return a

testdata = [5, 10, 15, 20, 30, 40]
recursiveResults = []
iterativeResults = []

recursiveFib(5)
for i in testdata:
    start = datetime.now()
    recursiveFib(i)
    end = datetime.now()
    recursiveResults.append((end - start).microseconds)

iterativeFib(5)
for i in testdata:
    start = datetime.now()
    iterativeFib(i)
    end = datetime.now()
    iterativeResults.append((end - start).microseconds)

print recursiveResults
print iterativeResults
