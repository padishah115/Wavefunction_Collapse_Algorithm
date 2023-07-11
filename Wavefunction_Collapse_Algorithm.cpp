#include <iostream>
#include <vector>
#include <random>

//Define the grid as 100x100
const int x_max = 100;
const int y_max = 100;
int square_grid[x_max][y_max] = {0};

/*
Collapse cell fxn - checks to see if tile is nonzero
"Collapse"- takes cell that could have one of a number of values and
"collapses" it onto one, single value.
*/
int collapse_cell(int x, int y) {
	if (square_grid[x][y] != 0) {
		return square_grid[x][y];
	}
	else {
		std::vector<int> possible_tiles = get_possible_tiles(x,y);
		int length = possible_tiles.size();


		int tile = 
	}
}

//Gives tiles that could be neighbours
std::vector<int> get_possible_tiles(int x, int y) {
	//Create "neighbours" list.
	std::vector<int> neighbours = {};
	std::vector<int> useful_neighbours = {};

	if(x > 0){ 
		//Append one to the left
		neighbours.push_back(square_grid[x - 1][y]);
	}

	if (x < x_max - 1) {
		//Append one to the right
		neighbours.push_back(square_grid[x + 1][y]);
	}

	if (y > 0) {
		//Append one above
		neighbours.push_back(square_grid[x][y - 1]);
	}

	if (y < y_max - 1) {
		//Append one below
		neighbours.push_back(square_grid[x][y - 1]);
	}

	for (int n : neighbours) {
		if (n != 0) {
			useful_neighbours.push_back(n);
		}
	}

	return useful_neighbours;

}

int main() {
	


	return 0;
}