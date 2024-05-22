

def kangaroo(x1, v1, x2, v2):
    a = abs(v1 - x1)
    b = abs(v2 - x1)
    res = "NO"
    i = 1
    while i < 10000:
        if x1 + a * i == x2 + b * i:
            res = "YES"
        i+=1
    return res

    first_multiple_input = input().rstrip().split()

    x1 = int(first_multiple_input[0])

    v1 = int(first_multiple_input[1])

    x2 = int(first_multiple_input[2])

    v2 = int(first_multiple_input[3])

    result = kangaroo(x1, v1, x2, v2)

    print(result)
