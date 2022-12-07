#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include<string>

class Vector2 {
public:
	float x;
	float y;

	Vector2 operator-(Vector2 const& a);

	Vector2 operator+(Vector2 const& a);

	Vector2 operator*(float a);

	Vector2 operator/(float a);

	void operator+=(Vector2 const& a);

	void operator-=(Vector2 const& a);

	float length();

	Vector2 abs();

	std::string str();

	Vector2();
	Vector2(float X, float Y);
};

#endif