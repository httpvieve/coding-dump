def printx():
        print('x')
def multiplex(n):
        x = ""
        for i in range (n):
                x += "x"
        return n * printx()
    
multiplex(5)