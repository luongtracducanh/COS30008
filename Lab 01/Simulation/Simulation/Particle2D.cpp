
// COS30008, 2022

#include "Particle2D.h"

using namespace std;

Particle2D::Particle2D( float aMass,
                        float aRadius,
                        const Vector2D& aPosition,
                        const Vector2D& aVelocity,
                        const Vector2D& aAcceleration ) :
    fMass(aMass),
    fPosition(aPosition),
    fVelocity(aVelocity),
    fAcceleration(aAcceleration)
{}

const float Particle2D::getMass() const
{
    return fMass;
}

const float Particle2D::getRadius() const
{
    return fRadius;
}

const Vector2D& Particle2D::getPosition() const
{
    return fPosition;
}

const Vector2D& Particle2D::getVelocity() const
{
    return fVelocity;
}

const Vector2D& Particle2D::getAcceleration() const
{
    return fAcceleration;
}

void Particle2D::applyAcceleration( const Vector2D& aAcceleration )
{
    fAcceleration = fAcceleration + aAcceleration;
}

float Particle2D::direction() const
{
    return fVelocity.direction();
}

void Particle2D::align( float aAngleInDegrees )
{
    fVelocity = fVelocity.align( aAngleInDegrees );
}

float Particle2D::speed() const
{
    return fVelocity.length();
}

void Particle2D::update()
{
    fVelocity = fVelocity + fAcceleration;
    fPosition = fPosition + fVelocity;
}

ostream& operator<<( ostream& aOStream, const Particle2D aParticle )
{
    return
        aOStream
        << "Speed: " << aParticle.speed() << "\n"
        << "Direction: " << aParticle.direction() << "\n"
        << "Position: " << aParticle.fPosition << "\n";
}

