init_amt = input()
int_rate = input()/100.00
years = input()
for i in range(years):
  # print("Year " + str(i) + ": " + str(init_amt))
  init_amt = init_amt*(1+int_rate)
print(str("{:.2f}".format(init_amt)))