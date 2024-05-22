try:
        value = 10/0
        num = int(input("enter num: ")) 
        print(num)
except ZeroDivisionError as err:
        print(err) # "division by zero"
except ValueError:
        print("invalid input!")