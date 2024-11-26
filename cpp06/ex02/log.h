#ifndef __LOG__
# define __LOG__

# if defined(VERBOSE) || defined(LOG)
#  include <iostream>
#  define LOG(...) std::cout << __VA_ARGS__ << std::endl;
# else
#  define LOG(...)
# endif 

#endif /* __LOG__ */
