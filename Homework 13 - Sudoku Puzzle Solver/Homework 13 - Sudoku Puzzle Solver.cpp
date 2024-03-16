// Yara Most

// This program currently finds all valid 4x4 Sudoku grids

// There are 288 possible SOLUTIONS to this problem!
// If you just randomly put values 1-4 into each of the 16 squares,
// there would be 4,294,967,296 POSSIBILITES to try!
// This recursive method only searches 9,860 of the possibilities!

// ----------
// ASSIGNMENT
// ----------
// 1) Convert the code below to find and print out valid 9x9 grids

// If you just randomly put values 1-9 into each of the 81 squares,
// there would be 1.96627e77 POSSIBILITES to try!

// There are 6,670,903,752,021,072,936,960 SOLUTIONS so as long 
// each output is a valid grid then you have done your job

// 2) Find the solution to this specific 9x9 Sudoku puzzle:
//                 8 7 6 9 0 0 0 0 0
//				   0 1 0 0 0 6 0 0 0
//				   0 4 0 3 0 5 8 0 0
//				   4 0 0 0 0 0 2 1 0
//				   0 9 0 5 0 0 0 0 0
//				   0 5 0 0 4 0 3 0 6
//				   0 2 9 0 0 0 0 0 8
//				   0 0 4 6 9 0 1 7 3
//				   0 0 0 0 0 1 0 0 4

#include <iostream>
#include <vector>

void PrintFourByFourGrid(const std::vector<int>& grid)
{
	// changed the print statment to print 9x9 grid
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			// I tinkered with this for a while, and the best way i could come up with
			// was this, as all rows starts with multiplications of 9
			std::cout << grid[(i * 9) + j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool IsLegalRowColumnWhatever(const std::vector<int>& vector)
{
	std::vector<int> occurrences(vector.size() + 1);

	try
	{
		for (const int& i : vector)
		{
			++occurrences.at(i);
		}
	}

	catch (const std::exception&)
	{
		return false;
	}

	for (std::size_t i = 1; i < occurrences.size(); ++i)
	{
		if (occurrences[i] > 1)
		{
			return false;
		}
	}

	return true;
}

bool IsFourByFourSudokuLegal(const std::vector<int>& grid)
{
	// rows now become 9 elements starting with multiplications of 9
	int rows[] = { 0, 9, 18, 27, 36, 45, 54, 63, 72 };
	for (const int& i : rows)
	{
		std::vector<int> v{ grid[i], grid[i + 1], grid[i + 2], grid[i + 3], grid[i + 4], grid[i + 5], grid[i + 6], grid[i + 7], grid[i + 8] };
		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	// columns now become 9
	int columns[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	for (const int& i : columns)
	{
		std::vector<int> v{ grid[i], grid[i + 9], grid[i + 18], grid[i + 27], grid[i + 36], grid[i + 45],grid[i + 54], grid[i + 63], grid[i + 72] };
		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	// squares now become 3x3 
	int squares[] = { 0, 3, 6, 27, 30, 33, 54, 57, 60 };
	for (const int& i : squares)
	{
		std::vector<int> v{ grid[i], grid[i + 1], grid[i + 2], grid[i + 9], grid[i + 10], grid[i + 11], grid[i + 18], grid[i + 19], grid[i + 20] };
		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	return true;
}

void GenerateValidFourByFourGrids(std::vector<int>& grid, int index)
{
	if (index == 81)
	{
		PrintFourByFourGrid(grid);
	}
	else
	{
		// added if statmenet to check if there is a value assigned to the
		// index number already, if so, it will move to next index.

		// ************this is for part 2 of the homework********
		if (grid[index] != 0)
		{
			GenerateValidFourByFourGrids(grid, index + 1);
		}
		
		else
		// ********end of part 2 code************
		{
			for (int i = 1; i <= 9; ++i)
			{
				grid[index] = i;
				if (IsFourByFourSudokuLegal(grid) == true)
				{
					GenerateValidFourByFourGrids(grid, index + 1);
				}
			}
			grid[index] = 0;
		}

	}
}

void GenerateAllValidFourByFourGrids()
{
	// changed the size to 81
	std::vector<int> grid(81, 0);
	// ************this is for part 2 of the homework********
	grid.at(0) = 8;
	grid.at(1) = 7;
	grid.at(2) = 6;
	grid.at(3) = 9;
	grid.at(10) = 1;
	grid.at(14) = 6;
	grid.at(19) = 4;
	grid.at(21) = 3;
	grid.at(23) = 5;
	grid.at(24) = 8;
	grid.at(27) = 4;
	grid.at(33) = 2;
	grid.at(34) = 1;
	grid.at(37) = 9;
	grid.at(39) = 5;
	grid.at(46) = 5;
	grid.at(49) = 4;
	grid.at(51) = 3;
	grid.at(53) = 6;
	grid.at(55) = 2;
	grid.at(56) = 9;
	grid.at(62) = 8;
	grid.at(65) = 4;
	grid.at(66) = 6;
	grid.at(67) = 9;
	grid.at(69) = 1;
	grid.at(70) = 7;
	grid.at(71) = 3;
	grid.at(77) = 1;
	grid.at(80) = 4;
	// ********end of part 2 code************
	GenerateValidFourByFourGrids(grid, 0);
}

int main()
{
	GenerateAllValidFourByFourGrids();
	system("PAUSE");
	return 0;
}
/*
 ******* Here are some of the generated Sudoku puzzles before solving the one provided************
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 2 6 7 1 9 4 8
9 7 8 5 4 2 6 3 1
6 4 1 9 3 8 5 7 2

1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 2 6 7 8 9 4 1
6 4 1 9 3 2 5 7 8
9 7 8 5 4 1 6 3 2

1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 2 6 7 8 9 4 1
6 4 8 9 3 1 5 7 2
9 7 1 5 4 2 6 3 8

1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 2 6 7 8 9 4 1
6 7 1 9 4 2 5 3 8
9 4 8 5 3 1 6 7 2

1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 2 6 7 8 9 4 1
6 7 8 9 4 1 5 3 2
9 4 1 5 3 2 6 7 8

1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 2 6 7 8 9 4 1
9 4 1 5 3 2 6 7 8
6 7 8 9 4 1 5 3 2
*/