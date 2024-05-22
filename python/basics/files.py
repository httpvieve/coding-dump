# open files (modes)
# 'r'  = open for read (default)
# 'w'  = open for write, truncate
# 'r+' = open for read/write
# 'w+' = open for read/write, truncate
# 'a+' = open for read/append
oomfs = open("oomfs.txt", "r+")
# calling methods
oomfs.write("viray\n")
oomfs.write("eros\n")
names = oomfs.read()
print(names)
