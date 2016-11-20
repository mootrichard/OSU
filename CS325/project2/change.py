import sys

def changedp(values, cents):
    """
    Given an array of coin denominations and an integer value, returns an array
    of quantities of coins that can be used to make change for the value using
    as few coins as possible.

    >>> changedp([1, 2, 4, 8], 15)
    [1, 1, 1, 1]
    >>> changedp([1, 3, 7, 12], 29)
    [0, 1, 2, 1]
    >>> changedp([1, 3, 7, 12], 31)
    [0, 0, 1, 2]
    """
    coins_needed = [0]
    coins_added = [0]
    for i in range(1, cents + 1):
        mincoins = float("inf")
        coin_used = 0
        for v in values:
            if v > i:
                break
            coins = 1 + coins_needed[i - v]
            if coins < mincoins:
                mincoins = coins
                coin_used = v
        coins_needed.append(mincoins)
        coins_added.append(coin_used)
    coin_map = {values[i] : i for i in range(len(values))}
    change = [0] * len(values)
    while cents > 0:
        change[coin_map[coins_added[cents]]] += 1
        cents -= coins_added[cents]
    return change


def changegreedy(values, cents):
    """
    Given an array of coin denominations and an integer value, returns an array
    of quantities of coins that can be used to make change for the value. Uses
    a greedy algorithm which is not guaranteed to produce the optimal result.

    >>> changegreedy([1, 2, 4, 8], 15)
    [1, 1, 1, 1]
    >>> changegreedy([1, 3, 7, 12], 29)
    [2, 1, 0, 2]
    >>> changegreedy([1, 3, 7, 12], 31)
    [0, 0, 1, 2]
    """
    coins_needed = []
    for v in reversed(values):
        coins = 0
        while v <= cents:
            coins += 1
            cents -= v
        coins_needed.insert(0, coins)
    return coins_needed


def main(argv):
    """

    """
    if len(argv) > 1:
        file = argv[1]
    else:
        file = "Coins1.txt"
    with open(file[0:file.rfind('.')] + "change.txt", "w") as ofp:
        with open(file) as ifp:
            print("Algorithm changedp:", file=ofp)
            while True:
                line1 = ifp.readline()
                line2 = ifp.readline()
                if not line2:
                    break
                try:
                    v = [int(x.strip()) for x in line1.strip("[] \n").split(",")]
                    a = int(line2)
                except ValueError:
                    break
                coins_needed = changedp(v, a)
                print(coins_needed, file=ofp)
                print(sum(coins_needed), file=ofp)
        with open(file) as ifp:
            print("Algorithm changegreedy:", file=ofp)
            while True:
                line1 = ifp.readline()
                line2 = ifp.readline()
                if not line2:
                    break
                try:
                    v = [int(x.strip()) for x in line1.strip("[] \n").split(",")]
                    a = int(line2)
                except ValueError:
                    break
                coins_needed = changegreedy(v, a)
                print(coins_needed, file=ofp)
                print(sum(coins_needed), file=ofp)

if __name__ == "__main__":
    main(sys.argv)
