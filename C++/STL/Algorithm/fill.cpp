#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v(10);

	fill(v.begin(), v.end(), -1);
	
	for(auto x : v)
		cout << x << "\t";

	fill(v.begin(), v.begin() + 4, 10);

	cout << endl;
	for(auto x : v)
		cout << x << "\t";

	fill(v.begin() + 4, v.end(), 20);

	cout << endl;
	for(auto x : v)
		cout << x << "\t";

	cout << endl;
	
	vector<int> v1(10);

	fill_n(v1.begin(), 10, -1);
	
	for(auto x : v1)
		cout << x << "\t";

	fill_n(v1.begin(), 4, 10);

	cout << endl;
	for(auto x : v1)
		cout << x << "\t";

	fill_n(v.begin() + 4, 6, 20);

	cout << endl;
	for(auto x : v)
		cout << x << "\t";

	cout << endl;
	
	return 0;
}
