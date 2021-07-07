#include <iostream>
#include "checkML.h"
#include "Game.h"

using namespace std;

int main(int argc, char* argv[]) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	try {
		Game();
	}
	catch(ArrowsError e){
		cout << e.what() << endl;
	}
	
	return 0;
}