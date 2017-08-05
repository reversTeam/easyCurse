#ifndef __MODULE_CLASS_HPP__
# define __MODULE_CLASS_HPP__

# include "primary.hpp"
# include "Window.class.hpp"

class Module : public Window {

	public:
		Module(std::string title, Window *parent, unsigned int width, unsigned int height, unsigned x, unsigned y);
		virtual ~Module();

		Module			*print(std::string const &str);
		Module			*printl(std::string const &str);
		Module			*printCenter(std::string const &str);

	protected:
		Module();

		std::string			_title;
		Window				*_header;
		Window				*_content;
};

#endif
