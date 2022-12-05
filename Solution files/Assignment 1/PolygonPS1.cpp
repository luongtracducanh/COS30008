// COS30008, Tutorial 2, 2022

#include "Polygon.h"
 
using namespace std;

// Problem Set 1 extension
float Polygon::getSignedArea() const
{
    float Result = 0.0f;                                                // 3

    // There have to be at least three vertices
    if ( fNumberOfVertices > 2 )                                        // 3
    {
        // solution without modulus
        for ( size_t i = 1; i < fNumberOfVertices; i++ )                // 5
        {
            Vector2D v0 = fVertices[i - 1];                             // 3
            Vector2D v1 = fVertices[i];                                 // 3
            Result += v0.getX() * v1.getY() - v0.getY() * v1.getX();    // 6(12)
        }

        Vector2D v0 = fVertices[fNumberOfVertices - 1];                 // 3
        Vector2D v1 = fVertices[0];                                     // 3
        Result += v0.getX() * v1.getY() - v0.getY() * v1.getX();        // 6(12)
    }

    return Result / 2.0f;                                               // 3
}                                                                       // (38)

