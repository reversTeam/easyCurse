#ifndef __DISPLAY_CLASS_HPP__
# define __DISPLAY_CLASS_HPP__

# include "primary.hpp"
# include "Window.class.hpp"
# include "Window/Module.class.hpp"
# include "IMonitorDisplay.hpp"

class Display : IMonitorDisplay {
	public:
		Display();
		Display(Display const &o);
		virtual ~Display();

		unsigned int			getWidth()		const;
		unsigned int			getHeight()		const;
		Window					*getWindow();

		virtual void			init();
		void					end();

		Display					&operator=(Display const &o);
	private:

		unsigned int			_width;
		unsigned int			_height;
		Window					*_window;

		void					_initColor()	const;
};

#endif
