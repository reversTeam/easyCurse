#include "Tools/Percent.class.hpp"

Percent::Percent() : Window() {

}

Percent::Percent(Window *parent, unsigned int width, unsigned int height, unsigned int x, unsigned int y):
	Window(parent, width, height, x, y)
{
	this->setBackgroundColor(BG_WHITE_BLACK);
}

Percent::~Percent() {

}

Percent					*Percent::addValue(unsigned int const &value) {
	this->_values[value] = NULL;
	return (this);
}

Percent					*Percent::flush() {
	std::map<unsigned int, Window *>::iterator	it;

	for (it = this->_values.begin(); it != this->_values.end(); ++it) {
		delete it->second;
		this->_values.erase(it);
	}
	this->clear()->setBackgroundColor(BG_WHITE_BLACK)->apply();
	return (this);
};


Percent					*Percent::display() {
	unsigned int								width = this->getWidth();
	unsigned int								height = this->getHeight();
	unsigned int								size;
	unsigned int								x = 0;
	std::map<unsigned int, Window *>::iterator	it;
	unsigned int								i = 2;

	this->clear();
	for (it = this->_values.begin(); it != this->_values.end(); ++it) {
		size = round(it->first / 100.0 * width);
		if (it->second == NULL) {
			it->second = new Window(this, size, height, x, 0);
			it->second
				->setBackgroundColor(++i)
				->print("\n")
				->printCenter(it->first)
			->apply();
		} else {
			it->second->clear()->apply();
			delwin(it->second->getWindow());
			it->second = new Window(this, size, height, x, 0);
			it->second
				->setBackgroundColor(++i)
				->print("\n")
				->printCenter(it->first)
			->apply();
		}
		x += size;
	}
	this->apply();
	return (this);
}
