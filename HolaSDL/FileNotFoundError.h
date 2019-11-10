#ifndef FILENOTFOUNDERROR_H_
#define FILENOTFOUNDERROR_H_

#include "ArrowsError.h";
#include <string>;

class FileNotFoundError: public ArrowsError
{
	private:
		string file;
	public:
		FileNotFoundError(/*string file*/);

};
#endif

