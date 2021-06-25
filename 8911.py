import sys
t = int(sys.stdin.readline().rstrip())

control = ['F', 'B', 'L', 'R']
direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]
for _ in range(t):
    x, y = 0, 0
    see = direction[0]  # 북쪽 바라봄
    nx = 0
    ny = 1
    s = 0
    trace = [(0, 0)]

    moves = list(sys.stdin.readline().rstrip())

    for move in moves:
        if move == 'F':
            x += see[nx]
            y += see[ny]
            trace.append((x, y))

        elif move == 'B':
            x -= see[nx]
            y -= see[ny]
            trace.append((x, y))

        elif move == 'L':
            s -= 1
            if s == -1:
                s = 3
            elif s == 4:
                s = 0
            see = direction[s]

        else:  # 'R'
            s += 1
            if s == -1:
                s = 3
            elif s == 4:
                s = 0
            see = direction[s]

    # print(f'({x}, {y})')
    # print(trace)

    w = []
    h = []
    for i in range(len(trace)):
        w.append(trace[i][0])
        h.append(trace[i][1])

    a = max(w) - min(w)
    b = max(h) - min(h)
    print(a * b)

