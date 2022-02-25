        #Fish language : converts every vowels to w
def translate(phrase):
        translation = ""
        for l in phrase:
                if l in "AEIOUaeiou":
                        if l.isupper():
                                translation +="W"
                        else:
                                translation += "w"
                else:
                        translation += l
        return translation

print(translate(input("enter phrase: ")))