
// COS30008, 2022

#include <iostream>

#include "Vector2D.h"

class Particle2D
{
private:
    float fMass;
    float fRadius;
    Vector2D fPosition;
    Vector2D fVelocity;
    Vector2D fAcceleration;
    
public:

    explicit Particle2D( float aMass = 0.0f,
                         float aRadius = 10.0f,
                         const Vector2D& aPosition = Vector2D( 0.0f, 0.0f ),
                         const Vector2D& aVelocity = Vector2D( 0.0f, 0.0f ),
                         const Vector2D& aAcceleration = Vector2D( 0.0f, 0.0f ) );
    
    const float getMass() const;
    const float getRadius() const;
    const Vector2D& getPosition() const;
    const Vector2D& getVelocity() const;
    const Vector2D& getAcceleration() const;

    void applyAcceleration( const Vector2D& aAcceleration );
    float direction() const;
    void align( float aAngleInDegrees );
    float speed() const;

    void update();
    
    friend std::ostream& operator<<( std::ostream& aOStream, const Particle2D aParticle );
};
