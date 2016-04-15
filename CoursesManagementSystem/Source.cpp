#include <iostream>
#include <string>
using namespace std;

void main()
{
	string **p;
	int size;
	string course;
	cout << "enter the no. of courses of the university" << endl;
	cin >> size;
	p = new string*[size];//dynamic array and pointers point at it size hee is row
	for (int i = 0; i < size; ++i)
	{
		p[i] = new string[size];//p kl mraya t7gz mkan f 3nd awl pointer p[0] 7gzt awl mkan
		//columns
	}
	p[0][0] = "DB"; p[0][1] = "Programming"; p[0][2] = "Logic";
	p[1][0] = "Compiler"; p[1][1] = "CS"; p[1][2] = "DS";
	p[2][0] = "algorithm"; p[2][1] = "math"; p[2][2] = "DS";
	cout << "enter the course u want to take" << endl;
	cin >> course;
	for (int i = 0; i < size; i++)
	{
		if (p[i][0] == course)
		{
			int y = i;
			for (int y = 1; y < size; y++)
			{
				cout << "the prequisite of this course is " << p[i][y] << endl;
			}
		}
	}
	system("pause");
}

