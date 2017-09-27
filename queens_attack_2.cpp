// https://www.hackerrank.com/challenges/queens-attack-2

#include <iostream>
#include <cmath>

using namespace std;

constexpr int N  = 0;
constexpr int NE = 1;
constexpr int E  = 2;
constexpr int SE = 3;
constexpr int S  = 4;
constexpr int SW = 5;
constexpr int W  = 6;
constexpr int NW = 7;

int direction(int qx, int qy, int x, int y)
{

	if (x == qx)
		return (y > qy) ? N : S;

	if (y == qy)
		return (x > qx) ? E : W;

	int dx = x - qx;
	int dy = y - qy;
	if (abs(dx) != abs(dy))
		return -1;

	if (dx > 0)
		return (dy > 0) ?  NE : SE;
	if (dx < 0)
		return (dy > 0) ?  NW : SW;

	return -1;
}

/** Returns the number of squares between (qx, qy) and (x, y) exclusive */
int distance(int qx, int qy, int x, int y)
{
	int dx = abs(x-qx)-1;
	int dy = abs(y-qy)-1;
	return dx > dy ? dx : dy;
}


int main()
{
    int n, k, qx, qy;
    cin >> n >> k >> qy >> qx;
	int dist[8];
	dist[N] = n-qy;
	dist[E] = n-qx;
	dist[S] = qy-1;
	dist[W] = qx-1;
	dist[NE] = min(dist[N], dist[E]);
	dist[NW] = min(dist[N], dist[W]);
	dist[SE] = min(dist[S], dist[E]);
	dist[SW] = min(dist[S], dist[W]);


	// closest obstacles in each direction
	int cx[8] = {0}, cy[8] = {0};
    for (int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> y >> x;

		int dir = direction(qx, qy, x, y);
		if (dir == -1)
			continue;

		int d = distance(qx, qy, x, y);
		if (d < dist[dir])
		{
			dist[dir] = d;
			cx[dir] = x;
			cy[dir] = y;
		}
    }

	int sum = 0;
	for (int i = 0; i < 8; ++i)
		sum += dist[i];

	cout << sum << endl;
    return 0;
}
