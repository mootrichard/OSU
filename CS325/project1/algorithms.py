
with open('MSS_TestProblems.txt', 'r') as test_problems:
    for line in test_problems:
        line = line.replace("[", "")
        line = line.replace("]", "")
        input_array = line.split(",")
        output_array = []
        for i in input_array:
            output_array.append(int(i))
        print output_array
