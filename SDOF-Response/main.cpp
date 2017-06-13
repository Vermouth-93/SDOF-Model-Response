#include <iostream>

using namespace std;

int main()
{
    int i; //counter for number of deltaT
    int j; //counter for value of constant c
    int c = [0,100,938,2000];

    int k = 2200; //stiffness
    int m = 100; //mass in tonnes
    float deltaT = 0.1; //delta of time

    float u0 = 0.1; //displacement 0
    float v0 = 2; //velocity 0

    float u_1; //displacement -1
    float acc0; //acceleration 0
    float p; //force at interval

    float kk, pp;
    float a, b;

    for(j=0; j<4; j++)
    {
        kk = (m/(deltaT)^2) + (c[j]/(2*deltaT));
        a = (m/(deltaT)^2) - (c[j]/(2*deltaT));
        b = k - (2*m/(deltaT)^2);

        for(i=0; i<=20; i++)
        {
            cout << "Hello world!" << endl;



            p = 100*sin(2*c[j]*deltaTt);


            pp = p - a*u_1 - b*u;
            acc0 = ( p(0) - c*v(0) - k*u(0) )/m;
            u_1 = u0 - deltaT*v0 + ((deltaT)^2)*acc0/2;
        }
    }

    return 0;
}
