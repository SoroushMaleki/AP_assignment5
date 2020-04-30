#include <iostream>
#include <cmath>
#include <vector>
#include "../RSDL-master/src/rsdl.hpp"

using namespace std;

Point mousePosition;

class Ball {
public:
	void update(Window* window) {
		float mouse_x = mousePosition.x;
		float mouse_y = mousePosition.y;
		set_target(mouse_x, mouse_y);
		move_towards_target();
	}



	void draw(Window* window)
	{
		window->fill_circle(Point(x,y), 20);
	}
	void setpos(float x_, float y_)
	{
		x = x_;
		y = y_;
	}
	void set_target(float x_, float y_){target.x = x_; target.y = y_;}
	void move_towards_target();
	float vx();
	float vy();
private:
	float x, y;
	Point target;
	float speed = 300;
};

float dist (float x1, float y1, float x2, float y2){
	float result = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	return result;
}


float Ball::vx()
{
	float result = speed * (target.x - x) / dist(x, y, target.x, target.y);
	return result;
}

float Ball::vy()
{
	float result = speed * (target.y - y) / dist(x, y, target.x, target.y);
	return result;
}


void Ball::move_towards_target()
{
	float new_x;
	float new_y;
	if(dist(x, y, target.x, target.y) == 0) {
		new_x = x;
		new_y = y;
		return;
	}

	float distance = dist(x, y, target.x, target.y);
	new_x =  x + (target.x - x)/(distance) * speed /1000.0* (1.0) * 15;
    new_y = y + (target.y - y)/(distance) * speed /1000.0 * (1.0) * 15;
	setpos(new_x, new_y);
}


Ball ball;

void update(Window* window) {
	while(window->has_pending_event()) {
		Event e = window->poll_for_event();
		switch(e.get_type()) {
			case Event::EventType::QUIT:
				exit(0);
				break;
			case Event::EventType::MMOTION:
				mousePosition = e.get_mouse_position();
				break;
		}
	}
	ball.update(window);
}

void draw(Window* window) {
	window->clear();
	ball.draw(window);
	window->draw_line(Point(300,300), Point(300,600));
	window->update_screen();
}


int main()
{
	
	Window *window = new Window(1000, 1000, "RSDL Demo");
	ball.setpos(300,300);
	
	while(true) {

		update(window);
		draw(window);
		delay(15);
	}
	
	
	return 0;
}