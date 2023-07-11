#include <iostream>


//Define the grid as 100x100
const int x_max = 100;
const int y_max = 100;
int square_grid[x_max][y_max] = {0};

//Collapse cell fxn- checks to see if tile is nonzero
int collapse_cell(int x, int y) {
	if (square_grid[x][y] != 0) {
		return square_grid[x][y];
	}
	else {
		get_possible_tiles[x][y];
	}
}

//Gives tiles that could be neighbors
void get_possible_tiles(int x, int y) {
	if(x > 0){ 
		//Append one to the left
		
	}

	if (x < x_max) {
		//Append one to the right
	}

	if (y > 0) {
		//Append one above
	}

	if (y < y_max) {
		//Append one below
	}
}

int main() {
	


	return 0;
}