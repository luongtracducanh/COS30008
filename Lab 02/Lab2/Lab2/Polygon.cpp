#include "Polygon.h"
#include <stdexcept>

Polygon::Polygon() : fNumberOfVertices(0)
{
}

size_t Polygon::getNumberOfVertices() const
{
	return fNumberOfVertices;
}

const Vector2D& Polygon::getVertex(size_t aIndex) const
{
	if (aIndex < fNumberOfVertices)
		return fVertices[aIndex];
	throw std::out_of_range("Index is out of vertices bounds");
}

void Polygon::readData(std::istream& aIStream)
{
	while (aIStream >> fVertices[fNumberOfVertices])
	{
		fNumberOfVertices++;
	}
}

float Polygon::getPerimeter() const
{
	float perimeter = 0.0f;

	for (int i = 0; i < fNumberOfVertices; i++)
	{
		Vector2D segment = fVertices[(i + 1) % fNumberOfVertices] - fVertices[i];
		perimeter += segment.length();
	}
	return perimeter;
}

Polygon Polygon::scale(float aScalar) const
{
	Polygon result = *this;

	for (int i = 0; i < result.getNumberOfVertices(); i++)
		result.fVertices[i] = this->fVertices[i] * aScalar;

	return result;
}
