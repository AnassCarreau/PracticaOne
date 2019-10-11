
#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows

#include <iostream>

using Point2D = Vector2D;

class Vector2D {
private:
	double x;
	double y;
public:
	Vector2D();
	Vector2D(double x, double y);
	double getX() const;
	double getY() const;
	void normalize();
	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator*(double d) const;
	Vector2D operator-(const Vector2D& v) const;
	double operator*(const Vector2D& d) const;
	friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
};
#endif // También lo escriben los IDEs (va con el #ifndef de arriba)
