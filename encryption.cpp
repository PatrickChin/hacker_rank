// https://www.hackerrank.com/challenges/encryption/submissions

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
	string s;
	cin >> s;
	int len = s.length();
	float sqlen = sqrt(len);
	int rows = floor(sqlen);
	int cols = ceil(sqlen);
	if (rows*cols < len)
		if (cols > rows)
			rows++;
		else cols++;

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			int k = j*cols + i;
			if (k < len)
				cout << s[k];
		}
		cout << " ";
	}
}

