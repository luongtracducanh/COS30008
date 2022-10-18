#include "Polygon.h"

float Polygon::getSignedArea() const
{
	float Result = 0.0f;

	if (fNumberOfVertices > 2)
	{
		for (size_t i = 0; i < fNumberOfVertices; i++)
		{
			size_t j = (i + 1) % fNumberOfVertices;
			// shoelace algorithm
			Result += 0.5 * (fVertices[i].getX() * fVertices[j].getY() - fVertices[i].getY() * fVertices[j].getX());
		}
	}
	return Result;
}