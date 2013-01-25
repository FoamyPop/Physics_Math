//////////////////////////////////////////////////////////
//                                                      //
// Custom Physics Header                                //
//                                                      //
//   Created By (@PotatoSoftware)                       //
//                                                      //
//       January 18, 2013 --> January 20, 2013          //
//                                                      //
//////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <cmath>

#define G = 6.67e-11
#define PI 3.145978

template<class T>
class VAR
{
public:
    VAR(T var)
    {
        value = var;
    }
    VAR()
    {
        value = 0;
    }
    std::string Show()
    {
        return value;
    }
    void display()
    {
        std::cout << value << std::endl;
    }
    VAR& operator= (const float& val)
    {
        value = val;
    }
    T value;
};

class Vector
{
    public:
        Vector(float THETA, float xDISPLACEMENT, float yDISPLACEMENT)
        : ANGLE(THETA), xLENGTH(xDISPLACEMENT), yLENGTH(yDISPLACEMENT)
        {
            /*
                   /|
                  / |
                 /  |
              h /   |
               /    | y(o)
              /     |
             /THETA |
            /_______|
               x(a)
            */
        }
        Vector(float DISPLACEMENT, std::string AXIS)
        {
            if(AXIS == "X" || AXIS == "x")
            {
                xLENGTH = DISPLACEMENT;
                yLENGTH = 0;
                ANGLE = 0;
            }
            else if(AXIS == "Y" || AXIS == "y")
            {
                yLENGTH = DISPLACEMENT;
                xLENGTH = 0;
                ANGLE = 90;
            }
        }
        Vector() : ANGLE(0), xLENGTH(0), yLENGTH(0)
        {

        }
        void display()
        {
            std::cout << "X:" << xLENGTH << ", Y:" << yLENGTH << ", ANGLE:" << ANGLE;
        }
        float MAGNITUDE()
        {
            return (sqrt(xLENGTH * xLENGTH) + (yLENGTH * yLENGTH));
        }
    private:
        float xLENGTH, yLENGTH, ANGLE;
};

class FORCE : public Vector
{
    public:
        FORCE(float FORCE_VALUE) : MAGNITUDE(FORCE_VALUE)
        {

        }

        friend std::ostream& operator<< (std::ostream& stream, const FORCE& f)
        {
            std::cout << f.MAGNITUDE;
        }

        FORCE& operator= (const FORCE& force)
        {
            MAGNITUDE -= force.MAGNITUDE;
        }

        FORCE& operator+ (const FORCE& force)
        {
            MAGNITUDE = force.MAGNITUDE;
        }

        FORCE& operator- (const FORCE& force)
        {
            MAGNITUDE -= force.MAGNITUDE;
        }

        FORCE& operator+= (const FORCE& force)
        {
            MAGNITUDE = force.MAGNITUDE;
        }

        FORCE& operator-= (const FORCE& force)
        {
            MAGNITUDE -= force.MAGNITUDE;
        }

        void display()
        {
            std::cout << MAGNITUDE;
        }
    private:
        float MAGNITUDE;
        // A, B and C
        // X, Y, MAGNITUDE
};

namespace VALUES
{
    float EMPTY_VAR()
    {
        return 0.0f;
    }

    float DISPLACEMENT(float d)
    {
        return d;
    }
}

namespace CENTRIPETAL
{
    // Fc = mv2/r
    float CALCULATE_FC(float mass, float velocity, float radius)
    {
        float v2 = velocity * velocity;
        return ((mass*v2) / radius);
    }
};

namespace FORCES
{
    FORCE FNET(float mass, float acceleration)
    {
        return FORCE(mass * acceleration);
    }

    FORCE APPLIED_FORCE(float Fa)
    {
        return FORCE(Fa);
    }

    FORCE FRICTIONAL_FORCE(float Ff)
    {
        return FORCE(Ff);
    }

    FORCE TENSION_FORCE(float T)
    {
        return FORCE(T);
    }

    FORCE CENTRIPETAL_FORCE(float Fc)
    {
        return FORCE(Fc);
    }

    FORCE GRAVITATIONAL_FORCE(float Fg)
    {
        return FORCE(Fg);
    }
}

namespace ENERGY
{
    float WORK(float FORCE, float DISPLACEMENT)
    {
    return FORCE * DISPLACEMENT;
    }
}

namespace PROJECTILE_MOTION
{
    float CALCULATE_HORIZONTAL(float ANGLE, float ANGLED_FORCE, float Vi)
    {
        /* COS */
        float horiz_force = (cos(ANGLE) * ANGLED_FORCE);
    }
}






