from datetime import datetime

def enumeration_algo(arr):
    start = 0
    end = len(arr)
    sub_sum = arr[0]

    for i in xrange(len(arr)):
        for j in xrange(i, len(arr)):
            temp_sum = 0
            for k in xrange(i, j + 1):
                temp_sum += arr[k]
                if sub_sum < temp_sum:
                    start = i
                    end = j
                    sub_sum = max(sub_sum, temp_sum)

    return (start, end, sub_sum)

with open('MSS_TestProblems.txt', 'r') as test_problems:
    for line in test_problems:
        line = line.replace("[", "")
        line = line.replace("]", "")
        input_array = line.split(",")
        output_array = []
        for i in input_array:
            output_array.append(int(i))
        print enumeration_algo(output_array)
