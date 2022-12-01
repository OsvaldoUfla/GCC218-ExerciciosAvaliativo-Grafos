// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <iostream>
using namespace std;


class Lampada 
{
    private:
        int indice;
        int grau;
    public:
        Lampada(int indice, int grau)
        {
            this->indice = indice;
            this->grau = grau;
        }

        int getIndice()
        {
            return indice;
        }

        int getGrau()
        {
            return grau;
        }

};

bool myfunction (Lampada i, Lampada j) 
{
    return(i.getGrau() < j.getGrau());
}


int main () {
  
    std::vector<Lampada> myLampada;   
    Lampada *lamp;
    for(int i =0 ; i < 5 ; i++)
    {
        int x;
        cin >> x;
        lamp = new Lampada(i,x);   
        myLampada.push_back(*lamp);
    }          

    // using default comparison (operator <):
    //std::sort (myvector.begin(), myvector.begin()+4);           

    // using function as comp
    std::sort (myLampada.begin(), myLampada.end(), myfunction); 

    // using object as comp
    // std::sort (myvector.begin(), myvector.end(), myobject);     



  return 0;
}