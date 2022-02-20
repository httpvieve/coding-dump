n = int(input())
def return_multiplier(n):
        multiplier = 1
        for i in range (len(str(n))):
                multiplier *= 10
        return multiplier 
def return_val(n):
        num = 0
        for i in range(n + 1):
                if len(str(i))*10 == return_multiplier(i):
                        num = num*return_multiplier(n) + i
        return num
    
print(return_val(n))