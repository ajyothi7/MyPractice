#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> vObj;

	for(int itr = 0; itr < 5; itr++)
		vObj.push_back(rand()%100);

	cout << "size of vector : " << vObj.size() << endl;
	cout << "element at 0 : " << vObj.at(0) << endl;
	cout << "vObj.front() : " << vObj.front() << endl;
	cout << "vObj.back() : " << vObj.back() << endl;

	cout << "using []" << endl;
	for(auto itr = 0; itr < vObj.size(); itr++)
		cout << vObj[itr] << " ";
	cout << endl;

	cout << "using data()" << endl;
	int *ptr = vObj.data();
	for(auto itr = 0; itr < vObj.size(); itr++)
	{
		cout << *ptr << " ";
		ptr++;
	}
	cout << endl;

	vObj.pop_back();
	for(auto itr : vObj)
		cout << itr << " ";
	cout << endl;
	
	cout << "begin() and end()" << endl;
	for(auto itr = vObj.begin(); itr != vObj.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	cout << "rbegin() and rend()" << endl;
	for(auto itr = vObj.rbegin(); itr != vObj.rend(); itr++)
		cout << *itr << " ";
	cout << endl;

	cout << "cbegin() and cend()" << endl;
	for(auto itr = vObj.cbegin(); itr != vObj.cend(); itr++)
		cout << *itr << " ";
	cout << endl;

	cout << "crbegin() and crend()" << endl;
	for(auto itr = vObj.crbegin(); itr != vObj.crend(); itr++)
		cout << *itr << " ";
	cout << endl;

	vObj.clear();

	if(vObj.empty())		
		cout << "vector empty" << endl;

	vector<int> v1;
	vector<int> v2;

	v1.assign(5, 100);
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	int arr[] = {10, 20, 30, 40, 50};
	v1.assign(arr, arr+5);
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	v2.assign(v1.begin(), v1.end());
	for(auto itr : v2)
		cout << itr << " ";
	cout << endl;
	
	return 0;
}
