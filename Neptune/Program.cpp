#include <iostream>
#include "Neptune.h"

int main() {
	Neptune::InitWindow(1280, 800, "Neptune");
	
	while (Neptune::IsWindowRunning()) {

	}

	Neptune::CloseWindow();
	return 0;
}