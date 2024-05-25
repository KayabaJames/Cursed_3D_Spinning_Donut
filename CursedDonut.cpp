#include <iostream>
#include <string.h>
#include <math.h>
#include <unistd.h>

using namespace std;

void displayDonut()
{
    auto _ = []() -> auto { return 0; };
    auto __ = []() -> auto { return 6.28; };
    auto ___ = []() -> auto { return 0.07; };
    auto ____ = []() -> auto { return 0.02; };
    auto _____ = []() -> auto { return 2; };
    auto ______ = []() -> auto { return 5; };
    auto _______ = []() -> auto { return 40; };
    auto ________ = []() -> auto { return 30; };
    auto _________ = []() -> auto { return 12; };
    auto __________ = []() -> auto { return 15; };
    auto ___________ = []() -> auto { return 80; };
    auto ____________ = []() -> auto { return 8; };
    auto _____________ = []() -> auto { return 0.00004; };
    auto ______________ = []() -> auto { return 0.00002; };
    auto _______________ = []() -> auto { return 30000; };
    auto ________________ = []() -> auto { return "oopisTHEBEST"; };

    float rotationA = _(), rotationB = _();
    float theta, phi;
    int loopIndex;
    float depthBuffer[1760];
    char outputBuffer[1760];
    printf("\x1b[2J");
    while(1)
    {
        memset(outputBuffer, 32, 1760);
        memset(depthBuffer, 0, 7040);
        for(phi = _(); phi < __(); phi += ___())
        {
            for(theta = _(); theta < __(); theta += ____())
            {
                float circleRadius = sin(theta);
                float circleDistance = cos(phi);
                float rotationSinA = sin(rotationA);
                float rotationSinB_phi = sin(phi);
                float rotationCosA = cos(rotationA);
                float circleOffset = circleDistance + _____();
                float perspectiveFactor = 1 / (circleRadius * circleOffset * rotationSinA + rotationSinB_phi * rotationCosA + ______());
                float circleCos = cos(theta);
                float rotationCosB = cos(rotationB);
                float rotationSinB_rotationB = sin(rotationB);
                float circleT = circleRadius * circleOffset * rotationCosA - rotationSinB_phi * rotationSinA;
                int screenX = _______() + ________() * perspectiveFactor * (circleCos * circleOffset * rotationCosB - circleT * rotationSinB_rotationB);
                int screenY = _________() + __________() * perspectiveFactor * (circleCos * circleOffset * rotationSinB_rotationB + circleT * rotationCosB);
                int pixelIndex = screenX + ___________() * screenY;
                int lightIntensity = ____________() * ((rotationSinB_phi * rotationSinA - circleRadius * circleDistance * rotationCosA) * rotationCosB - circleRadius * circleDistance * rotationSinA - rotationSinB_phi * rotationCosA - circleCos * circleDistance * rotationSinB_rotationB);
                if(22 > screenY && screenY > _() && screenX > _() && ___________() > screenX && perspectiveFactor > depthBuffer[pixelIndex])
                {
                    depthBuffer[pixelIndex] = perspectiveFactor;
                    outputBuffer[pixelIndex] = ________________()[lightIntensity > _() ? lightIntensity : _()];
                }
            }
        }
        printf("\x1b[H");
        for(loopIndex = _(); loopIndex < 1761; loopIndex++)
        {
            putchar(loopIndex % ___________() ? outputBuffer[loopIndex] : 10);
            rotationA += _____________();
            rotationB += ______________();
        }
        usleep(_______________());
    }
}
