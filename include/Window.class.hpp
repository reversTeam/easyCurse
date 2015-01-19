#ifndef __WINDOW_CLASS_HPP__
# define __WINDOW_CLASS_HPP__

# include "primary.hpp"

class Window {
	public:
		Window(Window const &o);
		Window(Window *parent, unsigned int width, unsigned int height, unsigned int x, unsigned int y);
		virtual ~Window();

		unsigned int			getWidth()						const;
		unsigned int			getHeight()						const;
		unsigned int			getX()							const;
		unsigned int			getY()							const;
		t_window				*getWindow()					const;

		unsigned int			getAbsoluteX()					const;
		unsigned int			getAbsoluteY()					const;

		Window					*setBackgroundColor(unsigned int color);
		virtual Window			*printl(std::string const &str);
		virtual Window			*print(std::string const &str);
		virtual Window			*printCenter(std::string const &str);
		virtual Window			*printCenter(const unsigned int n);
		virtual Window			*print(unsigned int &n);
		virtual Window			*print(const unsigned int n);
		Window					*refresh();
		Window					*clear();
		Window					*apply();

		Window			&operator=(Window const &o);

	protected:
		Window();
		unsigned int			_width;
		unsigned int 			_height;
		unsigned int			_x;
		unsigned int			_y;
		Window					*_parent;
		t_window				*_window;
};

#endif
