#include "Avaliador.hpp"
#include <iostream>

int main(){
    //Arrange - Given
    Lance primeiroLance(Usuario("Thaynara"), 1000);
    Lance segundoLance(Usuario("Patricia"), 2000);
    Leilao leilao("Fiat 147 10Km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    Avaliador leiloeiro;

    //Act - When
    leiloeiro.avalia(leilao);

    //Assert -Then
    float valorEsperado = 2000;
    if (valorEsperado == leiloeiro.recuperaMaiorValor())
    {
        std::cout<<"Teste OK"<<std::endl;
    }else{
        std::cout<<"Teste NOK"<<std::endl;
    }
    return 0;
}