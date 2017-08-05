#include "Modules/CPU.class.hpp"

namespace Modules {

	CPU::CPU():
		Module(),
		_usage(NULL)
	{

	}

	CPU::CPU(Window *parent, unsigned int width, unsigned int height, unsigned int x, unsigned y):
		Module("CPU MONITOR", parent, width, height, x, y),
		_usage(NULL)
	{
		this->_usage = new Percent(this, this->getWidth() - 2, 3, 1, 2);
	}

	CPU::~CPU() {

	}

}
