//---------------------------------------------------------------------------

#ifndef UtListaH
#define UtListaH
#include "Excepciones.h"
using namespace std;
//---------------------------------------------------------------------------

template <class T>
class tLista
{
        protected:
                struct tNodo
                {
                        T dato;
                        tNodo* ant;
                        tNodo* sig;
                };
                struct tPi
                {
                        tNodo* pCur;
                        int ind;
                };


                tNodo* pCab;
                int cont;
                tPi* pi;


        public:

                tLista()
                {
                        cont = 0;
                        pCab = new tNodo;
                        pCab->ant = pCab;
                        pCab->sig = pCab;
                        pi = new tPi;
                        iniciaPI();
                };
                virtual ~tLista() throw()
                {
                        clear();
                        delete pCab;
                        pCab = NULL;
                        delete pi;
                        pi = NULL;
                        cont = 0;
                };
                void clear() throw()
                {
                        int contador = cont;
                        for(int i = 0; i < contador; i++)
                        {
                                pop_back();
                        }
                };
                int size() const throw()
                {
                        return cont;
                };
                bool empty() const throw()
                {
                        return (cont==0);
                };
                bool at(int Pos, T& E) const throw()
                {
                        posicionPI(Pos);
                        return elemPI(E); //:D
                };
                T& at(int Pos) throw(ErrRango)
                {
                        int tam;
                        tam = size();
                        if((Pos < tam) && (Pos >= 0))
                        {
                                posicionPI(Pos);
                                return elemPI();//;D
                        }
                        else throw ErrRango("lista:at");
                };
                void insert(int Pos, const T& E) throw(ErrRango, bad_alloc)
                {
                        if((Pos <= cont) && (Pos >= 0))
                        {
                                posicionPI(Pos);
                                insertPI(E);
                        }
                        else throw ErrRango("lista:insert");
                };
                void erase(int Pos) throw(ErrRango)
                {
                        if((Pos < cont) && (Pos >= 0))
                        {
                                posicionPI(Pos);
                                quitaPI();
                        }
                        else throw ErrRango("lista:erase");
                };
                bool front(T& E) const throw()
                {
                        E = pCab->sig->dato;
                        return true;
                };
                const T& front() const throw(ErrVacia)
                {
                        if(!empty())
                        {
                                return pCab->sig;
                        }
                        else throw ErrVacia("lista:front");
                };
                void push_front(const T& E) throw(bad_alloc)
                {
                        if(cont == 0)
                        {
                                tNodo* aux = new tNodo;
                                aux->dato = E;
                                aux->sig = pCab;
                                aux->ant = pCab;
                                pCab->sig = aux;
                                pCab->ant = aux;
                                cont++;
                        }
                        else
                        {
                                tNodo* aux = new tNodo;
                                aux->dato = E;
                                aux->sig = pCab->sig;
                                aux->ant = pCab;
                                pCab->sig->ant = aux;
                                pCab->sig = aux;
                                cont++;
                        }
                };
                void pop_front() throw(ErrVacia)
                {
                        if(!empty())
                        {
                                tNodo* aux = pCab->sig;
                                aux->dato = pCab->sig->dato;
                                pCab->sig->sig->ant = pCab;
                                pCab->sig = pCab->sig->sig;
                                delete aux;
                                aux = NULL;
                                cont--;
                        }
                        else throw ErrVacia("lista:pop_front");
                };
                bool back(T& E) const throw(ErrVacia)
                {
                        if(!empty())
                        {
                                E = pCab->ant;
                                return true;
                        }
                        else throw ErrVacia("lista:back");
                };
                const T& back() const throw(ErrVacia)
                {
                        if(!empty())
                        {
                                return pCab->ant;
                        }
                        else throw ErrVacia("lista:back");
                };
                void push_back(const T& E) throw(bad_alloc)
                {
                        tNodo* aux = new tNodo;
                        aux->dato = E;
                        aux->sig = pCab;
                        aux->ant = pCab->ant;
                        pCab->ant->sig = aux;
                        pCab->ant = aux;
                        cont++;
                };
                void pop_back() throw(ErrVacia)
                {
                        if(!empty())
                        {
                                tNodo* aux = pCab->ant;
                                pCab->ant->ant->sig = pCab;
                                pCab->ant = pCab->ant->ant;
                                delete aux;
                                aux = NULL;
                                cont--;
                        }
                        else throw ErrVacia("lista:pop_back");
                };

        protected:

                bool iniciaPI() const throw()
                {
                        pi->ind = 0;
                        pi->pCur = pCab->sig;
                        return true;
                };
                bool avanzaPI() const throw()
                {
                        if(pi->pCur == pCab->ant)
                        {
                                pi->pCur = pCab->sig;
                                pi->ind = 0;
                        }
                        else
                        {
                                pi->ind++;
                                pi->pCur = pi->pCur->sig;
                        }
                        return true;
                };
                bool retrocedePI() const throw()
                {
                        if(pi->pCur == pCab->sig)
                        {
                                pi->pCur = pCab->ant;
                                pi->ind = (size() - 2);
                        }
                        else
                        {
                                pi->ind--;
                                pi->pCur = pi->pCur->ant;
                        }
                        return true;
                };
                void posicionPI(int Pos) const throw(ErrRango)
                {
                        if ((Pos > cont) || (Pos < 0))
                        {
                                throw ErrRango("lista:posicionPI");
                        }
                        else if((cont == 0) || (Pos == 0))
                        {
                                iniciaPI();
                                return;
                        }
                        else if(Pos != pi->ind)
                        {
                                int retrocede = 0;
                                int avanza = 0;
                                avanza = Pos - pi->ind;
                                if(avanza < 0)
                                {
                                        avanza += (cont);
                                }
                                retrocede = pi->ind - Pos;
                                if(retrocede < 0)
                                {
                                        retrocede += (cont);
                                }
                                if (avanza <= retrocede)
                                {
                                        for(int i = 0;i < avanza;i++)
                                        {
                                                avanzaPI();
                                        }
                                }
                                else if(avanza > retrocede)
                                {
                                        for(int i = 0;i < retrocede;i++)
                                        {
                                                retrocedePI();
                                        }
                                }
                        }
                };
                bool elemPI(T& E) const throw()
                {
                        E = pi->pCur->dato;
                        return true;
                };
                T& elemPI() throw()
                {
                        return pi->pCur->dato;
                };
                const T& elemPI() const throw()
                {
                        return pi->pCur->dato;
                }
                bool elemAntPI(T& E) const throw()
                {
                        E = pi->pCur->ant->dato;
                        return true;
                };
                void insertPI(const T& E) throw(bad_alloc)
                {
                        if(cont == 0)
                        {
                                push_front(E);
                                iniciaPI();
                                return;
                        }
                        else
                        {
                                if(cont == 1)
                                {
                                        if(pi->pCur->dato < E)
                                        {
                                                push_back(E);
                                                return;
                                        }
                                        else
                                        {
                                                push_front(E);
                                                return;
                                        }
                                }
                                else
                                {
                                        if ((pi->ind == cont-1) && (pi->pCur->dato < E))
                                        {
                                                push_back(E);
                                                return;
                                        }
                                        else
                                        {
                                                if((pi->ind == 0) && (E < pi->pCur->dato))
                                                {
                                                        push_front(E);
                                                        return;
                                                }
                                                else
                                                {
                                                        if((pi->ind == 0) && (pi->pCur->dato < E))
                                                        {
                                                                avanzaPI();
                                                        }
                                                }
                                        }
                                }
                        }
                        tNodo* aux = new tNodo;
                        aux->dato = E;
                        aux->sig = pi->pCur;
                        aux->ant = pi->pCur->ant;
                        pi->pCur->ant->sig = aux;
                        pi->pCur->ant = aux;
                        cont++;
                };
                void quitaPI()
                {
                        tNodo* aux = pi->pCur;
                        pi->pCur->ant->sig = pi->pCur->sig;
                        pi->pCur->sig->ant = pi->pCur->ant;
                        pi->pCur = pi->pCur->ant;
                        pi->ind--;
                        delete aux;
                        aux = NULL;
                        cont--;
                };
};
#endif
