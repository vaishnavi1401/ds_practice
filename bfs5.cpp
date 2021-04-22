
#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int> > mat, int i, int j,
			vector<vector<int> > vis)
{ int R=mat.size();
	int C=mat[0].size();
	return (i >= 0) && (i < R) &&
		(j >= 0) && (j < C) &&
		(mat[i][j] && !vis[i][j]);
}

void BFS(vector<vector<int> > mat, vector<vector<int> > vis,
		int si, int sj)
{
int R=mat.size();
	int C=mat[0].size();
	int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	queue<pair<int, int> > q;
	q.push(make_pair(si, sj));
	vis[si][sj] = true;
	while (!q.empty()) {

		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			if (isSafe(mat, i + row[k],
					j + col[k], vis)) {
			vis[i + row[k]][j + col[k]] = true;
			q.push(make_pair(i + row[k], j + col[k]));
			}
		}
	}
}
int countIslands(vector<vector<int> > mat)
{
	int R,C;
	R=mat.size();
	C=mat[0].size();
	cout<<R<<C;
	vector<vector<int> > vis(R,vector<int >(C,0));
	int res = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mat[i][j] && !vis[i][j]) {
				BFS(mat, vis, i, j);
				res++;
			}
		}
	}

	return res;
}

// main function
int main()
{ int n,m,a;
cin>>m>>n;
    vector<vector< int> > mat;
    for(int i=0;i<m;i++)
    {
        vector<int>t;
        for(int j=0;j<n;j++)
        {
            cin>>a;
            t.push_back(a);
        }
        mat.push_back(t);
    }
	cout << countIslands(mat);

	return 0;
}

