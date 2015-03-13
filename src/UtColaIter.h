//---------------------------------------------------------------------------

#ifndef UtColaIterH
#define UtColaIterH

#include "UtLista.h"
//---------------------------------------------------------------------------
template <class T> class tColaIter : protected tLista<T>
{
        private:

        public:
                tColaIter()
                {
                        tLista<T>();
                };
                ~tColaIter() throw()
                {

                };
                int size() const throw()
                {
                        return tLista<T>::size();
                };
                bool empty() const throw()
                {
                        return tLista<T>::empty();
                };
                void push(const T& E) throw(bad_alloc)
                {
                        push_back(E);
                };
                bool pop() throw()
                {
                        if(empty())
                        {
                                return false;
                        }
                        tLista<T>::pop_front();
                        return true;
                };
                bool front(T &E) const throw()
                {
                        return tLista<T>::front(E);
                };
                const T &front() const throw(ErrVacia)
                {
                        tLista::front(T &E);
                };

                bool iniciaIter() throw()
                {
                        if(empty())
                        {
                                return false;
                        }
                        posicionPI(0);
                        return true;
                };
                bool avanzaIter() throw()
                {
                        if(pi->ind == cont)
                        {
                                return false;
                        }
                        return avanzaPI();

                };
                bool actualIter(T& E) throw()
                {
                        if(pi->ind == cont)
                        {
                                return false;
                        }
                        return elemPI(E);
                };
};
#endif
