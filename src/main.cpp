#include <iostream>

#include "../include/scene.h"
#include "../include/interface.h"
#include "../include/GUI.h"
#include <vector>


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
	//Interface ui = Interface(testGrid);
	GUI gui = GUI();
	Scene scene = Scene();
<<<<<<< HEAD

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

=======
	std::vector bodies = std::vector<body_t>();
	
	gui.GetUserInput();
	// bodies = gui.getBodiesFromInput();

	// for (size_t i = 0; i < bodies.size(); i++)
	// {
	// 	scene.addBody(&bodies.at(i));
	// }

	// while(!WindowShouldClose()) {
	// 	scene.update();
	// 	gui.NextFrame();
	// 	// ui.print(bodies, TEST_BODY_COUNT);
	// 	//printf("next step\n");
		
	// 	// std::string temp;
	// 	// std::cin >> temp;
	// }
    
	gui.closeWindow();
>>>>>>> 4c012d1ef005e5db0e9858f3af68a5b4891c6fc3

    return 0;
}
