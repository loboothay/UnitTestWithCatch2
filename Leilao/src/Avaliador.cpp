#include "Avaliador.hpp"

void Avaliador::avalia(Leilao leilao){
    std::vector<Lance>lances = leilao.recuperaLances();
    /*percorrendo todos os lances*/
    for(Lance lance:lances){
        if(lance.recuperaValor()>maiorValor){
            maiorValor = lance.recuperaValor();
        }
    }
}

float Avaliador::recuperaMaiorValor() const{
    return maiorValor;
}