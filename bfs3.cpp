#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int cities,
					vector<vector<int> >& flights,
					int src, int dst, int stops)
{
	unordered_map<int,
				vector<pair<int, int> > >
		adjList;
	for (auto flight : flights) {
		adjList[flight[0]].push_back(
			{ flight[1], flight[2] });
	}
	queue<pair<int, int> >
		q;
	q.push({ src, 0 });
	int srcDist = INT_MAX;
	while (!q.empty() && stops-- >= 0) {

		int qSize = q.size();

		for (int i = 0; i < qSize; i++) {
			pair<int, int> curr = q.front();
			q.pop();

			for (auto next : adjList[curr.first]) {
				if (srcDist < curr.second
								+ next.second)
					continue;

				q.push({ next.first,
						curr.second
							+ next.second });

				if (dst == next.first) {
					srcDist = min(
						srcDist, curr.second
									+ next.second);
				}
			}
		}
	}

	return srcDist == INT_MAX ? -1 : srcDist;
}
int main()
{
	vector<vector<int> > flights;
	int n,a,b,c,i;
	cin>>n;
	for(i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        vector<int> f;
        f.push_back(a);
        f.push_back(b);
        f.push_back(c);
        flights.push_back(f);

    }
	int k;
	int src;
	int dest ;
	cin>>src>>dest>>k;
	long ans = findCheapestPrice(
		n, flights,
		src, dest,
		k);
	cout << ans;
	return 0;
}
