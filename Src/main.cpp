
#include <iostream>

#include "foo.h"
#include "dbgUtils.h"

#include "services_interfaces.h"
#include <glfw/glfw3.h>

int main()
{
	std::cout<<"Hello world!\n";
	std::cout<<"Calling func1 from foo.h: "<<func1()<<'\n';
	func2();
	auto message = formatMsg("formatted message %d %s", 12, "user message");
	printMsg(message.c_str());

	CServiceIp ipservice;
	ipservice.ServiceInfo();

	#ifdef RAW_INTERFACE_SERVICES
	ipservice.ServiceInfoR();
	#endif

	GLFWwindow* window;

	if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

	window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
	// Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 	// Terminate GLFW
    glfwTerminate();

	return 0;
}


