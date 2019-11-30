#ifndef FILEFORMATRROR_H_
#define FILEFORMATERROR_H_

#include "ArrowsError.h";
#include <iostream>

class FileFormatError: public ArrowsError
{
	public:
		static void FileError() { cout << "El formato de archivo no es correcto"; };
};
#endif

