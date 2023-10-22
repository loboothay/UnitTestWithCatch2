#ifndef Avaliador_hpp
#define Avaliador_hpp
#include <climits>
#include "Leilao.hpp"

class Avaliador
{
    private: 
        float maiorValor = INT_MIN;
        float menorValor = INT_MAX;
    public:
        void avalia(Leilao);
        float recuperaMaiorValor() const;
        float recuperaMenorValor() const;
};

#endif /*Avaliador_hpp*/