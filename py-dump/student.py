# classes : collection of properties and methods
class Student: #class name 

    name = None
    age = None
    #methods / functions
    def __init__(self, name, age):
        self.name = name
        self.age= age

    def print_name(self):
        print("My name is " + self.name)

    def print_age(self):
        print("I am " + str(self.age) + " years old.")

    def add_age(self):
        self.age += 5
