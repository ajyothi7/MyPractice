#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str1 = "Hello";
	string str2 = "World";

	cout << "Given String1 : " << str1 << endl;
	cout << "Given String2 : " << str2 << endl;

	cout << "concat strings : " << str1 + str2 << endl;
	
	cout << "length of str1 : " << str1.length() << endl;
	cout << "length of str2 : " << str2.length() << endl;
	cout << "length of str1 + str2 : " << (str1 + str2).length() << endl;

	cout << "char at 0 in str1 - " << str1[0] << endl;
	cout << "char at 2 in str1 - " << str1[2] << endl;
	cout << "char at 3 in str1 - " << str1[3] << endl;

//	str2 = str1;

	if(str1 == str2)
		cout << "strings are equal" << endl;

	else
		cout << "strings are not equal" << endl;

	string str3;

	str3.assign(str1);
	cout << "str3.assign(str1) - " << str3 <<  endl;

	str3.assign(str2, 1, 3);
	cout << "str3.assign(str2, 1, 3) - " << str3 << endl;

	str3.assign("Hi");
	cout << "str3.assign(\"Hi\") - " << str3 << endl;

	str3.assign("HiHello", 4);
	cout << "str3.assign(\"Hi\", 4) - " << str3 << endl;

	str3.assign(4, 'a');
	cout << "str3.assign(4, 'a') - " << str3 << endl;

	cout << "int value 1234 to string - " << to_string (1234) << endl;
	cout << "float value 12.34 to string - " << to_string(12.34f) << endl;
	cout << "double value 12.34 to string - " << to_string(12.34) << endl;
	cout << "to_string(10+20+30+40) - " << to_string(10+20+30+40) << endl;
	cout << "to_string(10+20+12.34) - " << to_string(10+20+12.34) << endl;
	cout << "to_string(10/20+30*2) - " << to_string(10/20+30*2) << endl;

	string str = "Hello";

	str.append("world");
	cout << str << endl;

	str1 = "Jyothi";

	str.append(str1.begin()+2, str1.end()-2);
	cout << str << endl;

	str = "c++ programming";

	cout << str.substr(4, 10) << endl;

	str1 = "hello";
	str2 = "hello";
	str3 = "world";

	if(0 == str1.compare(str2))
		cout << "string are equal" << endl;

	else
		cout << "string are not equal" << endl;
		
	return 0;
}
