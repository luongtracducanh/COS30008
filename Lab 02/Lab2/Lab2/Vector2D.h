
// COS30008, 2022

#pragma once

#include <iostream>

class Vector2D
{
private:

    float fX;
    float fY;

public:

    Vector2D(float aX = 1.0f, float aY = 0.0f) : fX(aX), fY(aY) {}
    Vector2D(std::istream& aIStream) { aIStream >> *this; }

    float getX() const;
    float getY() const;

    Vector2D operator+(const Vector2D& aVector) const;
    Vector2D operator-(const Vector2D& aVector) const;

    Vector2D operator*(const float aScalar) const;
    float dot(const Vector2D& aVector) const;
    float cross(const Vector2D& aVector) const;

    float length() const;
    Vector2D normalize() const;

    float direction() const;
    Vector2D align(float aAngleInDegrees) const;

    friend std::istream& operator>>(std::istream& aIStream, Vector2D& aVector);
    friend std::ostream& operator<<(std::ostream& aOStream, const Vector2D& aVector);
};

Vector2D operator*(const float aScalar, const Vector2D& aVector);
