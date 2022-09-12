
#include <iostream>

#include "Particle2D.h"

using namespace std;

int main()
{
    cout << "A simple particle simulation\n" << endl;
    
    Particle2D obj( 0.0f,
                    10.0f,
                    Vector2D( 10.0f, 20.0f ),
                    Vector2D( 4.0f, 15.0f ),
                    Vector2D( 0.0f, -0.1f )
                   );
    
    do
    {
        cout << obj << endl;

        obj.update();
    } while ( obj.getPosition().getY() >= 20.0f );

    cout << obj << endl;

    return 0;
}
