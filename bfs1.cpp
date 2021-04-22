#include <bits/stdc++.h>
using namespace std;
#define int long long int
struct node {
	int a, b, c;
	int dist;
};
bool visited[26][26][26];
bool restricted[26][26][26];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
void solve(string start,
		string end, int qx,
		const vector<vector<string> >& forbidden)
{

	memset(visited, 0,
		sizeof(visited));
	memset(restricted, 0,
		sizeof(restricted));

	for (auto vec : forbidden) {

		string a = vec[0];
		string b = vec[1];
		string c = vec[2];

		for (auto x : a)
			for (auto y : b)
				for (auto z : c) {
					restricted[x - 'a']
							[y - 'a']
							[z - 'a']
						= true;
				}
	}
	int sa = start[0] - 'a';
	int ea = end[0] - 'a';
	int sb = start[1] - 'a';
	int eb = end[1] - 'a';
	int sc = start[2] - 'a';
	int ec = end[2] - 'a';

	if (restricted[sa][sb][sc]
		or restricted[ea][eb][ec]) {
		cout << -1 << endl;

		return;
	}
	queue<node> q;
	q.push({ sa, sb, sc, 0 });
	visited[sa][sb][sc] = true;

	while (!q.empty()) {
		node x = q.front();
		q.pop();
		if (x.a == (end[0] - 'a')
			and x.b == (end[1] - 'a')
			and x.c == (end[2] - 'a')) {

			cout << x.dist
				<< endl;
			return;
		}

		int DIST = x.dist;
		for (int i = 0; i < 6; i++) {
			int A = (x.a + dx[i] + 26) % 26;
			int B = (x.b + dy[i] + 26) % 26;
			int C = (x.c + dz[i] + 26) % 26;
			if (!restricted[A][B][C]
				and !visited[A][B][C]) {
				q.push({ A, B, C, DIST + 1 });
				visited[A][B][C] = true;
			}
		}
	}
	cout << -1 << endl;
}

signed main()
{
	string X,t;
	string Y;
	int N,i,j;
cin>>X>>Y>>N;
	vector<vector<string> > forbidden ;
	for(i=0;i<N;i++)
    {
        vector<string> t1;
        for(j=0;j<3;j++)
        {
            cin>>t;
            t1.push_back(t);

        }
        forbidden.push_back(t1);
    }
	solve(X, Y, N, forbidden);
	return 0;
}
