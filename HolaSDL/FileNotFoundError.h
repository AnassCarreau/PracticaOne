#ifndef FILENOTFOUNDERROR_H_
#define FILENOTFOUNDERROR_H_

#include "ArrowsError.h";
#include <string>;
#include <iostream>;

class FileNotFoundError: public ArrowsError
{
		public:
			FileNotFoundError(string f) : ArrowsError(f){};
};
#endif

