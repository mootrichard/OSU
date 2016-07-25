def coins(values, cents):
    coins_needed = []
    for i in range(cents + 1):
        coins_needed.append(-1)

    coins_needed[0] = 0

    for j in range(1, cents + 1):
        q = float("inf")
        i = 0
        while i < len(values) and values[i] <= j:
            q = min(q, 1 + coins_needed[j - values[i]])
            i += 1

        coins_needed[j] = q

    return coins_needed

values = [1, 5, 10, 25, 50, 100]
cost = 126
num_needed = coins(values, cost)

for num in range(cost + 1):
    print("To make " + str(num) + " cents")
    print("You need: " + str(num_needed[num]) + " coins.")