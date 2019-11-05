#ifndef ARROWSERROR_H_
#define ARROWSERROR_H_

#include <stdexcept>;
using namespace std;
class ArrowsError: public logic_error
{
	logic_error(const char* what_arg);

};
#endif

