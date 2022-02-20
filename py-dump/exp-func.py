print(4**5) #4^5
#exp func using for loop
def compute_pow(base, exp):
        result = 1;
        for i in range(exp):
                result *= base
        return result

print(compute_pow(4,5))