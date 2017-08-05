#ifndef __PERCENT_CLASS_HPP__
# define __PERCENT_CLASS_HPP__

# include "primary.hpp"
# include "Window.class.hpp"
# include <map>
# include <cmath>

class Percent : public Window {
	public:
		Percent(Window *parent, unsigned int width, unsigned int height, unsigned int x, unsigned int y);
		virtual ~Percent();

		Percent						*addValue(unsigned int const &value);
		Percent						*display();
		Percent						*flush();

	private:
		Percent();

		std::map<unsigned int , Window*>	_values;
};

#endif
