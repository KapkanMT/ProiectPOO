#include <iostream>
#include "Matrici.h"

using namespace std;

//Am alocat matricea dinamic in cod in mod liniar si am incercat sa rezolv problemele intr-un mod similar cu vectorul de la seminarul 3.
//In final am dat de un bug caruia nu ii pot gasi solutie si nu am mai avut timp sa va intreb cum as putea sa-l rezolv.
//La urmatorul proiect ma voi apuca imediat cum apare.Pana atunci,imi cer scuze.

int main()
{
    Matrici m,n;
    cin>>m;
    cout<<m<<"\n";
    cin>>n;
    cout<<n<<"\n";
    try
    {
        Matrici u,v;
        u=m+n;
        cout<<u<<"\n";
        v=m*n;
        cout<<v<<"\n";
    }
    catch(invalid_argument e)
    {
        cout<<e.what<<"\n";
    }

    return 0;
}
