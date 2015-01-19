#include "Window.class.hpp"

Window::Window():
	_width(0),
	_height(0),
	_x(0),
	_y(0),
	_parent(NULL),
	_window(NULL)
{

}

Window::~Window()
{
	if (this->_window) {
		if (this->_parent)
			this->_parent->clear();
		wclear(this->_window);
		delwin(this->_window);
		if (this->_parent)
			this->_parent->apply();
	}
}

Window::Window(Window const &o) {
	*this = o;
}

Window::Window(Window *parent, unsigned int width, unsigned int height, unsigned int x, unsigned int y):
	_width(width),
	_height(height),
	_x(x),
	_y(y),
	_parent(parent)
{
	if (parent == NULL)
		this->_window = newwin(this->getHeight(), this->getWidth(), this->getAbsoluteY(), this->getAbsoluteX());
	else
		this->_window = subwin(parent->getWindow(), this->getHeight(), this->getWidth(), parent->getAbsoluteY() + y, parent->getAbsoluteX() + x);
}

unsigned int			Window::getWidth()		const { return (this->_width);	}
unsigned int			Window::getHeight()		const { return (this->_height);	}
unsigned int			Window::getX()			const { return (this->_x);		}
unsigned int			Window::getY()			const { return (this->_y);		}
t_window				*Window::getWindow()	const { return (this->_window);	}

unsigned int			Window::getAbsoluteX()	const {
	if (this->_parent != NULL)
		return (this->_x + this->_parent->getX());
	else
		return (this->getX());
}

unsigned int			Window::getAbsoluteY()	const {
	if (this->_parent != NULL)
		return (this->_y + this->_parent->getY());
	else
		return (this->getY());
}

Window					&Window::operator=(Window const &o) {
	this->_parent = o._parent;
	this->_width = o._width;
	this->_height = o._height;
	this->_x = o._x;
	this->_y = o._y;
	return (*this);
}

Window					*Window::setBackgroundColor(unsigned int color) {
	if (this->_window != NULL)
		wbkgd(this->_window, COLOR_PAIR(color));
	return (this);
}

Window					*Window::printl(std::string const &str) {
	std::string		s;

	s = str + "\n";
	this->print(s);
	return (this);
}

Window					*Window::print(std::string const &str) {
	if (this->_window != NULL)
		wprintw(this->_window, str.c_str());
	return (this);
}

Window					*Window::printCenter(std::string const &str) {
	std::string				s;
	if (this->_window == NULL)
		return (this);
	if (str.length() < this->_width) {
		for (unsigned int i =  0; i < (this->_width - str.length()) / 2; ++i)
			s += " ";
		s += str;
	} else {
		s = str;
	}
	wprintw(this->_window, s.c_str());
	return (this);
}

Window					*Window::printCenter(const unsigned int n) {
	std::string				str;
	std::stringstream		ss;

	ss <<  n;
	str = ss.str();
	this->printCenter(str);
	return (this);
}

Window					*Window::print(unsigned int &n) {
	if (this->_window != NULL) {
		wprintw(this->_window, "%u", n);
	}
	return (this);
}

Window					*Window::print(const unsigned int n) {
	if (this->_window != NULL) {
		wprintw(this->_window, "%u", n);
	}
	return (this);
}

Window					*Window::apply() {
	if (this->_window != NULL)
		wrefresh(this->_window);
	return (this);
}

Window					*Window::refresh() {
	if (this->_window != NULL)
		wrefresh(this->_window);
	return (this);
}

Window					*Window::clear() {
	if (this->_window != NULL)
		wrefresh(this->_window);
	return (this);
}
