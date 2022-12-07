#include "Vector2.h"


Vector2 Vector2::operator-(Vector2 const& a) {
	return Vector2(x - a.x, y - a.y);
}

Vector2 Vector2::operator+(Vector2 const& a) {
	return Vector2(x + a.x, y + a.y);
}

Vector2 Vector2::operator*(float a) {
	return Vector2(x * a, y * a);
}

Vector2 Vector2::operator/(float a) {
	return Vector2(x / a, y / a);
}

void Vector2::operator+=(Vector2 const& a) {
	*this = Vector2(x + a.x, y + a.y);
}

void Vector2::operator-=(Vector2 const& a) {
	*this = Vector2(x - a.x, y - a.y);
}

float Vector2::length() {
	return std::sqrt((x * x + y * y));
}

Vector2 Vector2::abs() {
	return Vector2(std::abs(x), std::abs(y));
}

std::string Vector2::str() {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vector2::Vector2(float X, float Y) {
	x = X;
	y = Y;
}

Vector2::Vector2() {
	x = 0;
	y = 0;
}