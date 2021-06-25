n, k = map(int, input().split())

array = [i for i in range(2, n+1)]
s = []

while len(array) != 0:
    p = array[0]
    s.append(p)
    array.remove(p)
    for i in array:
        if i % p == 0:
            s.append(i)
            array.remove(i)

print(s[k-1])
