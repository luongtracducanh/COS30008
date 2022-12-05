#pragma once
#include "Vector2D.h"
#define MAX_VERTICES 30
class Polygon
{
private:
	Vector2D fVertices[MAX_VERTICES];
	size_t fNumberOfVertices;

public:

	Polygon();

	size_t getNumberOfVertices() const;
	const Vector2D& getVertex(size_t aIndex) const;

	void readData(std::istream& aIStream);

	float getPerimeter() const;

	Polygon scale(float aScalar) const;

	// Problem Set 1 extension
	float getSignedArea() const;
};