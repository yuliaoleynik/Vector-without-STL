#include <iostream>
#include "MyVector.h"
#include <vector>
#include <cstdlib>



void ShowVector(Vector::MyVector<int>& vec)
{
	std::cout << "----------------------------------------------------"<< std::endl;
	std::cout << " Elements of  my vector : ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << "  ";
	std::cout << "\n";
	std::cout << " Size of vector : "<<vec.size()<< std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

}

void ShowVector(std::vector<int>& vec)
{
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << " Elements of vector : ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << "  ";
	std::cout << "\n";
	std::cout << " Size of vector : " << vec.size() << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

}

void Menu()
{
	std::cout << "   MyVector          " << std::endl;
	std::cout << "\n 1. Push_back()" << std::endl;
	std::cout << " 2. Pop_back()" << std::endl;
	std::cout << " 3. Clear()" << std::endl;
	std::cout << " 4. Resize()" << std::endl;
	std::cout << " 5. Swap ( Exchanges the contents of the container with those of other )" << std::endl;
	std::cout << " 6. Erase ( Removes the element at position )" << std::endl;
	std::cout << " 7. Insert ( Inserts value before the element )" << std::endl;
	std::cout << " 0. Exit" << std::endl;
}

int main()
{
	Menu();
	std::vector<int> vector;
	Vector::MyVector<int> arr;
	Vector::MyVector<int> arr1; // create another vector to show the Swap()

	srand(time(0));
	const size_t n = 6;
	int left_range = -100, right_range = 100;
	for (size_t i = 0; i < n; ++i)
	{
		int a = left_range + rand() % (right_range - left_range);
		arr1.push_back(a);
	}

	int num;
	std::cout << "\n Enter the number of function you want to check : ";
	std::cin >> num;

	while (num)
	{

		switch (num)
		{
		case 1:
		{  
			system("cls");
			Menu();
			std::cout << "\n Enter the element you want to add : ";
		    int element;
		    std::cin >> element;
		    arr.push_back(element);
			vector.push_back(element);
		    ShowVector(arr);
			ShowVector(vector);
		break;
		}
		case 2:
		{
			system("cls");
			Menu();
			arr.pop_back();
			vector.pop_back();
			ShowVector(arr);
			ShowVector(vector);
			break;
		}
		case 3:
		{
			system("cls");
			Menu();
			arr.clear();
			vector.clear();
			ShowVector(arr);
			ShowVector(vector);
			break;
		}
		case 4:
		{
			/*system("cls");
			Menu();
			arr.resize(5,123);
			vector.resize(5, 123);
			ShowVector(arr);
			ShowVector(vector);*/
			break;
		}
		case 5:
		{
			system("cls");
			Menu();
			ShowVector(arr);
			ShowVector(arr1);
			system("pause");
			arr.swap(arr1);
			system("cls");
			Menu();
			ShowVector(arr);
			ShowVector(arr1);
			break;
		}
		case 6:
		{
			system("cls");
			Menu();
			arr.erase(arr.begin()+2);
			vector.erase(vector.begin() + 2);
			ShowVector(arr);
			ShowVector(vector);
			break;
		}
		case 7:
		{
			/*system("cls");
			Menu();
			arr.insert(arr.begin() + 2, 123);
			vector.insert(vector.begin() + 2, 123);
			ShowVector(arr);
			ShowVector(vector);*/
			break;
		}
		default:
			std::cout << "fault case" << std::endl;
		}

		std::cout << "\n Enter the number of function you want to check : ";
		std::cin >> num;
	}
    return 0;
}