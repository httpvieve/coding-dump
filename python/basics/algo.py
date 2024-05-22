prompt = int(input("Enter a number: "))
  
def is_armstrong (prompt):
        nth_sum = 0
        temp = prompt
        n = len (str(prompt))
        while temp > 0:
                leftmost = temp % 10
                print (str(leftmost) + "^" + str (n) + " = " + str(leftmost**n))
                nth_sum += leftmost**n
                temp //= 10
                
        print (str (nth_sum) + " ?= " + str (prompt))
        return (nth_sum == prompt)

result = is_armstrong(prompt)
if result == True :
        print (str(prompt) + " is an armstrong number")
else :
        print (str(prompt) + " is not an armstrong number")