#ifndef FILEFORMATRROR_H_
#define FILEFORMATERROR_H_

#include "ArrowsError.h";
#include <iostream>
#include <string>

class FileFormatError: public ArrowsError
{
	public:
		FileFormatError(string f) : ArrowsError(f){};
};
#endif

