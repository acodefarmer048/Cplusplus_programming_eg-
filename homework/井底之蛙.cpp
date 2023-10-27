#include <iostream>

using std::cin; using std::cout;
using std::endl;

int main()
{
	int depth, climb, slide;
	cin >> depth >> climb >> slide;
	int finished=0, days=0;
	while (finished < depth) {
		++days;
		finished+=climb;
		if (finished >= depth) {
			break;
		}
		finished-=slide;
	}
	cout << days;
	return 0;
}

