#ifndef __RAM_CLASS_HPP__
# define __RAM_CLASS_HPP__

# include "Window/Module.class.hpp"
# include "Tools/Percent.class.hpp"
# include "primary.hpp"

namespace Modules {
	class Ram : public Module {

		public:
			Ram(Window *parent, unsigned int width, unsigned int height, unsigned int x, unsigned int y);
			virtual ~Ram();

		private:
			Ram();

			Window			*_usage;
/*			int				_mem_use;
			int				_mem_total;
			int				_mem_swap_use;
			int				_mem_swap_total;*/

	};
}
#endif
