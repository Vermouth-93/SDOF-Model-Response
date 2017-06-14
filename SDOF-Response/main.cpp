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

    float u[25] = { }; //displacement 0
    u[0] = 0.1;
    float v[25] = { }; //velocity 0
    v[0] = 2;
    float acc[25] = { }; //acceleration 0

    float u_1; //displacement -1
    float a, b; //constants

    float p[25] = { }; //force at interval
    p[0] = 100;
    float pp[25] = { }; //p chapeau
    float kk; //k chapeau

    for(j=0; j<1; j++)
    {
        kk = (m/(deltaT*deltaT)) + (c[j]/(deltaT*deltaT));
        cout << "K chapeau = " << kk << endl;

        a = (m/(deltaT*deltaT)) - (c[j]/(deltaT*deltaT));
        cout << "a= " << a << endl;

        b = k - (2*m/(deltaT*deltaT));
        cout << "b = " << b << endl;

        acc[0] = ( (p[0] - c[j]*v[0] - k*u[0])/m );
        cout << "acc(0) = " << acc[0] << endl;

        u_1 = u[0] - deltaT*v[0] + (deltaT*deltaT*acc[0])/2;
        cout << "u(-1) = " << u_1 << endl;

        cout << "----------------------------------------------------------------------" << endl;

        for(i=0; i<2; i++)
        {
            cout << "Iteration " << i << endl;

            if(i==0)
            {
                pp[i] = p[0] - a*u_1 - b*u[i];
                cout << "P chapeau of " << i << " =" << pp[i] << endl;
            }
            else
            {
                cout << "value of i = " << i << endl;
                p[i] = (float) 100*sin(2*i*deltaT);
                cout << "P of "  << i << " ="  << p[i] << endl;
                pp[i] = p[i] - a*u[i-1] - b*u[i];
                cout << "P chapeau of " << i << " =" << pp[j] << endl;
            }

            u[i+1] = pp[i]/kk;
            cout << "u of " << i+1 << " =" << u[i+1] << endl;

            if(i==0)
            {
                v[i] = (u[i+1] - u_1)/(2*deltaT);
            }
            else
            {
                v[i] = (u[i+1] - u[i-1])/(2*deltaT);
            }
            cout << "v of " << i << " =" << v[i] << endl;

            if(i==0)
            {
                acc[i] = (u[i+1] - 2*u[i] + u_1)/(deltaT*deltaT);
            }
            else
            {
                acc[i] = (u[i+1] - 2*u[i] + u[i-1])/(deltaT*deltaT);
            }
            cout << "acc of " << i << " =" << acc[i] << endl;

            cout << "End of iteration " << i<< endl;
            cout << "----------------------------------------------------------------------" << endl;
        }
    }

    return 0;
}
