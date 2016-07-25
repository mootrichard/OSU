def coins(values, cents):
    coins_needed = []
    for i in range(cents + 1):
        coins_needed.append(-1)

    coin_count = []
    for i in range(cents + 1):
        coin_count.append([0]*len(values))

    coins_needed[0] = 0

    for j in range(1, cents + 1):
        q = float("inf")
        i = 0
        while i < len(values) and values[i] <= j:
            max_with_j = 1 + coins_needed[j - values[i]]
            if q > max_with_j:
                coin_count[j] = list(coin_count[j - values[i]])
                coin_count[j][i] += 1
            q = max_with_j
            i += 1

        coins_needed[j] = q

    return coins_needed[-1], coin_count[-1]

values = [1, 5, 10, 25, 50, 100]
cost = 126
num_needed, coin_count = coins(values, cost)

for num in range(cost + 1):
    num_needed, coin_count = coins(values, num)

    print("To make " + str(num) + " cents")
    print("You need: " + str(num_needed) + " coins.")
    print(coin_count)