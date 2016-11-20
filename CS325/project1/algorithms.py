from sys import maxint

test_arrays = list()

def enumeration_algo(arr):
    start = 0
    end = len(arr)
    sub_sum = -maxint - 1

    for i in xrange(len(arr)):
        for j in xrange(i, len(arr)):
            temp_sum = 0
            for k in xrange(i, j + 1):
                temp_sum += arr[k]
                if sub_sum < temp_sum:
                    start = i
                    end = j+1
                    sub_sum = max(sub_sum, temp_sum)

    return arr[start:end], sub_sum

def enumeration_algo_faster(arr):
    start = 0
    end = len(arr)
    sub_sum = -maxint - 1

    for i in xrange(len(arr)):
        temp_sum = 0
        for j in xrange(i, len(arr)):
            temp_sum += arr[j]
            if sub_sum < temp_sum:
                start = i
                end = j+1
                sub_sum = max(sub_sum, temp_sum)
    return arr[start:end], sub_sum

def divide_and_conquer(arr, start=None, end=None):
    if start == None:
        start = 0
    if end == None:
        end = len(arr) - 1
    def cross_over(arr, start, end, middle):
        right_sum = -maxint - 1
        left_sum = -maxint - 1
        left_index_end = 0
        right_index_end = 0

        curr_left_sum = 0
        for i in range(middle, start-1, -1):
            curr_left_sum += arr[i]
            if curr_left_sum > left_sum:
                left_sum = curr_left_sum
                left_index_end = i

        curr_right_sum = 0
        for j in range(middle+1, len(arr)):
            curr_right_sum += arr[j]
            if curr_right_sum > right_sum:
                right_sum = curr_right_sum
                right_index_end = j+1

        return arr[left_index_end:right_index_end], left_sum + right_sum

    if start == end:
        return arr[start:end], arr[start]

    middle = (start + end) / 2

    left_sub, left_sum = divide_and_conquer(arr, start, middle)
    right_sub, right_sum = divide_and_conquer(arr, middle+1, end)
    cross_sub, cross_sum = cross_over(arr, start, end , middle)

    if left_sum > right_sum:
        if left_sum > cross_sum:
            return (left_sub, left_sum)
        else:
            return (cross_sub, cross_sum)
    else:
        if right_sum > cross_sum:
            return (right_sub, right_sum)
        else:
            return (cross_sub, cross_sum)

def linear_algo(arr):
    max_ending_here = max_so_far = arr[0]
    sub_start = 0
    sub_end = len(arr)-1

    for i in range(1, len(arr)):
        if (max_so_far < arr[i]) & (max_ending_here <= 0):
            sub_start = i
        max_ending_here = max(arr[i], max_ending_here + arr[i])
        if max_ending_here > max_so_far:
            sub_end = i+1
        max_so_far = max(max_so_far, max_ending_here)

    return arr[sub_start:sub_end], max_so_far

def extract():
    with open('MSS_Problems.txt', 'r') as test_problems:
        list_of_arrays = list()
        for line in test_problems:
            line = line.replace("[", "")
            line = line.replace("]", "")
            input_array = line.split(",")
            output_array = []
            for i in input_array:
                if len(i) == 0:
                    continue
                output_array.append(int(i))
            list_of_arrays.append(output_array)
    return list_of_arrays

list_arrays = extract()

results = open('MSS_Results.txt', 'w')

print ""
print "O(n^3)"
results.write("Algorithm 1 \n")
for i in list_arrays:
    sub_array, sub_sum = enumeration_algo(i)
    print sub_array
    print sub_sum
    results.write(str(sub_array) + '\n')
    results.write(str(sub_sum) + '\n')

print ""
print "O(n^2)"
results.write("\nAlgorithm 2 \n")
for i in list_arrays:
    sub_array, sub_sum = enumeration_algo_faster(i)
    print sub_array
    print sub_sum
    results.write(str(sub_array) + '\n')
    results.write(str(sub_sum) + '\n')

print ""
print "O(n log n)"
results.write("\nAlgorithm 3 \n")
for i in list_arrays:
    sub_array, sub_sum = divide_and_conquer(i, 0, len(i) - 1)
    print sub_array
    print sub_sum
    results.write(str(sub_array) + '\n')
    results.write(str(sub_sum) + '\n')

print ""
print "O(n)"
results.write("\nAlgorithm 4 \n")
for i in list_arrays:
    sub_array, sub_sum = linear_algo(i)
    print sub_array
    print sub_sum
    results.write(str(sub_array) + '\n')
    results.write(str(sub_sum) + '\n')

results.close()
