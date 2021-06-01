int FindKthLargest(vector<int> const &A, int k){

	priority_queue<int, vector<int>, greater<>> pq(A.begin(), A.begin() + k);

	for (int i = k; i < A.size(); i++)
	{
		if (A[i] > pq.top())
		{
			pq.pop();
			pq.push(A[i]);
		}
	}
	return pq.top();
}
