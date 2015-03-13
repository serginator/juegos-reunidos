#ifndef UArbolH
#define UArbolH
#include "UtLista.h"
#include "Excepciones.h"

template <class T> class Arbol
{
	protected:
		T dato;
		tLista<Arbol<T>*> hijos;


	//metodos
	public:
		Arbol(const T& d)
		{
			dato = d;
		};
                virtual ~Arbol(){};
		int numHijos() const throw()
		{
			return hijos.size();
		};
		virtual bool esHoja() const throw()
		{
                        return hijos.size()==0;
		};
		const T& getDato() const throw()
		{
			return dato;
		};
		Arbol* getHijo(int i) const throw(ErrRango)
		{
			return hijos.at(i);
		};
		void addHijo(Arbol* a) throw(bad_alloc)
		{
                        hijos.push_back(a);
		};

};
#endif
