#include <iostream>

#include "../include/scene.h"
#include "../include/interface.h"

// phase 0;
// #include "../tester/phase0/connectedDiffTest.h"
// #include "../tester/phase0/connectedTest.h"
#include "../tester/phase0/fullContainer.h"

// phase 1;
// #include "../tester/phase1/drain+connectedTest.h"
// #include "../tester/phase1/drainTest.h"


int main()
{
    printf("Hello, Water!\n");



	// Call GUI for init water sim
	Interface ui = Interface(testGrid);

	Scene scene = Scene();

	body_t bodies[TEST_BODY_COUNT];

	createTestBodies(bodies);

	for (size_t i = 0; i < TEST_BODY_COUNT; i++)
	{
		scene.addBody(&bodies[i]);
	}


	while(true)
	{
		scene.update();
		ui.print(bodies, TEST_BODY_COUNT);
		printf("next step\n");

		std::string temp;
		std::cin >> temp;
	}


    return 0;
}
