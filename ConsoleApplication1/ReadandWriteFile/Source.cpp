#include <iostream>
using namespace std;
void nhap(int& n)
{
	cin >> n;
}
int fibo(int n)
{
	int n;
	cin >> n;
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	if (n != 0 && n != 1)
		return fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n;
	nhap(n);
	cout << fibo(n);
	return 0;
}