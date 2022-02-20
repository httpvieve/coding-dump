lucky_num = [2, 5, 7, 13, 18, 37]
friends = ["Tom","Tom", "Tom", "Milsen", "Daniel", "Ella", "Felix"]

friends.append("Way") #append(newvar): adds var
friends.insert(1, "Ron") #insert(index_num, newvar): adds var on a specific index in a list
friends.remove("Milsen") #remove(var): removes selected element
friends.pop() #removes the last element from the list

print(friends.index("Daniel")) #determines the index number of the prompted element 
print(friends.count("Tom")) #count the number of times an element is provided in the list

friends.sort() #arrange the list in alphabetical order for strings, ascending for num
lucky_num.sort() #ascending order
lucky_num.reverse() #descending order

mutuals = friends.copy() #duplicates/copies list elements
print(mutuals)

friends.extend(lucky_num) #list1.extend(list2): combines lists 
friends.clear() #clear(): resets the list
print(friends)

int a;
for (a = 2; a <= max_val; a++){
        if (a)
}