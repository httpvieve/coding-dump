
source("matrix.R")

swap <- function(mat, pivot, i){
    # array of indices of rows
    row_numbers = 1:nrow(mat)

    # swap row numbers in the vector
    temp = row_numbers[i]
    row_numbers[i] = pivot
    row_numbers[pivot] = temp
    
    # return pivoted matrix
    return(mat[order(row_numbers), ])
}

# accepts a labelled list with variables vector and ACM
GaussianMethod <- function(acm_list, verbose){
    n = nrow(acm_list$augcoeffmatrix)
    var_list = acm_list$variables
    # converts acm from char to numeric
    acm = matrix(as.numeric(acm_list$augcoeffmatrix), ncol = ncol(acm_list$augcoeffmatrix),
                 dimname = list(1:n, colnames(acm_list$augcoeffmatrix)))
    
    if (verbose){
        cat("---------------- INITIAL MATRIX ----------------\n")
        print(acm)
        cat("------------------------------------------------\n")
        cat("\n")
    }

    for (i in 1:(n-1)){
        
        # find pivot row of ith to nth row
        pivot_row = i; 
        for (p in i:n){
            # iterate through all elements in the column
            if(abs(acm[p,i]) > abs(acm[pivot_row,i])){
                pivot_row = p
            }
        }
        
        # exit if no unique solution
        if (acm[pivot_row, i] == 0) return(NA)
        
        # do partial pivoting
        acm = swap(acm, pivot_row, i)
        
        if (verbose){
            cat("PIVOT:\n")
            print(acm)
            cat("\n")
        }
        
        for(j in (i+1):n){
            pivot_element = acm[i,i]
            multiplier = acm[j,i] / pivot_element
            # get normalized row
            normalized_row = multiplier * acm[i, ]
            acm[j,] = acm[j,] - normalized_row 
        }
        
        if (verbose){
            cat("NORMALIZED MATRIX: \n")
            print(acm)
            cat("------------------------------------------------\n")
            cat("\n")
        }
        
    }
    
    if (verbose){
        cat("====== FINAL MATRIX ======\n")
        print(acm)
        cat("\n")
    }
    
    x = c()
    
    x[n] = acm[n,n+1] / acm[n,n]
    for (i in (n-1):1){
        x[i] = (acm[i, n+1] - sum(acm[i, (i+1):n] * x[(i+1):n])) / acm[i,i]
    }
    
    acm_solution_list = list(variables = var_list, 
                             augcoeffmatrix = acm,
                             solution = x)
    return(acm_solution_list)
  
} # end of GaussianMethod


GaussJordanMethod <- function(acm_list, verbose){
    n = nrow(acm_list$augcoeffmatrix)
    var_list = acm_list$variables
    # converts acm from char to numeric
    acm = matrix(as.numeric(acm_list$augcoeffmatrix), ncol = ncol(acm_list$augcoeffmatrix),
                 dimname = list(1:n, colnames(acm_list$augcoeffmatrix)))
    
    if (verbose){
        cat("---------------- INITIAL MATRIX ----------------\n")
        print(acm)
        cat("------------------------------------------------\n")
        cat("\n")
    }
    
    for (i in 1:n){
        if (i != n){
            # find pivot row of ith to nth row
            pivot_row = i; 
            for (p in i:n){
                # iterate through all elements in the column
                if(abs(acm[p,i]) > abs(acm[pivot_row,i])){
                    pivot_row = p
                }
            }
            
            # exit if no unique solution
            if (acm[pivot_row, i] == 0) return(NA)
            
            # do partial pivoting
            acm = swap(acm, pivot_row, i)
            
            if (verbose){
                cat("PIVOT:\n")
                print(acm)
                cat("\n")
            }
        }
        
        # divide row by pivot element
        acm[i,] = acm[i,] / acm[i,i]
        
        if (verbose){
            cat("DIVIDE ROW BY PIVOT ELEMENT:\n")
            print(acm)
            cat("\n")
        }

        
        for(j in 1:n){
            if (i == j) next

            # normalize rows
            normalized_row = acm[j,i] * acm[i, ]
            acm[j,] = acm[j,] - normalized_row 
        }
        
        if (verbose){
            cat("NORMALIZED MATRIX: \n")
            print(acm)
            cat("------------------------------------------------\n")
            cat("\n")
        }
        
    }
    
    if (verbose){
        cat("====== FINAL MATRIX ======\n")
        print(acm)
        cat("\n")
    }
    
    # gets the RHS column and puts it in a solution vector
    x = c()
    for (sol in 1:n){
        x[sol] = acm[sol, n+1]
    }
    
    acm_solution_list = list(variables = var_list, 
                             augcoeffmatrix = acm,
                             solution = x)
    return(acm_solution_list)
    
} # end of GaussJordanMethod


# test-1 using example from lecture
# E1 <- function (x1, x2, x3) 25 * x1 + 5 * x2 + 1 * x3 + -106.8;
# E2 <- function (x1, x2, x3) 64 * x1 + 8 * x2 + 1 * x3 + -177.2;
# E3 <- function (x1, x2, x3) 144 * x1 + 12 * x2 + 1 * x3 + -279.2;
# 
# system <- list(E1, E2, E3);
# result = AugCoeffMatrix(system)
# result
# 
# answer = GaussianMethod(result, FALSE)
# answer
# answer = GaussJordanMethod(result, FALSE)
# answer
# end of test-1


# test-2 solving word problem 1
var_list = c('GenAdB', 'GenAdA', 'UpBoxB', 'UpBoxA',
             'LowBoxB', 'LowBoxA', 'VIP', 'Royalty')

colnames = var_list
colnames = append(colnames, 'Total Profit')
rownames = c('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H')

A = c(8000, 4500, 4000, 3000, 2000, 1000, 900, 250, 143145000)
B = c(7800, 6500, 5800, 0, 3100, 1600, 1000, 300, 158870000)
C = c(10000, 0, 3100, 0, 2600, 1300, 850, 150, 108440000)
D = c(5200, 3700, 3100, 2700, 2400, 1800, 1200, 450, 143805000)
E = c(7700, 7100, 0, 5700, 5100, 1300, 950 , 95, 181390500)
F = c(9300, 8700, 6100, 5100, 4000, 1000, 700, 70, 209273000)
G = c(6000, 0, 5000, 4300, 3000, 1900, 1400, 920, 174388000)
H = c(8500, 3700, 4200, 3900, 3500, 2400, 1000, 250, 183065000)

acm <- matrix(ncol = 9, nrow = 8, dimnames = list(rownames, colnames))
acm[1,] = A
acm[2,] = B
acm[3,] = C
acm[4,] = D
acm[5,] = E
acm[6,] = F
acm[7,] = G
acm[8,] = H

acm
problem1 <- list(variables = var_list, augcoeffmatrix = acm)

answer = GaussianMethod(problem1, FALSE)
answer
answer = GaussJordanMethod(problem1, FALSE)
answer
# end of test-2


# test-3 solving word problem 2
# var_list = c('x1', 'x2', 'x3', 'x4', 'x5', 'x6', 'x7', 'x8', 'x9')
# 
# colnames = var_list
# colnames = append(colnames, 'RHS')
# rownames = c(1:9)
# 
# acm <- matrix(ncol = 10, nrow = 9, dimnames = list(rownames, colnames))
# acm[1,] = c(-4, 1, 0, 1, 0, 0, 0, 0, 0, -80)
# acm[2,] = c(1, -4, 1, 0, 1, 0, 0, 0, 0, -30)
# acm[3,] = c(0, 1, -4, 0, 0, 1, 0, 0, 0, -80)
# acm[4,] = c(1, 0, 0, -4, 1, 0, 1, 0, 0, -50)
# acm[5,] = c(0, 1, 0, 1, -4, 1, 0, 1, 0, 0)
# acm[6,] = c(0, 0, 1, 0, 1, -4, 0, 0, 1, -50)
# acm[7,] = c(0, 0, 0, 1, 0, 0, -4, 1, 0, -120)
# acm[8,] = c(0, 0, 0, 0, 1, 0, 1, -4, 1, -70)
# acm[9,] = c(0, 0, 0, 0, 0, 1, 0, 1, -4, -120)
# 
# acm
# problem2 <- list(variables = var_list, augcoeffmatrix = acm)
# 
# answer = GaussianMethod(problem2, FALSE)
# answer
# answer = GaussJordanMethod(problem2, FALSE)
# answer
# end of test-3