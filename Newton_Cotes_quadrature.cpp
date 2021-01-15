#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(int x)
{
    return 2*x;
}

double F(int x)
{
    return x*x;
}

double Q(double a, double b)
{
    // kwadratura parabol
    double n = 2;
    double h = (b - a) / n;
    return ((b-a)/6)*(2*a+4*2*(a+((b-a)/2))+2*b);
    return ((b-a)/6)*(f(a)+4*f(a+h)+f(b));
}

int main()
{
    double a, b, q, I, H;
    cout << "a = "; cin >> a;
    cout << endl;
    cout << "b = "; cin >> b;
    cout << endl;

    I = F(b) - F(a);
    q = Q(a,b);

    int p = 2;

    for(int l = 1; l<=25; l++)
    {
        long int N;
        N = pow(p,l);
        H = (b-a)/N;
        q = 0;

        for(long int i = 0; i <= N-1; i++)
        {
            q=q+Q(a+i*H,a+(i+1)*H);
        }

        cout << "N = " << N << endl;
        cout << "q = " << setprecision(15) << q << endl;
        cout << "|I-q| = " << setprecision(15) << fabs(I-q) << endl;
        cout << endl;

    }


    return 0;
}
