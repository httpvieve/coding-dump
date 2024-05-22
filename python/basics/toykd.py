target_donation = float(input())
prod_quantity = [int(input()) for x in range(5)]
prod_price = [14, 3, 20.2, 8.2, 10.65]
total_price = float(sum(prod_quantity[i] * prod_price[i] for i in range(5)))
if sum(prod_quantity) > 50:
        total_price = total_price * 1.25
rent = total_price * 0.1
res = target_donation - rent
if res > 0:
        print("Yes! " + str(res) + " dollars left")
else:
        res = -res
        print("Not enough money! "+ str(res) + " dollars needed.")
        
        
import string
word = input()
nShift = input()
shiftedstr = ""
letter = ""
for i in range (len(word)):
  if word[i] in string.ascii_lowercase or letter in string.ascii_uppercase:
    if len(word) - word.index[i] < nShift:
      shiftedchr = ord(word[(word.index[i] + nShift) % len(word)] + nShift)
    shiftedchr = ord(letter) + nShift
    shiftedstr += chr(shiftedchr)
  else:
    shiftedstr += letter
print(shiftedstr)