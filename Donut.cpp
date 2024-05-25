#include <iostream>
#include <string.h>
#include <math.h>
#include <unistd.h>

using namespace std;

void displayDonut()
{
    float rotationA = 0, rotationB = 0;
    float theta, phi;
    int loopIndex;
    float depthBuffer[1760];
    char outputBuffer[1760];
    printf("\x1b[2J");
    while(1)
    {
        memset(outputBuffer, 32, 1760);
        memset(depthBuffer, 0, 7040);
        for(phi = 0; phi < 6.28; phi += 0.07)
        {
            for(theta = 0; theta < 6.28; theta += 0.02)
            {
                float circleRadius = sin(theta);
                float circleDistance = cos(phi);
                float rotationSinA = sin(rotationA);
                float rotationSinB_phi = sin(phi);
                float rotationCosA = cos(rotationA);
                float circleOffset = circleDistance + 2;
                float perspectiveFactor = 1 / (circleRadius * circleOffset * rotationSinA + rotationSinB_phi * rotationCosA + 5);
                float circleCos = cos(theta);
                float rotationCosB = cos(rotationB);
                float rotationSinB_rotationB = sin(rotationB);
                float circleT = circleRadius * circleOffset * rotationCosA - rotationSinB_phi * rotationSinA;
                int screenX = 40 + 30 * perspectiveFactor * (circleCos * circleOffset * rotationCosB - circleT * rotationSinB_rotationB);
                int screenY = 12 + 15 * perspectiveFactor * (circleCos * circleOffset * rotationSinB_rotationB + circleT * rotationCosB);
                int pixelIndex = screenX + 80 * screenY;
                int lightIntensity = 8 * ((rotationSinB_phi * rotationSinA - circleRadius * circleDistance * rotationCosA) * rotationCosB - circleRadius * circleDistance * rotationSinA - rotationSinB_phi * rotationCosA - circleCos * circleDistance * rotationSinB_rotationB);
                if(22 > screenY && screenY > 0 && screenX > 0 && 80 > screenX && perspectiveFactor > depthBuffer[pixelIndex])
                {
                    depthBuffer[pixelIndex] = perspectiveFactor;
                    outputBuffer[pixelIndex] = "oopisTHEBEST"[lightIntensity > 0 ? lightIntensity : 0];
                }
            }
        }
        printf("\x1b[H");
        for(loopIndex = 0; loopIndex < 1761; loopIndex++)
        {
            putchar(loopIndex % 80 ? outputBuffer[loopIndex] : 10);
            rotationA += 0.00004;
            rotationB += 0.00002;
        }
        usleep(30000);
    }
}
