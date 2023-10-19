#include "Avaliador.hpp"
#include <iostream>

int main(){
    Lance primeiroLance(Usuario("Thaynara"), 1000);
    Lance segundoLance(Usuario("Patricia"), 2000);
    Leilao leilao("Fiat 147 10Km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    Avaliador leiloeiro;
    leiloeiro.avalia(leilao);

    std::cout<<leiloeiro.recuperaMaiorValor() << std::endl;
    return 0;
}