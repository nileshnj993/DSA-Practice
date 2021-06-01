
#include <bits/stdc++.h>
using namespace std;

// bool greater(int x,int y){ this is how the greater comparator function works
//	return x>y;
//}

// Pairs
void explainPair(){
	pair<int,int> p = {1,2};
	cout<<p.first<<" "<<p.second<<endl; // prints first value and second value
	pair<int,pair<int,int>> p1 = {1,{2,3}}; // int pair with another pair of two int
	cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;
	pair<int,int> arr[] = {{1,2},{3,4},{5,6}}; // array of pairs
	cout<<arr[0].second<<endl;
	for(int i=0;i<3;i++){
		cout<<arr[i].first<<" ";
	}
	cout<<endl;
}

// Vectors - dynamic allocation - variable size arrays
void explainVector(){
	vector<int> v = {1,2,3,4,5}; // making a dynamic sized array
	cout<<v.size()<<endl;
	vector<pair<int,pair<int,int>>> v1; // making an array of int-pair pairs
	v1.push_back({1,{1,2}});
	cout<<v1[0].second.first<<endl;
	vector<int> v2(5,100); // defining vector of size 5 with all elements as 100
	cout<<v2[0]<<" "<<v2.size()<<endl;
	vector<int> v3(5); // defining vector of size 5 with all elements as 0 / garbage value
	cout<<v3[0]<<endl;
	vector<int> v4(v); // v4 stores all values in v 
	cout<<v[0]<<endl;
	auto it = v.begin(); // pointer to beginning or array - auto automatically assigns data type based on value assigned
	for(it=v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	}
	// v.end() points to an address after the last value 
	cout<<endl;
	auto it1 = v.rbegin(); // reverse begin - points to last value
	auto it2 = v.rend(); // reverse end - points to value before first value
	cout<<v.back()<<endl; // back() gives last element

	v.erase(v.begin()); // remove element at given iterator
	v.erase(v.begin()+1); // erases one element after begin
	for(it=v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	vector<int> v5 = {1,2,3,4,5};
	v5.erase(v5.begin(),v5.begin()+3); // erasing values within a range - upper bound not included
	for(auto it3 = v5.begin();it3!=v5.end();it3++){
		cout<<*it3<<" ";
	}
	cout<<endl;

	vector<int> v6;
	v6.insert(v6.begin(),1); // inserting 1 at begin
	v6.insert(v6.begin()+1,2,23); // inserting two 23's starting from begin()+1
	auto it4 = v6.begin();
	for(it4=v6.begin();it4!=v6.end();it4++){
		cout<<*it4<<" ";
	}
	cout<<endl;

	vector<int> v7 = {2,3,4,5,6};
	v6.insert(v6.begin(),v7.begin()+1,v7.end()); // inserting values from v7.begin()+1 to v7.end() at v6.begin()
	for(it4=v6.begin();it4!=v6.end();it4++){
		cout<<*it4<<" ";
	}
	cout<<endl;

	v7.pop_back(); // removes last element
	for(it4=v7.begin();it4!=v7.end();it4++){
		cout<<*it4<<" ";
	}
	cout<<endl;

	v7.clear(); // erases all values in vector

	vector<int> v8 = {3,1,14,34,21};
	sort(v8.begin(),v8.end());
	for(auto it = v8.begin();it!=v8.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	sort(v8.begin(),v8.end(),greater<int>()); // sorting in descending order
	for(auto it = v8.begin();it!=v8.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;

}

void explainList(){ // prefer vectors over list as vectors are much faster
	list<int> ls;
	ls.push_back(1);
	auto it = ls.begin();
	for(it=ls.begin();it!=ls.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	ls.push_front(5); // push at front. Equivalent to v.insert(v.begin(),5)
	for(it=ls.begin();it!=ls.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;

	// Every other method is same as in vectors.
}

void explainDeque(){
	deque<int> dq;
	dq.push_back(5); // push at end
	dq.push_front(1); // push at front
	dq.push_back(3);
	auto it = dq.begin();
	for(it=dq.begin();it!=dq.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	dq.pop_back(); // erase last element
	dq.pop_front(); // erase first element
	for(it=dq.begin();it!=dq.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;

	// Every other method is same as in vectors.
}

void explainStack(){ // LIFO
	stack<int> st;
	for(int i=0;i<5;i++){
		st.push(i+1); // pushing into stack
	}
	int n = st.size();
	for(int i=0;i<n;i++){
		cout<<st.top()<<endl; // printing top most element
		st.pop(); // popping one by one
	}
	// stacks use LIFO - Last In First Out
	// top = -1, push -> ++top, pop -> top--
}

void explainQueue(){ // FIFO
	queue<int> q;
	for(int i=0;i<5;i++){
		q.push(i+1); // pushing into queue [1,2,3,4,5]
	}
	q.pop(); // as it is FIFO - first element is popped. [2,3,4,5]
	cout<<q.back()<<" "<<q.front()<<endl; // print last and first element
	q.back() = q.back()+5; // add 5 to value at back()
	cout<<q.back()<<endl;
	// Queues use LIFO - Last In First Out
	// front = rear = -1, push-> ++rear, pop-> ++front

}

void explainPQ(){ // priority queue
priority_queue<int> pq; // acts as max heap - pushes in descending order, pops from front.
pq.push(5);
pq.push(3);
pq.push(10);
pq.push(1);
cout<<pq.top()<<endl;
pq.pop();
cout<<pq.top()<<endl;

// if we want in ascending order - min heap
priority_queue<int,vector<int>,greater<int>> pq1; // uses greater comparator function to store in ascending order
pq1.push(1);
pq1.push(10);
pq1.push(5);
pq1.push(0);
cout<<pq1.top()<<endl;
}

void explainSet(){ // stores unique elements in sorted order
	set<int> s; // unordered_set for no sort but no duplicate - O(1) insertion
	s.insert(1);
	s.insert(10); // inserts in ascending order
	s.insert(3);
	s.insert(3); // duplicate elements not allowed
	for(auto it=s.begin();it!=s.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	auto it = s.find(3); // returns iterator pointing to where 3 is
	auto it1 = s.find(6); // returns pointer to s.end() if element not found. This can be used to check if element exists in set or not
	if(it1!=s.end()){
		cout<<"Element found!"<<endl;
	}
	else{
		cout<<"Element not found!"<<endl;
	}
	s.erase(1); // can erase by value
	auto it2 = s.find(3);
	s.erase(it2); // can also erase by iterator
	for(auto it=s.begin();it!=s.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;

	set<int> s1;
	s1.insert(2);
	s1.insert(3);
	s1.insert(1);
	s1.insert(10);
	s1.insert(8);
	it1 = s1.find(1);
	it2 = s1.find(8);
	s1.erase(it1,it2); // upper bound ignored - removes 1,2,3
	for(it=s1.begin();it!=s1.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;

	// Upper bound and lower bound functions also exist
}

void explainMultiSet(){
	multiset<int> ms; // sorted but duplicate elements allowed
	ms.insert(1);
	ms.insert(4);
	ms.insert(2);
	ms.insert(3);
	ms.insert(1);
	ms.erase(1); // removes all 1's in set
	ms.insert(2);
	ms.insert(2);
	cout<<ms.count(2)<<endl; // gives number of occurences of element
	for(auto it = ms.begin();it!=ms.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	// ms.erase(2) will erase all 2's. What if we want to just remove first 2.
	ms.erase(ms.find(2)); // erases only first '2'
	for(auto it = ms.begin();it!=ms.end();it++){
		cout<<*it<<" ";
	}
	// ms.erase(ms.find(1),ms.find(1)+2); // can erase ranges too
}

void explainMap(){
	map<int,int> mp; // key,value pairs
	map<string,pair<int,int>> mp1;
	mp[1] = 2; // inserting a key-value pair
	mp.insert({2,3});
	mp[4] = 5;
	mp[3] = 6; 
	// maps are sorted according to the key
	mp1["Name"] = {10,20};
	for(auto it : mp){
		cout<<it.first<<":"<<it.second<<endl;
	}
	cout<<mp1["Name"].first<<" "<<mp1["Name"].second<<endl;
	auto it = mp.find(1); // points to 1
}

bool comp(pair<int,int>p1,pair<int,int>p2){
	if(p1.second<p2.second)
		return true;
	else if(p2.second==p1.second){
		if(p1.first>p2.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

void extra(){
	vector<int> v;
	v.push_back(2); v.push_back(1); v.push_back(3);
	sort(v.begin(),v.end(),greater<int>()); // sort in descending order - without <greater> it'll print in ascending order
	for(auto it = v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	// write a function to sort pairs based on second element. if second same, sort based on first in descending order
	// {{1,2},{2,1},{4,1}}
	pair<int,int> a[] = {{1,2},{2,1},{4,1}};
	sort(a,a+3,comp);
	for(auto it : a){
		cout<<it.first<<" ";
	}
	cout<<endl;
	int num = 6;
	int count = __builtin_popcount(num); // gives number of 1's in the number
	cout<<count<<endl;
	// if number too big, use __builtin_popcountll(num)
	string s = "123";
	do{
		cout<<s<<" ";
	}
	while(next_permutation(s.begin(),s.end())); // prints all permutations greater than starting permutation
	int arr[] = {5,1,2,32,12,1};
	cout<<endl;
	cout<<*max_element(arr,arr+6); // gives max element in an array
}

void second_max(unordered_set<int> s){
	s.erase(*max_element(s.begin(),s.end()));
	cout<<*max_element(s.begin(),s.end())<<endl;
}

int main(){
	// explainPair();
	// explainVector();
	// explainList();
	// explainDeque();
	// explainStack();
	// explainQueue();
	// explainPQ();
	// explainSet(); // unordered set very useful - O(1) - no lower bound and upper bound applicable
	// explainMultiSet();
	explainMap(); // maps don't store duplicate key-value pairs. Multimaps can store duplicate key-value pairs. mp[key] can't be used here. unordered_map can be used for faster insertion - it isn't sorted.
	// use unordered_map or unordered_set if getting tle with set/map
	// extra();
	unordered_set<int> s = {1,2,5,32,23,1};
	// second_max(s);
}