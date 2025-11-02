#include <iostream>

#include "../include/scene.h"
#include "../include/interface.h"

// phase 0;
// #include "../tester/phase0/connectedDiffTest.h"
//#include "../tester/phase0/connectedTest.h"
//#include "../tester/phase0/connectedTest2.h"
#include "../tester/phase0/connectedTest3.h"
//#include "../tester/phase0/fullContainer.h"

// phase 1;
// #include "../tester/phase1/drain+connectedTest.h"
//#include "../tester/phase1/advancedTankNetwork.h"
// #include "../tester/phase1/drainTest.h"


int main()
{
    printf("Hello, Water!\n");

	

	// Call GUI for init water sim
	Interface ui = Interface(testGrid);

	Scene scene = Scene();

	Body bodies[TEST_BODY_COUNT];
	Hole holes[TEST_HOLE_COUNT];

	createTestBodies(bodies, holes);

	for (size_t i = 0; i < TEST_BODY_COUNT; i++)
	{
		scene.addBody(&bodies[i]);
	}

	for (size_t i = 0; i < TEST_HOLE_COUNT; i++)
	{
		scene.addHole(&holes[i]);
	}
	

	while(true)
	{
		ui.print(bodies, TEST_BODY_COUNT);
		printf("next step\n");
		
		int temp = 0;
		std::cin >> temp;

		for (int i = 0; i < temp; i++) {
			scene.update(0.0001);
		}
	}
    

    return 0;
}
