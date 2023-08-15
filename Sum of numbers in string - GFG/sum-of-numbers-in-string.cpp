//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	
    	// Your code here
    	int sum=0;
    	string temp="";
    	for(int i=0;i<str.size();i++){
    	    if(str[i]>='0' && str[i]<='9'){
    	        temp+=str[i];
    	    }else{
    	        sum+=atoi(temp.c_str());
    	        temp="";
    	    }
    	}
    	return sum+atoi(temp.c_str());
    	
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}

// } Driver Code Ends