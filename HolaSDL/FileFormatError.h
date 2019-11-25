#ifndef FILEFORMATRROR_H_
#define FILEFORMATERROR_H_

#include "ArrowsError.h";
#include <iostream>

class FileFormatError: public ArrowsError
{
	public:
		void FileError() { cout << "El formato de archivo no es correcto"; };
};
#endif

