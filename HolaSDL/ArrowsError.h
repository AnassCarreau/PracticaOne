#ifndef ARROWSERROR_H_
#define ARROWSERROR_H_

#include <stdexcept>
#include <string>
using namespace std;

class ArrowsError: public logic_error
{
	public:
		ArrowsError() :logic_error("logical error") { what(); };
};

#endif

