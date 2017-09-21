// https://community.topcoder.com/stat?c=problem_statement&pm=13918

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class ABBA
{
public:

	string canObtain(string initial, string target)
	{
		string reversed = initial;
		reverse(reversed.begin(), reversed.end());
		bool is_reversed = false;
		while (true)
		{
			if (target.size() == initial.size())
			{
				if ((!is_reversed && target == initial) ||
					(is_reversed && target == reversed))
					return string("Possible");
				else
					return string("Impossible");
			}
			char c;
			if (!is_reversed) {
				c = target.back();
				target.pop_back();
			} else {
				c = target.front();
				target.erase(0, 1);
			}
			if (c == 'B')
				is_reversed = !is_reversed;
		}
	}
};

int main()
{
	ABBA o;
	cout << o.canObtain("B", "ABBA") << "\n";
	cout << o.canObtain("AB", "ABB") << "\n";
	cout << o.canObtain("BBAB", "ABABABABB") << "\n";
	cout << o.canObtain("BBBBABABBBBBBA", "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA") << "\n";
	cout << o.canObtain("A", "BB") << "\n";
	return 0;
}

