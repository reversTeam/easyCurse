#ifndef __CPU_MODULE_HPP__
# define __CPU_MODULE_HPP__

# include "Window/Module.class.hpp"
#include "Tools/Percent.class.hpp"
# include "primary.hpp"

namespace Modules {
	class CPU : public Module {
		public:
			virtual ~CPU();
			CPU(Window *parent, unsigned int width, unsigned int height, unsigned int x, unsigned int y);

		private:
			CPU();

			Percent			*_usage;
	};
}

#endif
