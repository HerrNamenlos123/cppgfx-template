
#include "cppgfx/cppgfx.hpp"
#include "algorithm.h"

// Do not write global variables here.
// Use your application class in order to avoid lifetime issues.

struct Ball {
    glm::vec2 pos;
    glm::vec2 vel;
    float radius;
    sf::Color color;
};

// This is your application class which contains all variables and functions
class App : public cppgfx::App {
public:

    // Place all your variables here
    std::vector<Ball> balls;

    // This function is called once at the beginning of the program
    void setup() override {
        // Calling the C init function
        c_init();

        size(1024, 768);
        setTitle("My C++ Application");

        balls.push_back(Ball({ { 10, 10 }, { 500, 500 }, 10, sf::Color::Green }));
    }

    // This function is called repeatedly until the program is terminated
    void update() override {
        // Calling the C loop function
        c_loop();

        // Spawn new balls
        if (mousePressed) {
            for (int i = 0; i < 1; i++) {  // How many balls to spawn every frame
                // Random starting velocity
                glm::vec2 vel = {random(-400, 400), random(-200, 400)};

                // Random color
                sf::Color color = sf::Color(randomInt(0, 255), randomInt(0, 255), randomInt(0, 255));

                balls.push_back(Ball({{mouseX, mouseY}, vel, 10, color}));
            }
        }

        // Update the position of the circle
        for (auto& ball : balls) {
            ball.vel.y += 1000 * frameTime;    // Gravity
            auto distance = ball.vel * frameTime;
            ball.pos += distance;

            if (ball.pos.x <= ball.radius || ball.pos.x >= width - ball.radius) {
                ball.pos.x = clamp(ball.pos.x, ball.radius, width - ball.radius);
                ball.vel *= 0.9;
                ball.vel.x *= -1;
            }
            if (ball.pos.y <= ball.radius || ball.pos.y >= height - ball.radius) {
                ball.pos.y = clamp(ball.pos.y, ball.radius, height - ball.radius);
                ball.vel *= 0.9;
                ball.vel.y *= -1;
            }
            fill(ball.color);
            circle(ball.pos.x, ball.pos.y, ball.radius);
        }

        // Remove the first ball that lies on the ground
        for (size_t i = 0; i < balls.size(); i++) {
            auto distance = balls[i].vel * frameTime;
            // If the ball is almost standing still
            if (glm::length(distance) <= 1 && balls[i].pos.y > height - balls[i].radius - 5) {
                balls.erase(balls.begin() + i);
                break;
            }
        }

        // Status prints
        push();
        noStroke();
        fill(155, 237, 47);
        textSize(15);
        text(fmt::format("FPS: {:.02f}", frameRate), 10, 10);
        text(fmt::format("Number of Balls: {}", balls.size()), 10, 30);
        pop();

        // Welcome screen example
        push();
        noStroke();
        fill(255);
        textSize(48);
        textAlign(TextAlign::Center);
        text("Welcome to cppgfx!", width / 2.0, 150);
        textSize(24);
        text("Click to see some magic!", width / 2.0, 200);
        pop();

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
