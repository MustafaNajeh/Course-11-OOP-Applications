#include <iostream>
using namespace std;

template <typename T> T MYMax(T Number1, T Number2) {

	return (Number1 > Number2) ? Number1 : Number2;
}


int main()
{
	cout << MYMax<int>(3, 6) << endl;
	cout << MYMax<double>(3.2, 6.2) << endl;
	cout << MYMax<char>('m', 'n') << endl;



}
