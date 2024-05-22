filename = 'item13.txt'
with open(filename, "r") as ins:
    array = []
    for line in ins:
        array.append(line)
newArray = []
for i in array:
    newArray.append(int(i))

arraySum = sum(newArray)
print(str(arraySum)[:10])