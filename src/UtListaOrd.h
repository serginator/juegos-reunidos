//---------------------------------------------------------------------------

#ifndef UtListaOrdH
#define UtListaOrdH
#include "UtLista.h"

using namespace std;
//---------------------------------------------------------------------------

template <typename T, bool(Menor)(const T &,const T &)>
class tListaOrd : protected tLista<T>
{
        public:
                tListaOrd()
                {
                        tLista<T>();
                };
                ~tListaOrd() throw()
                {

                };
                void clear() throw()
                {
                        tLista<T>::clear();
                };
                int size() const throw()
                {
                        return tLista<T>::size();
                };
                bool empty() const throw()
                {
                        return tLista<T>::empty();
                };
                void at(int Pos, T &E)const throw(ErrRango)
                {
                        tLista<T>::at(Pos, E);
                };
                T &at(int Pos) const throw(ErrRango)
                {
                        return tLista<T>::at(Pos);
                };
                bool insert(const T &E) throw(bad_alloc)
                {
                        int pos;
                        if(!find(E,pos))
                        {
                                tLista<T>::insert(pos, E);
                                return true;
                        }
                        return false;
                };
                bool erase(int Pos) throw(ErrRango)
                {
                        tLista<T>::erase(Pos);
                        return true;
                };
                bool find(const T &E, int &Pos) const throw()
                {
                        int numElem = size();
                        /*Pos = (numElem / 2);*/
                        Pos = 0;
                        posicionPI(Pos);
                        if (numElem == 0)
                        {
                                return false;
                        }
                        else if (numElem == 1)
                        {
                                if((!Menor(E, pi->pCur->dato)) && (!Menor(pi->pCur->dato, E)))
                                {
                                        return true;
                                }
                                else
                                {
                                        if(Menor(pi->pCur->dato, E))
                                        {
                                                iniciaPI();
                                                avanzaPI();
                                        }
                                        else
                                        {
                                                iniciaPI();
                                        }
                                        return false;
                                }
                        }
                        //else if (Menor(pi->pCur->dato, E))
                        //{
                                //avanzaPI();
                                if(buscaPosAvanzando(E))
                                {
                                        Pos = pi->ind;
                                        return true;
                                }
                                Pos = pi->ind;
                                return false;
                        //}
                        /*else
                        {
                                return buscaPosRetrocediendo(E);
                        } */
                };
                bool buscaPosAvanzando(const T d) const
                {
                        iniciaPI();
                        while((pi->pCur->sig != pCab) && Menor(pi->pCur->dato,d))
                        {
                                avanzaPI();
                        }
                        return (!Menor(d, pi->pCur->dato) && !Menor(pi->pCur->dato, d));
                };
                /*bool buscaPosRetrocediendo(const T d)
                {
                        while((pi->pCur != pCab) && !Menor(pi->pCur->dato, d))
                        {
                                retrocedePI();
                        }
                        return (!Menor(d, pi->pCur->dato) && !Menor(pi->pCur->dato, d));
                };*/
};
//---------------------------------------------------------------------------
#endif
