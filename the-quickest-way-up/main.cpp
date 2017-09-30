// https://www.hackerrank.com/challenges/the-quickest-way-up

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

#define GRIDSIZE 100

int main(int argc, char* argv[])
{
	int t;
	input >> t;
	while (t--)
	{
		array<int, GRIDSIZE> grid;
		for (int i = 0; i < GRIDSIZE; ++i)
			grid[i] = i;

		int n;
		input >> n;
		while (n--)
		{
			int a, b;
			input >> a >> b;
			grid[a-1] = b-1;
		}
		int m;
		input >> m;
		while (m--)
		{
			int a, b;
			input >> a >> b;
			grid[a-1] = b-1;
		}

		array<bool, GRIDSIZE> visited;
		fill(visited.begin(), visited.end(), false);
		visited[0] = true;

		vector<int> curq = { 0 };
		vector<int> nexq;

		int rolls = 0;
		bool rolling = true;
		while (rolling)
		{
			if (curq.empty())
			{
				cout << -1 << endl;
				// rolling = false;
				break;
			}

			for (int curpos : curq)
			{
				bool added_last_empty = false;
				visited[curpos] = true;
				if (curpos == GRIDSIZE-1)
				{
					cout << rolls << endl;
					rolling = false;
					break;
				}
				for (int i = curpos+6; i > curpos; --i)
				{
					if (i > GRIDSIZE-1) continue;
					if (visited[i]) continue;
					if (i != grid[i]) // ladder or snake
						nexq.push_back(grid[i]);
					else if (!added_last_empty) // add last empty grid pos
					{
						nexq.push_back(i);
						added_last_empty = true;
					}
				}
			}
			++rolls;
			swap(curq, nexq);
			nexq.clear();
		}
	}
}

