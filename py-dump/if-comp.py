def max_num(a, b, c):
        if a >= b and a >= c:
                return a
        elif b >= a and b >= c:
                return b
        else:
                return c
        
print(max_num(5,7,7))