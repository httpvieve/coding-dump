n = int(input())
def return_val(n):
    num = 0 
    for i in range(n + 1):
        num = num*10 + i
    return num
    
print(return_val(n))