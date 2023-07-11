#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <cstdlib>

//Define the grid as 100x100
const int x_max = 100;
const int y_max = 100;
std::vector<std::vector<int>> square_grid(x_max, std::vector<int>(y_max, 0));



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
		int random_index = rand() % (length - 1);

		int tile = possible_tiles[random_index];

		square_grid[x][y] = tile;
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
		neighbours.push_back(square_grid[x][y + 1]);
	}

	for (int n : neighbours) {
		if (n != 0) {
			useful_neighbours.push_back(n);
		}
	}

	return useful_neighbours;

}

//Checks to see if any elements in grid are still 0
bool anyZeros(){
	for (int i = 0; i < x_max; i++) {
		for (int j = 0; j < y_max; j++) {
			if (square_grid[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}



int main() {
	
	//Manually set a random tile to a non-zero value
	srand(time(0));
	int x_init = std::rand() % x_max;
	int y_init = std::rand() % y_max;

	const int x_i = x_init;
	const int y_i = y_init;
	square_grid[x_i][y_i] = 3;


	//INITIAL PASS
	for (int i = 0; i < x_max; i++) {
		for (int j = 0; j < y_max; j++) {
			collapse_cell(i, j);
		}
	}

	//SUBSEQUENT PASSES
	while (anyZeros()) {
		for (int i = 0; i < x_max; i++) {
			for (int j = 0; j < y_max; j++) {
				collapse_cell(i, j);
			}
		}
	}


	return 0;
}