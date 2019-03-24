#include "Matrici.h"

Matrici::Matrici(int lin,int col)//constructor de matrici.lin=nr de linii;col=nr de coloane;marime=nr de elemente din matrice.
{
    if(lin<= 0 || col<=0)
    {
        std::invalid_argument e("Dimensiune mai mica sau egala cu 0");
        throw e;
    }
    this->lin=lin;
    this->col=col;
    this->marime=this->lin * this->col;
    m=new int[this->marime];
}

Matrici::~Matrici ()//destructor de matrici
{
    delete[] m;
    lin=col=0;
}

Matrici& Matrici::operator=(const Matrici& m)//constructor de copiere
{
    delete[] this->m;
    this->lin=m.lin;
    this->col=m.col;
    this->marime=m.marime;
    this->m=new int[this->marime];
    for (int i=0;i<this->marime;i++)
        this->m[i]=m.m[i];
    return *this;
}

int* Matrici::operator[](int i)
{
    if(i<0 || i>=lin)
    {
        std::invalid_argument e("Index invalid");
        throw e;
    }

    int* x=new int[col];

    for(int j=0; j<col; j++)
    {
        x[j]=m[i*lin+j];
    }

    return x;
}

int Matrici::getMarime()
{
    return marime;
}

int Matrici::getLin()
{
    return lin;
}

int Matrici::getCol()
{
    return col;
}

std::ostream& operator << (std::ostream &out,const Matrici &m)//afisarea pe ecran a matricii
{
    for(int i=0; i<m.lin; i++)
    {
        for(int j=0; j<m.col; j++)
            out<<m.m[i*(m.lin)+j]<<" ";
        out<<"\n";
    }
    return out;
}

std::istream& operator >> (std::istream &in, Matrici & m)//citirea matricii
{
    delete[] m.m;
    in>>m.lin;
    in>>m.col;
    m.marime=m.lin*m.col;
    m.m=new int[m.marime];
    for(int i=0; i<m.marime; i++)
        in>>m.m[i];
    return in;
}

Matrici::Matrici(const Matrici &m) //constructor de copiere
{
    lin=m.lin;
    col=m.col;
    marime=m.marime;
    this->m=new int[marime];
    for(int i=0;i<marime;i++)
        this->m[i]=m.m[i];
}

Matrici Matrici::operator+(const Matrici &m)//adunarea a 2 matrici
{
    if(m.lin!=lin || m.col!=col)
    {
        std::invalid_argument e("Dimensiuni incorecte");
        throw e;
    }
    Matrici n(lin,col);
    n.lin=lin;
    n.col=col;
    n.marime=marime;

    for(int i=0;i<marime;i++)
    {
        n[i]=m.m[i]+this->m[i];
    }
    return n;
}

Matrici Matrici::operator*(const Matrici &m)//inmutirea a 2 matrici
{
    Matrici x(m.lin,this->col);
    x.lin=m.lin;
    x.col=this->col;
    x.marime=m.lin*this->col;
    for(int i=0;i<marime;i++)
        for(int j=0;j<;j++)
            x[i]=m.m[i*m.lin+j]*this->m[j*m.lin+i]+x[i];
    //la fiecare incrementare a lui j,inmultesc al j-ulea element de pe
    //linia primei matrici cu al j-ulea element de pe coloana celeilalte matrici
}

Matrici Matrici::Minor (const Matrici &m)//gasirea minorului de stanga sus
{
    int i,j;
    if (m.lin<=m.col)//daca sunt mai putine linii decat coloane,se taie coloana
    {
        Matrici x(m.lin,m.col-1)
        lin=m.lin;
        col=m.col-1;
        marime=m.marime-m.col;
        for(i=0;i<m.lin;i++)
            for (j=0;j<m.col-1;j++)
                x[i*lin+j]=m.m[i*lin+j];
        delete[] m;
        return x;
    }
    if (m.lin>=m.col)//daca sunt mai putine coloane decat linii,se taie linia
    {
        Matrici x(m.lin-1,m.col)
        lin=m.lin-1;
        col=m.col;
        marime=m.marime-m.lin;
        for (i=0;i<marime-lin;i++)
            x[i]=m.m[i];
        delete[] m;
        return x;
    }
    if (m.lin==m.col)//daca nr liniile si coloanele sunt egale,se taie o linie si o coloana
    {
        Matrici x(m.lin-1,m.col-1)
        lin=m.lin-1;
        col=m.col-1;
        marime=m.marime-m.lin-m.col;
        for(i=0;i<m.lin-1;i++)
            for (j=0;j<m.col-1;j++)
                x[i*lin+j]=m.m[i*lin+j];
        delete[] m;
        return x;
    }
}

int Matrici::Determinant(const Matrici &m)//determinantul unei matrici cu lin==col<=3
{
    if(m.lin!=m.col || m.lin>3)
    {
        std::invalid_argument e("Dimensiune diferite sau prea mari");
        throw e;
    }
    if (m.lin==1)//lin==col==1
        return m.m[1];
    if (m.lin==2)//lin==col==2
        return m.m[1]*m.m[4]-m.m[2]*m.m[3]
    if (m.lin==3)//lin==col==3
    {
        int deltas=m.m[1]*m.m[5]*m.m[9]+m.m[2]*m.m[6]*m.m[7]+m.m[3]*m.m[4]*m.m[8];
        int deltad=m.m[3]*m.m[5]*m.m[7]+m.m[1]*m.m[6]*m.m[8]+m.m[2]*m.m[4]*m.m[9];
        return deltas-deltad;
    }
}

bool Matrici::Inversabil(const Matrici &m)//inversabilitatea unei matrici
{
    if(m.lin!=m.col || m.lin>3)
    {
        std::invalid_argument e("Nu are Determinant");
        throw e;
    }
    if (Determinant(m)!=0)
    {
        return TRUE;
    }
    return FALSE;
    //daca e inversabila,returneaza TRUE,daca nu e,returneaza FALSE
}
