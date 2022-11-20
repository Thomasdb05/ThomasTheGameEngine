#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
public:
	float x;
	float y;

	Vector2 operator-(Vector2 const& a);

	Vector2 operator+(Vector2 const& a);

	Vector2 operator*(float a);

	void operator+=(Vector2 const& a);

	void operator-=(Vector2 const& a);

	Vector2();
	Vector2(float X, float Y);
};

#endif