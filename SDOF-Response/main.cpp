#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int i; //counter for number of deltaT
    int j; //counter for value of constant c
    int c[4] = {0,100,938,2000};

    float k = 2200; //stiffness
    float m = 100; //mass in tonnes
    float deltaT = 0.1; //delta of time

    float u[20] = { }; //displacement 0
    u[0] = 0.1;
    float v[20] = { }; //velocity 0
    v[0] = 2;
    float acc[20] = { }; //acceleration 0

    float u_1; //displacement -1
    float a, b; //constants

    float p[20] = { }; //force at interval
    float pp[20] = { }; //p chapeau
    float kk; //k chapeau

    for(j=0; j<4; j++)
    {
        p[j] = (float) 100*sin(2*c[j]*deltaT);
        kk = (m/(deltaT*deltaT)) + (c[j]/(deltaT*deltaT));
        a = (m/(deltaT*deltaT)) - (c[j]/(deltaT*deltaT));
        b = k - (2*m/(deltaT*deltaT));

        for(i=0; i<=20; i++)
        {
            cout << "Hello world!" << endl;

            pp[j] = p[i] - a*u_1 - b*u[i];

            acc[0] = (p[0] - c[i]*v[0] - k*u[0])/m;
            u_1 = u[0] - deltaT*v[0] + (deltaT*deltaT*acc[0])/2;

            u[i+1] = pp[i]/kk;
            v[i] = (u[i+1] - u_1)/(2*deltaT);
            acc[i] = (u[i+1] - 2*u[i] + u_1)/(deltaT*deltaT);
        }
    }

    return 0;
}
