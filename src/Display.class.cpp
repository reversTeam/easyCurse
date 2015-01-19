#include "Display.class.hpp"
#include <sys/ioctl.h>

Display::Display():
	_width(0),
	_height(0)
{
}

Display::Display(Display const &o) {
	*this = o;
}

Display::~Display() {
}

void			Display::end() {
	getch();
	endwin();
}

Display			&Display::operator=(Display const &o) {
	this->_width = o._width;
	this->_height = o._height;
	this->_window = o._window;
	return (*this);
}

unsigned int				Display::getWidth()			const	{ return (this->_width);	}
unsigned int				Display::getHeight()		const	{ return (this->_height);	}
Window						*Display::getWindow()				{ return (this->_window);	}

void						Display::init() {
	struct winsize		w;

	initscr();
	setlocale(LC_ALL,"");
	start_color();
	noecho();
	curs_set(0);
	ioctl(0, TIOCGWINSZ, &w);
	refresh();
	this->_initColor();

	this->_width = w.ws_col;
	this->_height = w.ws_row;
	this->_window = new Window(NULL, this->_width, this->_height, 0,0);
}

void					Display::_initColor()		const {
	/*              TEXT         BG       */
	init_pair(1, COLOR_WHITE, COLOR_BLACK);		// BG_WHITE_BLACK
	init_pair(2, COLOR_BLACK, COLOR_WHITE);		// BG_BLACK_WHITE
	init_pair(3, COLOR_BLACK, COLOR_GREEN);		// BG_BLACK_GREEN
	init_pair(4, COLOR_WHITE, COLOR_BLUE);		// BG_WHITE_BLUE
	init_pair(5, COLOR_WHITE, COLOR_RED);		// BG_WHITE_RED
	init_pair(6, COLOR_RED, COLOR_WHITE);		// BG_RED_WHITE
	init_pair(7, COLOR_BLACK, COLOR_YELLOW);	// BG_BLACK_YELLOW
	init_pair(8, COLOR_WHITE, COLOR_MAGENTA);	// BG_WHITE_MAGENTA
	init_pair(9, COLOR_BLACK, COLOR_CYAN);		// BG_BLACK_CYAN
}
