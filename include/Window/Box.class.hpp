#ifndef __BOX_CLASS_HPP__
#define __BOX_CLASS_HPP__

# include "primary.hpp"
# include "Window.class.hpp"

class Box : public Window {
	public:
		Box(Window *parent, unsigned int width, unsigned int height, unsigned int x, unsigned int y);
		virtual ~Box();

	protected:
		Box();

};

#endif
