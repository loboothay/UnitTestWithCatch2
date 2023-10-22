#ifndef Avaliador_hpp
#define Avaliador_hpp
#include <climits>
#include "Leilao.hpp"

class Avaliador
{
    private: 
        float maiorValor = INT_MIN;
        float menorValor = INT_MAX;
        std::vector<Lance> maioresTresLances;
        static bool ordenaLances(const Lance&, const Lance&);
    public:
        void avalia(Leilao);
        float recuperaMaiorValor() const;
        float recuperaMenorValor() const;
        std::vector<Lance> recuperaMaioresTresLances() const;
};

#endif /*Avaliador_hpp*/