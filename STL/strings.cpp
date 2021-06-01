#include <bits/stdc++.h>

using namespace std;

// treat strings as arrays

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// TAKING INPUT
	string s = "Nilesh";
	// s.clear(); - this will clear entire string
	cout<<s[0]<<" "<<s[1]<<"\n"; // can access using index. we can also do s.at(2) - this will print s[2]
	
	/* string s_1;
	   cin>>s_1; // can only use cin if string doesn't have spaces
	   cout<<s_1<<"\n";
	   string s_2;
	   getline(cin,s_2); // if string has spaces, use this
	   cout<<s_2<<"\n"; */

	// TRAVERSING
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<"\n";
	for(auto it : s){
		cout<<it<<" ";
	}
	cout<<"\n";

	// APPEND
	string s1 = "Jain";
	s.append(" "); 
	s.append(s1); // can append. s.append(" Jain");
	cout<<s<<"\n";
	s = "Nilesh ";
	s.append(s1,1,3); // starting index of s1, number of characters to append
	cout<<s<<"\n";

	// FIND
	s = "This is a test";
	s1 = "test";
	cout<<s.find(s1)<<"\n"; // returns starting index of what we search
	cout<<s.find("no")<<"\n"; // garbage value if not found

	// FIND LENGTH OF STRING
	cout<< s.size()<<"\n";
	char c[] = "Hello";
	cout<<strlen(c)<<"\n"; // use strlen if char array initialization

	// SUBSTRING
	string s_sub = s.substr(2,8);
	cout<<s_sub<<"\n";
	cout<<s.substr(2)<<"\n";

	// ERASE
	s.erase(0,4); // erase 4 characters starting from index 0
	cout<<s<<"\n";

	// COMPARE
	s.clear();
	s = "This is a test";
	
	if(s.compare("This is a test")==0){
		cout<<"Same string"<<"\n";
	}
	else if(s.compare("This is a test")>0){
		cout<<"String 1 is larger"<<"\n";
	}
	else{
		cout<<"String 2 is larger"<<"\n";
	}

	// INSERT
	s.clear();
	s = "Hello";
	s.insert(3,"hmm");
	cout<<s;
}	
