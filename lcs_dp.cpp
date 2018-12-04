#include <iostream>
#include <string>
#include <stdlib.h> 
#include <stdio.h> 
#include <cmath>
#include <sstream>
#include <set>

using namespace std;

// lcs n*n matrix
unsigned int lcs[21][21];
// Store all LCS strings
set<string> aoLCS;

template <typename T> string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }


int findLcsLength(string Xs, string Ys, unsigned int n)
{
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i==0 || j==0)
			{
				lcs[i][j] = 0;
			}
			else if(Xs[i-1] == Ys[j-1])
			{
				lcs[i][j] = lcs[i-1][j-1] +1 ;
			}
			else
			{
				lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
			}
//		cout<<lcs[i][j]<<" ";
		}
//		cout<<endl;
	}
	return lcs[n][n];
}

void findAllLCS(string a, string b, int n, int m, string cur) {
    if (lcs[n][m]==0) {
        aoLCS.insert(cur);
        return;
    }

    if (a[n-1] == b[m-1]) {
        findAllLCS(a, b, n-1, m-1, a[n-1]+cur);
    }
    else {
        if (lcs[n-1][m] == lcs[n][m-1]) {
            // If tie, then we need to visit both
            findAllLCS(a, b, n-1, m, cur);
            findAllLCS(a, b, n, m-1, cur);
        } else if (lcs[n-1][m] > lcs[n][m-1]) {
            findAllLCS(a, b, n-1, m, cur);
        } else {
            findAllLCS(a, b, n, m-1, cur);
        }
    }
}

string decToBinary(unsigned x, unsigned int n)
{
    string output = "";

    // counter for binary array
    int i = 0;
    while (x > 0) {
        // storing remainder in binary array
    	output = NumberToString(x%2) + output;
        x = x / 2;
        i++;
    }

    output.insert(0,n-i,'0');  //padding in the front.
    return output;
}

int main()
{
	// ask user to input x,y,n
	unsigned int n;
 	cout << "Enter value of n in range [3:20]" <<endl;
  	cin >> n;
 
 	while (cin.fail() || !(n>=3 && n<=20))
 	{
 		cout << "invalid n value."<<endl;
 		cout << "Enter value of n in range [3:20]"<<endl;
        cin.clear();
        cin.ignore();
 		cin >> n;
 	}
 
  	unsigned int x_max = pow(2,n)-1;
  	unsigned int x;
 	cout << "Enter value of x in range [0:"<<x_max<<"] :"<<endl;
  	cin >> x;
 
 	while (cin.fail() || !(x>=0 && x<= x_max))
 	{
 		cout << "invalid x value."<<endl;
 		cout << "Enter value of x in range [0:"<<x_max<<"] :"<<endl;
 		cin.clear();
 		cin.ignore();
 		cin >> x;
 	}
 
  	unsigned int y_max = pow(2,n)-1;
  	unsigned int y;
 	cout << "Enter value of y in range [0:"<<y_max<<"] :"<<endl;
  	cin >> y;
 
 	while (cin.fail() || !(y>=0 && y<= y_max))
 	{
 		cout << "invalid y value."<<endl;
 		cout << "Enter value of y in range [0:"<<y_max<<"] :"<<endl;
 		cin.clear();
 		cin.ignore();
 		cin >> y;
 	}

 	string Xs = decToBinary(x, n);
 	string Ys = decToBinary(y, n);

	// find lcs length & build up lcs matrix
 	unsigned int lcs_length = findLcsLength(Xs, Ys, n);
 	findAllLCS(Xs, Ys, n, n, "");

 	//print result:
 	cout<<"string length(n) = "<<n<<endl;
 	cout<<"X=("<< x <<")="<< Xs <<endl;
 	cout<<"Y=("<< y <<")="<< Ys <<endl;
 	cout<<"LCS length of (X,Y) = "<<lcs_length<<endl;
 	cout<<"total number of LCS = "<<aoLCS.size()<<endl;
 	int i = 1;
 	for (std::set<string>::iterator it=aoLCS.begin(); it!=aoLCS.end(); ++it){
 		cout<<"lcs " << i << ":" << *it <<endl;
 		i += 1;
 	}

 	return 0;
}
