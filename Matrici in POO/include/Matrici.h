#ifndef MATRICI_H
#define MATRICI_H
#include <iostream>
#include <exception>
#include <stdexcept>


class Matrici
{
    int* m;
    int lin,col,marime;

    public:

        Matrici(int,int);//constructor de matrici
        ~Matrici();//destructor de matrici
        Matrici& operator = (const Matrici&);//constructor de copiere
        int* operator[](int);//returneaza linia i
        int getLin();//returneaza nr de linii
        int getCol();//returneaza nr de coloane
        int getMarime();//returneaza nr de elemente din matrice
        friend std::ostream & operator << (std::ostream &,const Matrici &);
        friend std::istream & operator >> (std::istream &, Matrici &);
        Matrici operator+(const Matrici &);//adunarea a 2 matrici
        Matrici operator*(const Matrici &);//inmutirea a 2 matrici
        Determinant(const Matrici&);//calcularea determinanului(doar la matrici cu lin==col<=3)
        Minor(const Matrici&);//gasirea minorului de stanga sus
        Inversabil(const Matrici&);//verifica daca o matrice e inversabila

};

#endif // MATRICI_H
