#include <iostream>
using namespace std;

float add(float f1, float f2) 
{
	return f1 + f2;
}

float subtract(float f1, float f2)
{
	return f1 - f2;
}

float multiply(float f1, float f2)
{
	return f1 * f2;
}

float divide(float f1, float f2)
{
	if (f2 != 0)
		return f1 / f2;
	else
		return 0;
}

void fill_array(float *arr, int x, int y, int z)
{
	for (int i = 0; i < (x*y*z); i++)
	{
		arr[i] = rand() % 10;
	}
}

void display(float *arr, int x, int y, int z)
{
	for (int i = 0; i < (x*y*z); i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	/***********************
	function pointer array.
	***********************/
	float f1, f2;
	float (*ptr[4])(float, float);
	ptr[0] = add;
	ptr[1] = subtract;
	ptr[2] = multiply;
	ptr[3] = divide;

	cout << "Float 1: ";
	cin >> f1;
	cout << "Float 2: ";
	cin >> f2;

	for (int i = 0; i < 4; i++)
		cout << ptr[i](f1, f2) << endl;

	/************************
	Hackers Challenge
	************************/
	int x, y, z;

	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	cout << "Z: ";
	cin >> z;

	/************************
	Sneaky Solution
	************************/
	float *arr1 = new float[x*y*z];
	fill_array(arr1, x, y, z);
	display(arr1, x, y, z);
	delete[] arr1;

	return 0;
}