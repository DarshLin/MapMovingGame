#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct MAP_TILES {
	char tileSymbol;
	bool walkable = true;
};

struct Position {
	int y, x;
}player;

const int tileLength = 10;
const int tileWidth = 15;

void GenerateMap(MAP_TILES (&map)[tileLength][tileWidth]) {
	srand(time(NULL));
	//MAP_TILES map[tileLength][tileWidth];


	for (int y = 0; y < tileLength; y++) {
		for (int x = 0; x < tileWidth; x++) {
			int tileSpawn = rand() % 20; 

			if (tileSpawn == 0) {
				map[y][x].tileSymbol = 'X';
				map[y][x].walkable = false;
			}
			else {
				map[y][x].tileSymbol = 'O';
				map[y][x].walkable = true;
			}
		}
	}
	map[0][0].tileSymbol = 'O';
	map[0][0].walkable = true;
}

void PrintMap(MAP_TILES map[tileLength][tileWidth]) {
	for (int y = 0; y < tileLength; y++) {
		for (int x = 0; x < tileWidth; x++) {
			if (player.y == y && player.x == x) {
				cout << "*";
			}
			else {
				cout << map[y][x].tileSymbol;
			}
		}
		cout << endl;
	}
}

int main() {
	MAP_TILES map[tileLength][tileWidth];
	char key = 'i';
	bool running = true;

	GenerateMap(map);
	
	while (running) {
		PrintMap(map);
		cout << "Press w,a,s,d or g to quit" << endl;
		cout << ">";
		cin >> key;

		switch (key) {
		case 'w'| 'W' : 
			if (player.y > 0 && map[player.y - 1][player.x].walkable) {
				player.y--;
			}
				system("cls");
			break;
		case 's' |'S' :
			if (player.y < tileLength -1 && map[player.y + 1][player.x].walkable) {
				player.y++;
			}
				system("cls");
			break;
		case 'a' | 'A' :
			if (player.x > 0 && map[player.y][player.x - 1].walkable) {
				player.x--;
			}
				system("cls");
			break;
		case 'd' |'D' :
			if (player.x < tileWidth - 1 && map[player.y][player.x + 1].walkable) {
				player.x++;
			}
				system("cls");
			break;
		case 'g'|'G' :
			running = false;
			system("cls");
			break;
		default: player.y = 0;
			player.x = 0;
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}