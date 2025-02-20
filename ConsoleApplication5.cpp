#include <iostream>
#include <string>

using namespace std;

class Point
{
private:
	int x;
	int y;
	int z;

	int size;
	int* arr;

public:

	int GetX() { return x; }
	int GetY() { return y; }
	int GetZ() { return z; }

	void SetX(int value) { x = value; }
	void SetZ(int value) { z = value; }
	void SetY(int value) { y = value; }

	Point()
	{
		x = 0;
		y = 0;
		z = 0;

		size = 5;
		arr = new int[size];
	}

	Point(int x, int y, int z, int size)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->size = size;

		arr = new int[size];
	}

	Point(const Point& original)
	{
		this->x = original.x;
		this->y = original.y;
		this->z = original.z;
		this->size = original.size;

		this->arr = new int[original.size];

		for (int i = 0; i < original.size; i++)
		{
			this->arr[i] = original.arr[i];
		}
	}

	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		this->size = other.size;

		if (arr != nullptr)
		{
			delete[] arr;
		}

		this->arr = new int[other.size];

		for (int i = 0; i < other.size; i++)
		{
			this->arr[i] = other.arr[i];
		}

		return *this;
	}

	Point& operator - (const Point& other)
	{
		Point temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;
		temp.z = this->z - other.z;

		return temp;
	}
	bool operator < (const Point& other)
	{
		return x < other.x;
		return y < other.y;
		return z < other.z;

	}
	bool operator > (const Point& other)
	{

		return x > other.x;
		return y > other.y;
		return z > other.z;
	}
	Point& operator ++ ()
	{
		x++;
		y++;
		z++;
		return *this;
	}

	~Point()
	{
		delete[] arr;
	}
};

int main()
{
	setlocale(LC_ALL, "Ru");

	Point a(4, 2, 2, 6);

	Point b(3, 2, 2, 8);

	Point c;

	if (a < b) {
		cout << "a < b" << endl;
	}
	if (a > b)
	{ 
		cout << "a > b" << endl;
	}
	a.operator++ ();
	b.operator++ ();
	cout << a.GetX() << endl;
	cout << b.GetX() << endl;

	c = a - b;
	cout << c.GetX() << endl;

}