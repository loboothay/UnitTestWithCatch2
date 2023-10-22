#include "Avaliador.hpp"

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
}

float Avaliador::recuperaMaiorValor() const{
    return maiorValor;
}

float Avaliador::recuperaMenorValor() const{
    return menorValor;
}