#include <iostream>
#include <stdio.h>
#include <vector> // dynamic arrays
#include <algorithm> // sorting in O(nlogn)
#include <set> // faster than vectors - sorting in O(logn)
#include <map> // used for mapping
#include <climits>
using namespace std;

// bool greater(int x,int y){ this is how the greater comparator function works
//	return x>y;
//}

void vector_demo(){
	vector<long long int> arr = {11,2,3,14,5};
	// cout<<arr[1];
	sort(arr.begin(),arr.end()); // sorting in O(NlogN)
	int i;

	/*for(i=0;i<arr.size();i++){ // use .size() to get length
		cout<<arr[i]<<"\t";
	}*/

	cout<<endl;
	bool present = binary_search(arr.begin(),arr.end(),2); // Binary search, first 2 parameters indicate searching range and third parameter indicates element to be searched for
	cout<<present<<endl;
	arr.push_back(100);
	arr.push_back(100);
	arr.push_back(100);
	arr.push_back(123);
	arr.push_back(124);

	/*for(i=0;i<arr.size();i++){ // use .size() to get length
		cout<<arr[i]<<"\t";
	}*/

	auto it = lower_bound(arr.begin(),arr.end(),100); // first value >= 100
	auto it2 = upper_bound(arr.begin(),arr.end(),100); // first value > 100 - in O(logn) time
	// lower_bound and upper_bound only works in sorted arrays

	cout<<*it<<"\t"<<*it2; // use * to access value at particular index
	cout<<"\n"<<it2-it<<"\n"; // normal subtraction of indices. can't print it or it2 directly. it2-it is also the number of occurrences of value at it (in this case - 3)
	sort(arr.begin(),arr.end(),greater<long long int>()); // sorts in descending order

	for(long long int &x:arr){ // modifiying values of array
		x++;
	}

	for(long long int x:arr){ // for each loop
		cout<<x<<"\t";
	}
	cout<<endl;

	auto it3 = arr.begin();
	for(it3=arr.begin();it3!=arr.end();it3++){
		cout<<*it3<<"\t";
	}


}

void set_demo(){
	set<long long int> arr;
	arr.insert(5); // automatically inserts in right position in ascending order in O(logn)
	arr.insert(2);
	arr.insert(32);
	arr.insert(-3);
	for(int x : arr){
		cout<<x<<"\t";
	}
	cout<<endl;

	auto it = arr.find(5); // searches for particular element and assigns iterator
	if(it==arr.end()){ // if element not found, iterator goes to arr.end()
		cout<<"Element not found!";
	}
	else{
		cout<<"Element "<<*it<<" found!";
	}
	cout<<endl;

	auto it2 = arr.lower_bound(-3); // as it is already sorted, no need to give arr.begin() and end()
	cout<<*it2<<endl;
	auto it3 = arr.upper_bound(-3);
	cout<<*it3<<endl;
	auto it4 = arr.upper_bound(32); // if upper bound of max passed, it returns arr.end()
	if(it4==arr.end()){
		cout<<"No upper bound exists!"<<endl;
	}

	arr.erase(32); // use to remove elements from set in O(logn) time 
	auto it5 = arr.find(32);
	if(it5==arr.end()){
		cout<<"Element not found!"<<endl;
	}
}

void map_demo(){

	map<int,int> arr;
	arr[0]=1;
	arr[1]=2; 
	arr[12313]=5; // every other index between 2-12312 is given value 0
	map<char,int> cnt; // mapping character to int
	string name = "Nilesh Jain";
	transform(name.begin(),name.end(),name.begin(),::tolower); // use to convert ::toupper or ::tolower
	cout<<name<<endl;
	for(char c:name){ // counting number of occurences of each unique character
		cnt[c]++;
	}
	for(char i : name){
		cout<<i<<":"<<cnt[i];
		cout<<endl; 
	}  
}

void PowerOfSTL(){
	// [x,y]
	// add [2,3], [10,20], [30,400] and [401,450] - no overlap
	// if we want to find which interval a certain number exists in, how do we find?

	set< pair<int,int> > arr;
	arr.insert({401,450});
	arr.insert({30,400});
	arr.insert({2,3});
	arr.insert({10,20});
	// order of insertion doesn't matter. It uses if a<c then {a,b} < {c,d} and if a==c and b<d then {a,b} < {c,d}
	auto it1 = arr.upper_bound({1,INT_MAX}); // finds the next interval than that required as INT_MAX greater than all so we have to find a strictly greater x coordinate
	if(it1==arr.begin()){
		cout<<"Doesn't lie in any interval!"<<endl;
		return;
	}
	it1--; // reached correct interval
	pair<int,int> current = *it1; // pointing to interval
	if(current.first <= 10 && current.second >= 10){ // first and last value in interval
		cout<<"Present"<<endl;
	}
	else{
		cout<<"Not present!"<<endl;
	}
}

int main(){
	vector_demo();
	// set_demo();
	// map_demo();
	// PowerOfSTL();
}