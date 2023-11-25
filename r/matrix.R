
AugCoeffMatrix <- function(list){ # accepts a list as parameter
  len = length(list) # number of equations
  expr_list = list()
  
  for (i in 1:len){
    expr_list[[i]] = deparse(list[[i]])
  }
  
  # exits AugCoeffMatrix function if unequal parameters
  if (variableCheck(expr_list) == FALSE) return(NA)
  
  # splits each expression into terms
  expr_terms = list()
  for (i in 1:len){
    # [[i]][2] accesses the expression part of the deparsed equation in each expr_list element
    expr_terms[i] = strsplit(expr_list[[i]][2],"\\+") 
  }
  
  # removes spaces in each term
  for (i in 1:len){
    expr_terms[[i]] = gsub(" ", "", expr_terms[[i]])
  }
  
  # print(expr_list)
  print(expr_terms)
  
  # gets the variable list
  var_list = substring(expr_list[[1]][1], 11, nchar(expr_list[[1]][1]) - 2)
  var_list = strsplit(var_list, "\\, ")

  # gets n from xn of var_list
  n = substring(var_list[[1]][length(var_list[[1]])], 2)
  n = strtoi(n)
  
  # empty acm matrix and rhs
  acm_matrix = matrix(ncol = n, nrow = len, dimname = list(1:len, var_list[[1]]))
  rhs = matrix(nrow = len, dimname = list(1:len, "RHS"))
  
  # loop through expr_terms
  # loop through vector
  
 
  temp = list()
  # term = expr_terms[[1]][1]
  # temp = strsplit(term, "\\*")
  # print(temp)
  # acm_matrix[1, 1] = temp[[1]][1]
  
  for (i in 1:len){
    print("@@@")
    for (j in 1:n+1){
      print("@@@")
      l = nchar(expr_terms[[i]][j])
      term = expr_terms[[i]][j]
      term_var = substring(expr_terms[[i]][j], l-1)
      
      if (var_list[j] == term_var) {
        
        temp = strsplit(term, "\\*")
        acm_matrix[i, j] = temp[[1]][1]
      }else{
        rhs[i,j] = temp[[1]][1]
      }
      
    } # end for j for loop
  }

  acm_list = list(variables = var_list[[1]], augcoeffmatrix = cbind(acm_matrix, rhs))
  return(acm_list)
}

# checks if parameters of equations match
variableCheck <- function(expr_list){
  for (i in 1:(length(expr_list) - 1)){
    if(expr_list[[i]][1] != expr_list[[i+1]][1]) return(FALSE)
  }
  return(TRUE)
}


E1 <- function (x1, x2, x3) 0.3 * x1 + -0.2 * x2 + 10 * x3 + -71.4;
E2 <- function (x1, x2, x3) 3 * x1 + -0.2 * x3 + -0.1 * x2 + -7.85;
E3 <- function (x1, x2, x3) 0.1 * x1 + 7 * x2 + -0.3 * x3 + 19.3;
system <- list(E1, E2, E3);

result1 = AugCoeffMatrix(system)
