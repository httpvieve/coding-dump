phrase = "De La Salle University"
print(phrase + " is cool")
print(phrase.lower()) #.lower(): converts every letter to lower case
print(phrase.upper()) #.upper(): converts every letter to UPPER CASE 
print(phrase.isupper()) #.isupper(): returns true if the phrase is entirely written in uppercase, else false
print(phrase.upper().isupper()) # upper() -> isupper() = True
print(len(phrase)) #len(var): counts the number of characters 
#string arrays -> always starts with 0!
print(phrase[0]) # pos 0 -> char in phrase
print(phrase[7])
#index func: returns pos num of prompted char (can be a phrase but counts first letter)
print(phrase.index("Salle")) #syntax -> .index(var)
#replace func: 
print(phrase.replace("De La Salle","Adamson")) #syntax -> .replace(newvar,var) 
