#include "primary.hpp"
#include "Display.class.hpp"
#include "Window/Module.class.hpp"
#include "Tools/Percent.class.hpp"

int			main() {
	Display		primary;
	Module		*window;
	Percent		*rage;

	primary.init();

	window = new Module("Primary Window", primary.getWindow(), primary.getWidth(), primary.getHeight(), 0, 0);
	rage = new Percent(window, window->getWidth() - 2, 3, 1, 2);
	rage->addValue(12)
		->addValue(18)
		->addValue(30)
		->addValue(40)
	->display();

	primary.end();
	return (0);
}
