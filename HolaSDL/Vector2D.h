
#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows

#include <iostream>

typedef unsigned int uint;

class Vector2D {
private:
	uint x;
	uint y;
public:
	Vector2D();
	Vector2D(uint x,  uint y);
	double getX() const;
	double getY() const;
	void normalize();
	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator*(double d) const;
	Vector2D operator-(const Vector2D& v) const;
	double operator*(const Vector2D& d) const;
	friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
}; using Point2D = Vector2D;


#endif // También lo escriben los IDEs (va con el #ifndef de arriba)
