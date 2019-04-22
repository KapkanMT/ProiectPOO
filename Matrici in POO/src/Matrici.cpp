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

Matrici::Matrici()
{
    this->lin=0;
    this->col=0;
    this->marime=0;
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
    {
        in>>m.m[i];
    }

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

Matrici Matrici::operator+(const Matrici &u)//adunarea a 2 matrici
{
    if(u.lin!=lin || u.col!=col)
    {
        std::invalid_argument e("Dimensiuni incorecte adunare");
        throw e;
    }
    Matrici n(lin,col);
    n.lin=lin;
    n.col=col;
    n.marime=lin*col;

    for(int i=0;i<marime;i++)
    {
        n.m[i]=this->m[i]+u.m[i];
    }
    return n;
}

Matrici Matrici::operator*(const Matrici &m)//inmutirea a 2 matrici
{
    if(this->lin != m.col)
    {
        std::invalid_argument e("Dimensiuni incorecte inmultire");
        throw e;
    }

    Matrici x(this->lin,m.col);
    x.lin=this->lin;
    x.col=m.col;
    x.marime=this->lin*m.col;
    for (int i=0;i<this->lin;i++)
        for (int j=0;j<m.col;j++)
        {
            int s=0;
            for(int k=0;k<m.col;k++)
            {
                s=s+this->m[i*this->col+k]*m.m[j+k*m.lin];
            }
            x.m[i*this->col+j]=s;
        }

    return x;
}

int Matrici::Determinant(const Matrici &m)//determinantul unei matrici cu lin==col<=3
{
    if(m.lin!=m.col || m.lin>3)
    {
        std::invalid_argument e("Dimensiune diferite sau prea mari");
        throw e;
    }
    if (m.lin==1)//lin==col==1
        return m.m[0];
    if (m.lin==2)//lin==col==2
        return (m.m[0]*m.m[3])-(m.m[1]*m.m[2]);
    if (m.lin==3)//lin==col==3
    {
        int deltas=m.m[0]*m.m[4]*m.m[8]+m.m[1]*m.m[5]*m.m[6]+m.m[2]*m.m[3]*m.m[7];
        int deltad=m.m[2]*m.m[4]*m.m[6]+m.m[0]*m.m[5]*m.m[7]+m.m[1]*m.m[3]*m.m[8];
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
        return true;
    }
    return false;
    //daca e inversabila,returneaza TRUE,daca nu e,returneaza FALSE
}

