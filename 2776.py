import sys
t = int(sys.stdin.readline().rstrip())
for _ in range(t):
    n = int(sys.stdin.readline().rstrip())
    one = set(map(int, sys.stdin.readline().rstrip().split()))

    m = int(sys.stdin.readline().rstrip())
    two = list(map(int, sys.stdin.readline().rstrip().split()))
    set2 = set(two)
    three = one & set2

    answer = []
    for i in two:
        if i in three:
            answer.append(1)
        else:
            answer.append(0)

    for j in answer:
        print(j)
