n = int(input())
s, e = 1, n*n+1
arr = []

for i in range(n, 0, -1):
    str_ = ""
    j = s
    while j < i + s:
        str_ += str(j) + '*'
        j += 1
    s = j
    j = e
    while j < i + e:
        str_ += str(j)
        if j < i + e - 1:
            str_ += '*'
        j += 1
    e -= (i - 1)
    arr.append(str_)

for i in range(len(arr)):
    s = '-' * i
    print(s + arr[i])
