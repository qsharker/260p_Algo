# 260p_Algo
## Requirements
Implement and analyze the time complexity of an algorithm that, given n in the range [3:20], and two integers x and y that are each in the range [0:2n-1], determines the number of distinct strings that are LCS's of binstring(n,x) and binstring(n,y) and displays them.  

Your program should

- ask the user to input an integer n within limits
- ask the user to input an integer x within limits
- ask the user to input an integer y within limits
- determine the number of distinct LCS's
- display
  - the input parameter values (n, x, y)
  - bitstrings binstring(n,x) and binstring(n,y)
  - the determined number of distinct LCS's
  - the list of those LCS's

## Algorithm description
We break down into functions:
#### decToBinary(x, n)
Convert a integer x into a n-length bit string.  
(Note: need pedding 0’s in the front to make every integer as n-bit string.)
#### findLcsLength(a, b, n)
A dp method to find the LCS length by recursion function
```
if a[i-1] == b[i-1]
    LCS[i][j] = LCS[i-1][j-1]+1
else
    LCS[i][j] = max(LCS[i][j-1]+LCS[i-1][j])
```
#### findAllLCS(a, b, m, n, cur)
A recursive function to backtrack and retrieve all LCS bits accordingly.
```
findAllLCS(a, b, m, n, cur):
    if a[n-1] == b[m-1]:
        findAllLCS(a, b, n-1, m-1, a[n-1]+cur)
	else if lcs[n-1][m] > lcs[n][m-1]:
	    findAllLCS(a, b, n-1, m, cur)
	else if lcs[n-1][m] < lcs[n][m-1]:
	    findAllLCS(a, b, n, m-1, cur)
    else:
        findAllLCS(a, b, n-1, m, cur) 
        findAllLCS(a, b, n, m-1, cur)
(stop on lcs[n][m]==0, to get whole LCS subsequence returned in “cur”)
```

## Analysis of the asymptotic worst-case time complexity (θ-notation)
#### decToBinary(x, n)
θ (n)
#### findLcsLength(a, b, n)
θ (n^2), with space memory to store all LCS[i][j] values.
#### findAllLCS(a, b, m, n, cur)
θ (2^(2n)), (in our case, input m=n)


## How to compile
    g++ -o lcs_dp lcs_dp.cpp

## Sample input and output
#### Case1: n=14, x=12642, y=5735
```
string length(n) = 14
X=(12642)=11000101100010
Y=(5735)=01011001100111
LCS length of (X,Y) = 9
total number of LCS = 12
lcs 1:000011001
lcs 2:001011001
lcs 3:010110000
lcs 4:010110001
lcs 5:010110010
lcs 6:100010111
lcs 7:100011001
lcs 8:101011001
lcs 9:110000111
lcs 10:110010111
lcs 11:110011001
lcs 12:111011001
```

#### Case2: n=20, x=948575, 8475
```
string length(n) = 20
X=(948575)=11100111100101011111
Y=(8475)=00000010000100011011
LCS length of (X,Y) = 12
total number of LCS = 7
lcs 1:000001011111
lcs 2:000010011111
lcs 3:000010101111
lcs 4:001000011111
lcs 5:001000101111
lcs 6:001001001111
lcs 7:100001001111
```

#### Case3: n=20, x=4095, y=0
```
string length(n) = 12
X=(4095)=111111111111
Y=(0)=000000000000
LCS length of (X,Y) = 0
total number of LCS = 0
```



