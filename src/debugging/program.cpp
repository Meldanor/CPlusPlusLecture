#include <iostream>
#include <ctime>

char** createSomeMap();
void freeMap(char**);
void drawMap(char**);
void moveMap(char**);

int main() {
	// Don't call srand() somewhere else.
	// Use a constant number instead of clock() if you wanna see the
	// same landscape each time (e.g. for debugging purposes)
	srand(clock());

	char** map = createSomeMap();
	drawMap(map);
	while (std::cin.get() != '1') {
		moveMap(map);
		drawMap(map);
	}
	freeMap(map);
	return 0;
}
