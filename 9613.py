import sys
from itertools import combinations

t = int(sys.stdin.readline().rstrip())


def gcd(a, b):
    mod = a % b
    while mod > 0:
        a = b
        b = mod
        mod = a % b

    return b


for _ in range(t):
    array = list(map(int, sys.stdin.readline().rstrip().split()))
    n = array[0]
    array.remove(n)

    comb = list(combinations(array, 2))
    # print(comb)

    answer = []
    for num in comb:
        answer.append(gcd(num[0], num[1]))
    # print(answer)
    print(sum(answer))
