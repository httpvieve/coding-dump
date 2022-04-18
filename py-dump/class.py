# inclusion 
# using class from another file <syntax> :
# from <file_name> import <Class_name>
from student import Student

student1 = Student("Bob", 19);
# calling a method from a class <syntax> :
# <class_name>.<method>()
student1.print_name()
student1.print_age()
student1.add_age()
print("In 5 years, ")
student1.print_age()
