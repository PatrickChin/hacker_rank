// https://community.topcoder.com/stat?c=problem_statement&pm=13918

#include <string>
#include <algorithm>

using namespace std;

class ABBA
{
public:
    string canObtain(string const &initial, string target)
    {
        bool is_reversed = false;
        while (target.size() != initial.size())
        {
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

        if ((!is_reversed && target == initial) ||
            (is_reversed && equal(target.begin(), target.end(), initial.rbegin())))
            return string("Possible");
        else
            return string("Impossible");
    }
};

#ifdef CHECK
#include <iostream>

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
#endif
