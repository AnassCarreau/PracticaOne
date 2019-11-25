#ifndef FILENOTFOUNDERROR_H_
#define FILENOTFOUNDERROR_H_

#include "ArrowsError.h";
#include <string>;
#include <iostream>;

class FileNotFoundError: public ArrowsError
{
		public:
			void FileNotFound(string file) { cout << "No se pudo encontrar el archivo " << file <<endl; };
};
#endif

