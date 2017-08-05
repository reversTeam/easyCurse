#include "Window/Module.class.hpp"

Module::Module ():
	_header(NULL),
	_content(NULL)
{

}

Module::Module (std::string title, Window *parent, unsigned int width, unsigned int height, unsigned int x, unsigned int y):
	Window(parent, width, height, x, y),
	_title(title)
{
(void)_header;
	this->setBackgroundColor(BG_BLACK_WHITE)->apply();
	this->_header = new Window(this, this->getWidth(), 1, 0, 0);
	this->_header
		->setBackgroundColor(BG_WHITE_BLUE)
		->printCenter(title)
	->apply();

	this->_content = new Window(this, this->getWidth(), this->getHeight() - 1, 0, 1);
}


Module				*Module::print(std::string const &str) {
	if (this->_content != NULL) {
		wprintw(this->_content->getWindow(), str.c_str());
	}
	return (this);
}

Module				*Module::printl(std::string const &str) {
	if (this->_content != NULL) {
		wprintw(this->_content->getWindow(), "%s\n", str.c_str());
	}
	return (this);
}

Module					*Module::printCenter(std::string const &str) {
	std::string				s;
	if (this->_content == NULL)
		return (this);
	if (str.length() < this->_width) {
		for (unsigned int i =  0; i < (this->_width - str.length()) / 2; ++i)
			s += " ";
		s += str;
	}
	wprintw(this->_content->getWindow(), s.c_str());
	return (this);
}

Module::~Module() {}
