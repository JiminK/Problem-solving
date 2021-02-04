N = int(input())
n = 0

answer = -1

while N - 3 * n >= 0:
    if (N - 3 * n) % 5 == 0:
        answer = (N - 3 * n) // 5 + n
        break
    else:
        n += 1

print(answer)
