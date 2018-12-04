# 260p_Algo
### Algorithm description
We break down into functions:
- decToBinary(x, n): Convert a integer x into a n-length bit string
- findLcsLength(a, b, n): A dp method to find the LCS length by recursion function
```
if a[i-1] == b[i-1]
    LCS[i][j] = LCS[i-1][j-1]+1
else
    LCS[i][j] = max(LCS[i][j-1]+LCS[i-1][j])
```
- findAllLCS(a, b, m, n, cur)


### Analysis of the asymptotic worst-case time complexity (θ-notation)



### How to compile
g++ -o lcs_dp lcs_dp.cpp

### Sample input and output
