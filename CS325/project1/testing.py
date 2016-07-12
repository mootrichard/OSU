from datetime import datetime
from sys import maxint
from random import random, shuffle, randint

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

def generate_n_values(N):
    returned_list = list()

    for x in xrange(0, N-1):
        returned_list.append(randint(-1000, 1000))
    returned_list.append(randint(1, 1000))
    shuffle(returned_list)

    return returned_list

data = open('data.csv', 'w')
def test_run(N, test_function):
    test_data = generate_n_values(N)
    data.write(str(test_function) + '\n')
    for x in range(1, 10):
        data.write('n = ' + str(N) + ', ')
        start = datetime.now()
        test_function(test_data)
        end = datetime.now()
        data.write(str((end - start).microseconds) +'\n')

test_run(20, linear_algo)
test_run(40, linear_algo)
test_run(80, linear_algo)
test_run(200, linear_algo)
test_run(500, linear_algo)
test_run(1000, linear_algo)
#test_run(1500, linear_algo)

test_run(20, divide_and_conquer)
test_run(40, divide_and_conquer)
test_run(80, divide_and_conquer)
test_run(200, divide_and_conquer)
test_run(500, divide_and_conquer)
test_run(1000, divide_and_conquer)
#test_run(1500, divide_and_conquer)

test_run(20, enumeration_algo_faster)
test_run(40, enumeration_algo_faster)
test_run(80, enumeration_algo_faster)
test_run(200, enumeration_algo_faster)
test_run(500, enumeration_algo_faster)
test_run(1000, enumeration_algo_faster)
#test_run(1500, enumeration_algo_faster)

test_run(20, enumeration_algo)
test_run(40, enumeration_algo)
test_run(80, enumeration_algo)
test_run(200, enumeration_algo)
test_run(500, enumeration_algo)
test_run(1000, enumeration_algo)
#test_run(1500, enumeration_algo)
