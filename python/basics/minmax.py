temp = input()
counter = 1
arr_num = [temp]
arr_div = []
min_val = temp
max_val = temp
while not(counter == 10):
  temp = input()
  arr_num.append(temp)
  if temp < min_val:
    min_val = temp
  elif temp > max_val:
    max_val = temp
  counter +=1

for num in arr_num:
  if num % min_val == 0:
    arr_div.append(num)

print("Highest: "+ str(max_val) + "\nLowest: "+ str(min_val) + "\n"+ str(len(arr_div))+ " numbers divisible by "+ str(min_val))

