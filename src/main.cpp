#include "primary.hpp"
#include "Display.class.hpp"
#include "Window/Module.class.hpp"
#include "Tools/Percent.class.hpp"

int			main() {
	Display		primary;
	Module		*window;
	Percent		*rage;

	Module		*submodule;

	primary.init();

	window = new Module("Primary Window", primary.getWindow(), primary.getWidth(), primary.getHeight(), 0, 0);
	rage = new Percent(window, window->getWidth() - 2, 3, 1, 2);
	rage->addValue(12)
		->addValue(18)
		->addValue(30)
		->addValue(40)
	->display();

	submodule = new Module("Man in the Middle", window, 40, 18, 10, 10);

	submodule->printCenter("Un text de test")->apply();

	primary.end();
	return (0);
}
