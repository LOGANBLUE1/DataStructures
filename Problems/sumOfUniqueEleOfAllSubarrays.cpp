

int countUniqueElements(vector<int> a){
	int n = a.size();
	int n_subarrays = n * (n + 1) / 2;
	int res = 0;
	unordered_map<int, vector<int> > mp;
	for (int i = 0; i < n; i++) {
		mp[a[i]].push_back(i);
	}
	for (auto x : mp) {
		vector<int> arr = x.second;
		arr.push_back(n);
		int len = arr.size();
		int n_excl = 0;
		int p = -1;
		for (int j = 0; j < len; j++) {
			int diff = arr[j] - p - 1;

			n_excl += (diff * (diff + 1))/ 2;
			p = arr[j];
		}

		res = res + (n_subarrays - n_excl);
	}

	return res - n_subarrays;
}