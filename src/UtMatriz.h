//---------------------------------------------------------------------------

#ifndef UtMatrizH
#define UtMatrizH

#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
template<class T>
class tMatriz
{
        private:
                unsigned int nCol, nFil;
                T** matriz;

        public:
                tMatriz()
                {
                        nFil = 0;
                        nCol = 0;
                        //matriz = NULL;
                };
                tMatriz(int c, int f, T inicial);
                ~tMatriz()
                {
                        T b;
                        for(unsigned int i = 0; i < nCol; i++)
                        {
                                for(unsigned int j = 0; j < nFil; j++)
                                {
//                                        borrarDatoMat(matriz[i][j]);  //resolverlo sin funciones
                                          matriz[i][j] = b;
                                }
                        }
                        for(unsigned int i = 0; i < nCol; i++)
                        {
                                delete[] matriz[i];
                                matriz[i] = NULL;
                        }
                        delete[] matriz;
                        matriz = NULL;
                };
                int dameFilas()
                {
                        return nFil;
                };
                int dameColumnas()
                {
                        return nCol;
                };
                bool dameElem(unsigned int c, unsigned int f, T& d)
                {
                        if ((c <= nCol) && (f <= nFil)) //puede salirse de rango puede, y se sale!!XD asique he quitado los =
                        {
                                //asigna(d, matriz[c][f]);
                                d = matriz[c][f];
                                return true;
                        }
                        return false;
                };
                bool ponValor(int c, int f, const T &d)
                {
//                        borrarDatoMat(matriz[c][f]); //por si T es un puntero
//                        asigna(matriz[c][f], d);
                        matriz[c][f] = d;
                        return true; //:D
                }
                bool salvar(ofstream &sal);
                bool cargar(ifstream &ent);
};
template<class T>
tMatriz<T>::tMatriz(int c, int f,T inicial)
{
        matriz = new T*[c];
        nCol = c;
        nFil = f;
        for(int i = 0; i < c; i++) matriz[i] = new T[f];
        for(int i = 0; i < c; i++)
        {
                for (int j = 0; j < f; j++) //iniciaElemMatriz(matriz[i][j]);
                                            matriz[i][j] = inicial;
        }
};


template<class T>
bool tMatriz<T>::salvar(ofstream &sal)
{
        sal.write((char*)& nFil,sizeof(int));
        sal.write((char*)& nCol,sizeof(int));
        T b;
        for (int i= 0;i<nCol;i++)
        {
                for (int j= 0;j<nFil;j++)
                {
                        sal.write((char*) (&b), sizeof(T));
                }
        }
        return true;
};
template<class T>
bool tMatriz<T>::cargar(ifstream &ent)
{
        ent.read((char*)&nFil,sizeof(int));
        ent.read((char*)&nCol,sizeof(int));
        matriz= new T*[nCol];
        T b;
        for (int i= 0;i<nCol;i++)
        {
                matriz[i]= new T[nFil];
        }
        for (int i= 0;i<nCol;i++)
        {
                for(int j= 0;j<nFil;j++)
                {
                        ent.read((char*) (&b), sizeof(T));
                        ponValor(i,j,b);
                }
        }
        return true;
};
#endif
