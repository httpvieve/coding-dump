import csv
import numpy.matlib
import numpy as np
from tkinter import *
from tkinter import filedialog

# holds data from CSV
indep = []
dep = []

# test data
# indep = [0, 1, 2, 3, 4, 5]
# dep = [2.1, 7.7, 13.6, 27.2, 40.9, 61.1]

# test data QSI
# indep = [3.0, 4.5, 7.0, 9.0]
# dep = [2.5, 1.0, 2.5, 0.5]

def open_file ():
    file_path = filedialog.askopenfilename(title="Select a CSV file")
    indep.clear()
    dep.clear()
    with open(file_path, 'r') as csv_file:
        data = csv.reader(csv_file)
        for row in data:
            indep.append(float(row[0]))
            dep.append(float(row[1]))

def GaussJordanElimination (acm, verbose):
    n = len(acm) # gets the number of rows

    for i in range(n):
        if (i != n):
            pivot_row = i
            
            # find pivot row
            for p in range(i, n):
                if (abs(acm[p, i]) > abs(acm[pivot_row, i])):
                    pivot_row = p
            
            # exit if no unique solution
            if (acm[pivot_row, i] == 0.0):
                print("No Unique Solution.")
                return
            
            if (verbose):
                print(f"\n\n---------Iteration {i}---------")
                print(acm)

            # do partial pivoting
            temp_row = np.array(acm[i,])
            acm[i,] = acm[pivot_row,]
            acm[pivot_row,] = temp_row
            
            if (verbose):
                print("\nPIVOT:")
                print(acm)

            # divide row by pivot element
            acm[i,] = np.divide(acm[i,], acm[i,i])
            
            # perform elimination on other rows
            for j in range(n):
                if (i == j): continue
                normalized_row = np.multiply(acm[i,], acm[j,i])
                acm[j,] = np.subtract(acm[j,], normalized_row)

            if (verbose):
                print("MATRIX AFTER ELIMINATION:")
                print(acm)            

    return acm

def PolynomialRegression ():
    x_estimate = input_x.get("1.0",'end-1c')
    degree = input_degree.get("1.0",'end-1c')
    
    if (degree == '' or x_estimate == ''):
        print("Empty inputs")
        return

    x_estimate = int(x_estimate)
    degree = int(degree)

    if (degree < 1): 
        print("Degree cannot be lower than 1")
        return
    
    if (len(indep) != len(dep)):
        print("Unequal length for x and y")
        return

    # setup augmented coefficient matrix for gauss jordan elimination
    m_rows = degree + 1
    n_cols = degree + 2     
    acm = numpy.matlib.zeros((m_rows, n_cols))
    for i in range(m_rows):
        for j in range(m_rows):
            acm[i, j] = sum(np.float_power(indep, i+j))
        
        # fill in last column (rhs)
        acm[i, n_cols-1] = sum((np.float_power(indep, i) * dep))

    # solve using gauss jordan elimination
    acm = GaussJordanElimination(acm, True)
    
    # string manipulation for function string
    poly_string = "f(x) = "
    for i in range(m_rows):
        # first term
        if (i == 0): poly_string = poly_string + str(acm[i, n_cols-1]) + " + "
    
        # for last term
        elif(i == m_rows-1): poly_string = poly_string + str(acm[i, n_cols-1]) + "*x**" + str(i)
        
        else: poly_string = poly_string + str(acm[i, n_cols-1]) + "*x**" + str(i) + " + "

    output_func.config(text=poly_string)

    poly_string = poly_string.replace("f(x) = ", "")
    poly_string = poly_string.replace("x", str(x_estimate))

    x_output = round(eval(poly_string), 2)
    output_estimate.config(text=x_output)

def QuadraticSplineInterpolation ():
    x_estimate = input_x.get("1.0",'end-1c')

    if (x_estimate == ''):
        print("Empty estimate input")
        return

    m = len(indep)
    n = m-1
    curr_row = 0

    # setup acm
    acm = numpy.matlib.zeros(((3*n)-1, (3*n) + 1))

    # condition 1
    for i in range(2, n+1):
        # 1st eq for c1
        # a, b, c, rhs
        acm[curr_row, i-2] = indep[i-1] ** 2
        acm[curr_row, i-2 +3] = indep[i-1]
        acm[curr_row, i-2 +6] = 1
        acm[curr_row, 3*n] = dep[i-1]
        curr_row += 1

        # 2nd eq for c1
        acm[curr_row, i-1] = indep[i-1] ** 2
        acm[curr_row, i-1 +3] = indep[i-1]
        acm[curr_row, i-1 +6] = 1
        acm[curr_row, 3*n] = dep[i-1]
        curr_row += 1

    # condition 2
    acm[curr_row, 0] = indep[0] ** 2
    acm[curr_row, 3] = indep[0]
    acm[curr_row, 6] = 1
    acm[curr_row, 3*n] = dep[0]
    curr_row += 1

    acm[curr_row, n-1] = indep[n] ** 2
    acm[curr_row, n-1 +3] = indep[n]
    acm[curr_row, n-1 +6] = 1
    acm[curr_row, 3*n] = dep[n]
    curr_row += 1

    # condition 3
    for i in range(2, n+1):
        acm[curr_row, i-2] = indep[i-1] * 2
        acm[curr_row, i-2 +3] = 1

        acm[curr_row, i-1] = indep[i-1] * -2
        acm[curr_row, i-1 +3] = -1

        # ensures last column is at 0 (0 is default from setup)
        acm[curr_row, 3*n] = 0
        curr_row += 1

    # condition 4 - delete a1 column, since: a1 = 0
    acm = np.delete(acm, 0, 1)
    print(acm)

    acm = GaussJordanElimination(acm, True)

    func_array = []
    for i in range(-1, n-1):
        poly_string = "f(x) = "
        for j in range(2,-1,-1):         

            if(i == -1 and j == 2): continue 

            if (j == 2): poly_string = poly_string + str(acm[i, (3*n)-1]) + "*x**2" + " + "

            elif (j == 1): poly_string = poly_string + str(acm[i+3, (3*n)-1]) + "*x" + " + "

            else: poly_string = poly_string + str(acm[i+6, (3*n)-1])
                   
        func_array.append(poly_string)
    
    intervals = []
    for i in range(n):
        intervals.append(str(indep[i]) + " <= x <= " + str(indep[i+1]))
    
    for i in range(n):
        temp = intervals[i].replace("x", str(x_estimate))

        if (eval(temp) == True): 
            poly_string = func_array[i]
            break

    display_func_array = ""
    for i in range(n):
        display_func_array = display_func_array + func_array[i] + "\t" + intervals[i] + "\n"

    output_func.config(text=display_func_array)

    poly_string = poly_string.replace("f(x) = ", "")
    poly_string = poly_string.replace("x", str(x_estimate))

    x_output = round(eval(poly_string), 2)
    output_estimate.config(text=x_output)



# interface
window = Tk()
window.geometry("600x600")
window.title("Diet Problem Solver")

upload = Button (text="Open CSV file", command=open_file)
poly_r = Button (text="Polynomial Regression", command=PolynomialRegression)
qsi = Button (text="Quadratic Spline Interpolation", command=QuadraticSplineInterpolation)

input_x = Text(width=10, height=1)
x_label = Label(text="x")

input_degree = Text(width=10, height=1)
degree_label = Label(text="degree")

upload.place(x=10, y=10)
poly_r.place(x=10, y=110)
qsi.place(x=10, y=150)

input_x.place(x=10, y=300)
input_degree.place(x=300, y=300)
x_label.place(x=10, y=275)
degree_label.place(x=300, y=275)

output_title = Label(text="OUTPUT f(x) and estimate")
output_func = Label(text="", wraplength=590)
output_estimate = Label(text="")

output_title.place(x=10, y=380)
output_estimate.place(x=10, y=475)
output_func.place(x=10, y=400)


window.mainloop()