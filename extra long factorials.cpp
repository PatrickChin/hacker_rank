// https://www.hackerrank.com/challenges/extra-long-factorials

#include <iostream>

#define MAXL 200

using namespace std;

void multiply(int a, int b[MAXL])
{
	int carry = 0;
	for (int i = 0; i < MAXL; i++)
	{
		b[i] *= a;
		b[i] += carry;
		/* cout << a << " * " << b[i] << " + " << carry; */
		if (b[i] > 9)
		{
			carry = b[i] / 10;
			b[i] %= 10;
		}
		else carry = 0;
		/* cout << " = " << carry << "+" << b[i] << endl; */
	}
	/* cout << endl; */
}

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	int *result = new int[MAXL]{0};
	for (int i = 1; i < MAXL; i++)
		result[i] = 0;
	result[0] = 1;

	for (int i = 1; i <= n; i++)
		multiply(i, result);

	bool b = false;
	for (int i = MAXL-1; i >= 0; i--)
		if (b = (result[i] != 0 || b))
			cout << result[i];
	cout << endl;

	return 0;
}

