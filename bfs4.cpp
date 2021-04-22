#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > graph;
map<int, int> vis;
vector<int> odd;
vector<int> even;
void bfs()
{
	int src = 1;
	queue<pair<int, int> > q;
	q.push({ src, 0 });
	vis[src] = 1;
	while (!q.empty()) {
		int node = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (dist & 1) {
			odd.push_back(node);
		}
		else {
			even.push_back(node);
		}
		for (auto i : graph[node]) {
			if (!vis.count(i)) {

				q.push({ i, (dist + 1) });
				vis[i] = 1;
			}
		}
	}
}
int main()
{
    int src,des,n;
    cout<<"enter number of vertices"<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
       cin>>src>>des;
       graph[src].push_back(des);
    }
	bfs();
	if (odd.size() < even.size()) {
		for (int i : odd) {
			cout << i << " ";
		}
	}
	else {
		for (int i : even) {
			cout << i << " ";
		}
	}
	return 0;
}

