#include <iostream>
#include <string>

using namespace std;


int DJBHash(string str)

{
	int hash = 5381;

	for(int i = 0; i < str.size(); i++)

	{

		hash = ((hash << 5) + hash) + str[i]; //hash = hash * 32 + c

	}

	return (hash & 0x7FFFFFFF);

}
int main()
{
	cout << DJBHash("abcdefg") << "  " ;
	cout << endl;
	cout << DJBHash("abefg") << "  " ;
	cout << endl;
	cout << DJBHash("acfg") << "  " ;
	cout << endl;
	cout << DJBHash("abg") << "  " ;
	cout << endl;
}
