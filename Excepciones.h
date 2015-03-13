//---------------------------------------------------------------------------

#ifndef ExcepcionesH
#define ExcepcionesH
#include <stdexcept>
//---------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------
class ErrRango
{
        protected:
                string m;
        public:
                ErrRango(string M = "Error Rango")
                {
                        m = M;
                };
                string getMensaje()
                {
                        return m;
                };
};
//---------------------------------------------------------------------------
class ErrVacia
{
        protected:
                string m;
        public:
                ErrVacia(string M = "Error Vacia")
                {
                        m = M;
                };
                string getMensaje()
                {
                        return m;
                };
};
//----------------------------------------------------------------------------
#endif
 