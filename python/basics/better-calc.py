def calc_engine(a,op, b):
        if op == "-":
                return a - b
        elif op == "+":
                return a + b
        elif op == "*":
                return a*b
        elif op == "%":
                return a%b
        elif op == "/":
                return a/b
        else:
                print("invalid operator!")
        
        
a = float(input("enter first num: "))
op = input("enter operator: ")
b = float(input("enter second num: "))

print(calc_engine(a,op,b))
        
        