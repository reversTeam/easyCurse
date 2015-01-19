#include "Window/Box.class.hpp"

Box::Box(): Window() {

}

Box::Box(Window *parent, unsigned int width, unsigned int height, unsigned int x, unsigned int y): Window(parent, width, height, x, y) {
	wborder(this->_window, '|', '|', '-', '-', '+', '+', '+', '+');
}

Box::~Box() {

}



