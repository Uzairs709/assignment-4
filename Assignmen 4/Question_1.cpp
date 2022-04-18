#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void Word_Left_To_Right(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	bool space_check = true;

	int rand_row = 0;
	int rand_col = 0;
	int word_range = 0;
	int start = 0;
	int c = 0;
	int count = 0;

	while (!word_placed && count <= 15)
	{
		rand_row = rand() % row;
		// Selecting a random coordinate for row
		rand_col = rand() % col;
		// Selecting a random coordinate for column
		word_range = rand_col + (strlen(str) - 1);
		// The space which the word would require starting from the random position
		if (word_range < col)
		{
			c = rand_col;
			start = 0;
			space_check = true;
			while (space_check && c <= word_range)
			{

				if (arr[rand_row][c] != '*')
				{
					if (arr[rand_row][c] == str[start])
					{
						space_check = true;
					}
					else
					{
						space_check = false;
					}
				}
				c++;
				start++;
			}
			if (space_check)
			{
				for (start = 0; str[start] != '\0'; start++)
				{
					arr[rand_row][rand_col] = str[start];
					rand_col++;
				}
				word_placed = true;
			}
		}
		count++;
	}
}
void Word_Right_to_Left(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	bool space_check = true;

	int rand_row = 0;
	int rand_col = 0;
	int word_range = 0;
	int start = 0;
	int c = 0;
	int count = 0;

	while (!word_placed && count <= 15)
	{
		rand_row = rand() % row;
		rand_col = rand() % col;
		word_range = rand_col - (strlen(str) - 1);
		if (word_range >= 0)
		{
			c = rand_col;
			start = 0;
			space_check = true;
			while (space_check && c >= word_range)
			{

				if (arr[rand_row][c] != '*')
				{
					if (arr[rand_row][c] == str[start])
					{
						space_check = true;
					}
					else
					{
						space_check = false;
					}
				}
				c--;
				start++;
			}
			if (space_check)
			{
				for (start = 0; str[start] != '\0'; start++)
				{
					arr[rand_row][rand_col] = str[start];
					rand_col--;
				}
				word_placed = true;
			}
		}
		count++;
	}
}
void Word_Top_To_Bottom(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	bool space_check = true;

	int rand_row = 0;
	int rand_col = 0;
	int word_range = 0;
	int start = 0;
	int r = 0;
	int count = 0;

	while (!word_placed && count <= 15)
	{
		rand_row = rand() % row;
		rand_col = rand() % col;
		word_range = rand_row + (strlen(str) - 1);
		if (word_range < row)
		{
			r = rand_row;
			start = 0;
			space_check = true;
			while (space_check && r <= word_range)
			{

				if (arr[r][rand_col] != '*')
				{
					if (arr[r][rand_col] == str[start])
					{
						space_check = true;
					}
					else
					{
						space_check = false;
					}
				}
				r++;
				start++;
			}
			if (space_check)
			{
				for (start = 0; str[start] != '\0'; start++)
				{
					arr[rand_row][rand_col] = str[start];
					rand_row++;
				}
				word_placed = true;
			}
		}
		count++;
	}
}
void Word_Bottom_to_Top(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	bool space_check = true;

	int rand_row = 0;
	int rand_col = 0;
	int word_range = 0;
	int start = 0;
	int r = 0;
	int count = 0;

	while (!word_placed && count <= 15)
	{
		rand_row = rand() % row;
		rand_col = rand() % col;
		word_range = rand_row - (strlen(str) - 1);
		if (word_range >= 0)
		{
			r = rand_row;
			start = 0;
			space_check = true;
			while (space_check && r >= word_range)
			{

				if (arr[r][rand_col] != '*')
				{
					if (arr[r][rand_col] == str[start])
					{
						space_check = true;
					}
					else
					{
						space_check = false;
					}
				}
				r--;
				start++;
			}
			if (space_check)
			{
				for (start = 0; str[start] != '\0'; start++)
				{
					arr[rand_row][rand_col] = str[start];
					rand_row--;
				}
				word_placed = true;
			}
		}
		count++;
	}
}
void Word_TopLeft_to_Bottomright(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	bool space_check = true;

	int rand_row = 0;
	int rand_col = 0;
	int word_range_row = 0;
	int word_range_col = 0;
	int start = 0;
	int r = 0;
	int c = 0;
	int count = 0;

	while (!word_placed && count <= 15)
	{
		rand_row = rand() % row;
		rand_col = rand() % col;
		word_range_row = rand_row + (strlen(str) - 1);
		word_range_col = rand_col + (strlen(str) - 1);
		if (word_range_row < row && word_range_col < col)
		{
			r = rand_row;
			c = rand_col;
			start = 0;
			space_check = true;
			while (space_check && r <= word_range_row)
			{

				if (arr[r][c] != '*')
				{
					if (arr[r][c] == str[start])
					{
						space_check = true;
					}
					else
					{
						space_check = false;
					}
				}
				r++;
				c++;
				start++;
			}
			if (space_check)
			{
				for (start = 0; str[start] != '\0'; start++)
				{
					arr[rand_row][rand_col] = str[start];
					rand_row++;
					rand_col++;
				}
				word_placed = true;
			}
		}
		count++;
	}
}
void Word_Bottomright_To_TopLeft(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	bool space_check = true;

	int rand_row = 0;
	int rand_col = 0;
	int word_range_row = 0;
	int word_range_col = 0;
	int start = 0;
	int r = 0;
	int c = 0;
	int count = 0;

	while (!word_placed && count <= 15)
	{
		rand_row = rand() % row;
		rand_col = rand() % col;
		word_range_row = rand_row - (strlen(str) - 1);
		word_range_col = rand_col - (strlen(str) - 1);
		if (word_range_row >= 0 && word_range_col >= 0)
		{
			r = rand_row;
			c = rand_col;
			start = 0;
			space_check = true;
			while (space_check && r >= word_range_row)
			{

				if (arr[r][c] != '*')
				{
					if (arr[r][c] == str[start])
					{
						space_check = true;
					}
					else
					{
						space_check = false;
					}
				}
				r--;
				c--;
				start++;
			}
			if (space_check)
			{
				for (start = 0; str[start] != '\0'; start++)
				{
					arr[rand_row][rand_col] = str[start];
					rand_row--;
					rand_col--;
				}
				word_placed = true;
			}
		}
		count++;
	}
}

void TopPightToBottomLeft(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	bool space_check = true;

	int rand_row = 0;
	int rand_col = 0;
	int word_range_row = 0;
	int word_range_col = 0;
	int start = 0;
	int r = 0;
	int c = 0;
	int count = 0;

	while (!word_placed && count <= 15)
	{
		rand_row = rand() % row;
		rand_col = rand() % col;
		word_range_row = rand_row + (strlen(str) - 1);
		word_range_col = rand_col - (strlen(str) - 1);
		if (word_range_row < row && word_range_col >= 0)
		{
			r = rand_row;
			c = rand_col;
			start = 0;
			space_check = true;
			while (space_check && c >= word_range_col)
			{

				if (arr[r][c] != '*')
				{
					if (arr[r][c] == str[start])
					{
						space_check = true;
					}
					else
					{
						space_check = false;
					}
				}
				r++;
				c--;
				start++;
			}
			if (space_check)
			{
				for (start = 0; str[start] != '\0'; start++)
				{
					arr[rand_row][rand_col] = str[start];
					rand_row++;
					rand_col--;
				}
				word_placed = true;
			}
		}
		count++;
	}
}

void BottomLeftToTopRight(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	bool space_check = true;

	int rand_row = 0;
	int rand_col = 0;
	int word_range_row = 0;
	int word_range_col = 0;
	int start = 0;
	int r = 0;
	int c = 0;
	int count = 0;

	while (!word_placed && count <= 15)
	{
		rand_row = rand() % row;
		rand_col = rand() % col;
		word_range_row = rand_row - (strlen(str) - 1);
		word_range_col = rand_col + (strlen(str) - 1);
		if (word_range_row >= 0 && word_range_col < col)
		{
			r = rand_row;
			c = rand_col;
			start = 0;
			space_check = true;
			while (space_check && r >= word_range_row)
			{

				if (arr[r][c] != '*')
				{
					if (arr[r][c] == str[start])
					{
						space_check = true;
					}
					else
					{
						space_check = false;
					}
				}
				r--;
				c++;
				start++;
			}
			if (space_check)
			{
				for (start = 0; str[start] != '\0'; start++)
				{
					arr[rand_row][rand_col] = str[start];
					rand_row--;
					rand_col++;
				}
				word_placed = true;
			}
		}
		count++;
	}
}
bool GeneralCheck(char** array, int row, int col, char word[], int movement)
{
	int index = 0;
	for (; word[index] != '\0'; index++)
	{
		if (array[row][col] != '*')
		{
			return false;
		}
		if (movement == 1)
		{
			col++;
		}
		if (movement == 2)
		{
			col--;
		}
		if (movement == 3)
		{
			row++;
		}
		if (movement == 4)
		{
			row--;
		}
		if (movement == 5)
		{
			row++;
			col++;
		}
		if (movement == 6)
		{
			row--;
			col--;
		}
		if (movement == 7)
		{
			row++;
			col--;
		}
		if (movement == 8)
		{
			row--;
			col++;
		}
	}
	return true;
}
int main(){

	ifstream fin;
	char str1[15];
	int rand_row = 0;
	int rand_col = 0;
	int move = 0;
	int WordRangeRow = 0;
	int WordRangeCol = 0;
	int rows = 0;
	int cols = 0;
	srand(time(0));
	bool word_placed = false;
	bool space_check = true;
	char arr[10][10];
	fin.open("Input.txt");
	fin >> str1;
	int length = strlen(str1);
	while (!fin.eof()){
	
		fin >> str1;
		if (strlen(str1) > length){
		
			length = strlen(str1);
		}
	}
	fin.close();
	char** grid = 0;
	length += 2;
	rows = length;
	cols = length;
	grid = new char* [length];
	for (int i = 0; i < length; i++){
	
		grid[i] = new char[length];
	}
	for (int i = 0; i < length; i++){
	
		for (int j = 0; j < length; j++){
		
			grid[i][j] = '*';
		}
	}
	fin.open("Input.txt");
	while (!fin.eof()){
	
		fin >> str1;
		while (!word_placed){
		
			rand_row = rand() % length;
			rand_col = rand() % length;
			WordRangeRow = rand_row - (strlen(str1) - 1);
			WordRangeCol = rand_col - (strlen(str1) - 1);

			move = rand() % 8;
			if ((rand_col + (strlen(str1) - 1)) < cols){
			
				space_check = GeneralCheck(grid, rand_row, rand_col, str1, 1);
				if (space_check){
				
					Word_Left_To_Right(grid, length, length, str1);
				}
			}
			else if (move == 1){
			
				Word_Right_to_Left(grid, length, length, str1);
			}
			else if (move == 2){
			
				Word_Top_To_Bottom(grid, length, length, str1);
			}
			else if (move == 3){
			
				Word_Bottom_to_Top(grid, length, length, str1);
			}
			else if (move == 4){
			
				Word_TopLeft_to_Bottomright(grid, length, length, str1);
			}
			else if (move == 5){
			
				Word_Bottomright_To_TopLeft(grid, length, length, str1);
			}
			else if (move == 6){
			
				TopPightToBottomLeft(grid, length, length, str1);
			}
			else if (move == 7){
			
				BottomLeftToTopRight(grid, length, length, str1);
			}
		}
	}
	for (int i = 0; i < length; i++){
	
		for (int j = 0; j < length; j++){
		
			cout << grid[i][j] << "   ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}