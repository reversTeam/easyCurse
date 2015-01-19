#include "Modules/Ram.class.hpp"

namespace Modules {

	Ram::Ram():
		Module(),
		_usage(NULL)//,
	/*	_mem_use(0),
		_mem_total(0),
		_mem_swap_use(0),
		_mem_swap_total(0)*/
	{
		
	}


	Ram::Ram(Window *parent, unsigned int width, unsigned int height, unsigned int x, unsigned int y):
		Module("RAM MONITOR", parent, width, height, x, y),
		_usage(NULL)//,
/*		_mem_use(0),
		_mem_total(0),
		_mem_swap_use(0),
		_mem_swap_total(0)*/
	{
		this->_usage = new Percent(this, this->getWidth() - 2,  3, 1, 2);
	}

	Ram::~Ram() {

	}

}
