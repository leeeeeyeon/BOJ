t = int(input())
answer = []

for _ in range(t):
    a, b = map(int, input().split())
    x = min(a, b)
    y = 1
    for i in range(x, 0, -1):
        if a % i == 0 and b % i == 0 and i > y:
            y = i

    answer.append(int(a * b / y))

for i in answer:
    print(i)

'''
a, b = map(int, input().split())
x = min(a, b)
y = 1
for i in range(x, 0, -1):
    if a % i == 0 and b % i == 0 and i > y:
        y = i

print(y)
'''