// C++ program for the above problem

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define pb push_back
#define mod 1000000007

vector<int> lis[100001];
vector<int>primes;
int vis[100001];
int dis[100001];
bool isPrime(int n)
{
	for (int i = 2;
		i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
bool valid(int a, int b)
{
	int c = 0;
	while (a) {
		if ((a % 10) != (b % 10)) {
			c++;
		}
		a = a / 10;
		b = b / 10;
	}
	if (c == 1) {
		return true;
	}
	else {
		return false;
	}
}

void makePrimes(int N)
{
	int i, j;
	int L = pow(10, N - 1);
	int R = pow(10, N) - 1;
	for (int i = L; i <= R; i++) {
		if (isPrime(i)) {
			primes.pb(i);
		}
	}
	for (i = 0;
		i < primes.size(); i++) {
		for (j = i + 1;
			j < primes.size(); j++) {
			int a = primes[i];
			int b = primes[j];
			if (valid(a, b)) {
				lis[a].pb(b);
				lis[b].pb(a);
			}
		}
	}
}
void bfs(int src)
{
	queue<int> q;
	q.push(src);
	vis[src] = 1;
	dis[src] = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int x : lis[curr]) {
			if (vis[x] == 0) {
				vis[x] = 1;
				q.push(x);
				dis[x] = dis[curr] + 1;
			}
		}
	}
}

int main()
{

	int N ;
	cin>>N;
	makePrimes(N);
	int A ,B;
    cin>>A>>B;
	bfs(A);
	if (dis[B] == -1)
		cout << "-1" << endl;
	else
		cout << dis[B] << endl;

	return 0;
}
