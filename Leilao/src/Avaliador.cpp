#include "Avaliador.hpp"
#include <algorithm>

void Avaliador::avalia(Leilao leilao){
    std::vector<Lance>lances = leilao.recuperaLances();
    /*percorrendo todos os lances*/
    for(Lance lance:lances){
        if(lance.recuperaValor()>maiorValor){
            maiorValor = lance.recuperaValor();
        }else if(lance.recuperaValor() < menorValor){
            menorValor = lance.recuperaValor();
        }
    }

    std::sort(lances.begin(), lances.end(), ordenaLances);
    size_t tamanho = lances.size()>3?3:lances.size();
    maioresTresLances = std::vector<Lance>(lances.begin(), lances.begin() + tamanho);
}

float Avaliador::recuperaMaiorValor() const{
    return maiorValor;
}

float Avaliador::recuperaMenorValor() const{
    return menorValor;
}

std::vector<Lance> Avaliador::recuperaMaioresTresLances() const{
    return maioresTresLances;
}

bool Avaliador::ordenaLances(const Lance& lance1, const Lance& lance2){
    return lance1.recuperaValor()>lance2.recuperaValor();
}