#include <bits/stdc++.h> 
using namespace std; 

void calc(vector<vector<string> >& v) 
{ 
	//calculating size of outer vector
    int n = v.size(); 

    //to track element of n vectors
    int* p = new int[n]; 

    //initialising with 0 so that first time v[n][0]
    for (int i = 0; i < n; i++) 
        p[i] = 0; 
  
    while(true) 
    { 
    	//prints combination
        for (int i = 0; i < n; i++) 
            cout << v[i][p[i]] ; 

        //elements left
        int next = n - 1; 
        while(next >= 0 &&  (p[next] + 1 >= v[next].size())) 
            next--; 
  		
  		//when reached at end, no more elements
        if (next < 0) 
            return; 
  		
  		//if not reached to end, move to next index
        p[next]++; 
  		
        //array to right of this array current index again points to first element
        for (int i = next + 1; i < n; i++) 
            p[i] = 0; 
        cout<< ", ";
    } 
} 

int main(int argc, char** argv) 
{ 
	//reading name of file from command line
  	ifstream myfile (argv[1]);
  	string line,k="";

  	//creating 2d vector
  	vector<vector<string>> v;

  	//i denoting the outer vector
  	int i=0;

  	//reading single line from file
  	while(getline(myfile, line))
    {	
    	//creating another vector & running for loop upto length of line
    	//which excludes whitespace comma quotes from line 
    	//and finally inserting it to vector v1
    	vector<string> v1;
   		for(int j=0; j<line.size(); j++)
   		{
   			if(line[j]==' ' || line[j]==',' || line[j]=='\'' )
   				continue;
   			else
   			{
   				k=line[j];
   				v1.push_back(k); 
   			}
   		}
   		//letters of single line are stored in vector v1 and v1 is stored in vector v
   		//then i is incremented
   		v.push_back(v1);
   		i++;
    }
    calc(v);
} 
