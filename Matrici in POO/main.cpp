#include <iostream>
#include "Matrici.h"

using namespace std;

int main()
{
   Matrici m;
   cin>>m;
    try
    {
        cout<<m;
    }
    catch(invalid_argument e)
    {
        cout<<e.what()<<"\n";
    }

    catch(...)
    {
    cout<<"Nu putem face inmultirea"<<endl;
    }

}
