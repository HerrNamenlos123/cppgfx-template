
#include "cppgfx/cppgfx.hpp"
#include "algorithm.h"

// Do not write global variables here.
// Use your application class in order to avoid lifetime issues.

// This is your application class which contains all variables and functions
class App : public cppgfx::App {
public:

    // Place all your variables here
    int k = 1;

    // This function is called once at the beginning of the program
    void setup() override {
        // Calling the C init function
        c_init();

        size(1024, 768);
        setTitle("My C++ Application");
    }

    // This function is called repeatedly until the program is terminated
    void update() override {
        // Calling the C loop function
        c_loop();

        // Print example
        println("Result of my C example algorithm: {} -> {}", frameCount, c_example_algorithm(frameCount));
    }

    // This function is called once when the application is terminated
    void cleanup() override {
        // Calling the C cleanup function
        c_exit();
    }
};

// This is the entry point of the program
// Do not touch this function unless you know what you are doing
int main() {
    App app;
    app.run();
}
