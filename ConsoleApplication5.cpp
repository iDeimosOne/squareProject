#include "pch.h"
#include <iostream>
#include <random>

using namespace std;

struct cube
{
	int num;
	cube *right;
	cube *left;
};

cube *initCube(int num)
{
	cube *temp;
	temp = (cube*)malloc(sizeof(cube));

	temp->num = num;
	temp->left = nullptr;
	temp->right = nullptr;

	return temp;
}

cube *rightCube(int rnum, cube *root)
{
	cube *temp;
	temp = (cube*)malloc(sizeof(cube));

	temp->num = rnum;
	temp->left = nullptr;
	temp->right = nullptr;

	while (root->right != nullptr)
	{
		root = root->right;
	}
	root->right = temp;

	/*temp->num = rnum;
	temp->left = root;
	temp->right = nullptr;
	root->right = temp;*/
}

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

cube *squareCreation(cube *root)
{
	cube *temp;
	temp = root;
	for (int i = 0; i < 11; i++)
	{
		rightCube(rand() % 10 - 5, temp);
		if (temp->right != nullptr)
			temp = temp->right;
	} //Добавление элемента справа
	return root;
}

int main()
{
	int c = max(2, 5);
	srand(time_t(NULL));
	cube *mainCube;
	mainCube = initCube(rand() % 10 - 5); // 1 element
	mainCube = squareCreation(mainCube);
	//squareCreation(mainCube);
	//cout << mainCube->right << "\n" << mainCube->left << "\n" << mainCube->num;
	cout << mainCube->right->num << "\n";
	system("pause");
}
