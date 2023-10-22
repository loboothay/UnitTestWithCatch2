#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Avaliador.hpp"
#include <iostream>

TEST_CASE("Deve recuperar maior lance de leilão em ordem crescente"){
    //Arrange - Given
    Lance primeiroLance(Usuario("Thaynara"),1000);
    Lance segundoLance(Usuario("Patricia"),2000);
    Leilao leilao("Fiat 147 10KM");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    Avaliador leiloeiro;

    //Act - When
    leiloeiro.avalia(leilao);

    //Assert - Then
    REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
}

TEST_CASE("Deve recuperar maior lance de leilão em ordem decrescente"){
    //Arrange - Given
    Lance primeiroLance(Usuario("Thaynara"),2000);
    Lance segundoLance(Usuario("Patricia"),1000);
    Leilao leilao("Fiat 147 10KM");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    Avaliador leiloeiro;

    //Act - When
    leiloeiro.avalia(leilao);

    //Assert - Then
    REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
}

TEST_CASE("Deve recuperar menor lance de leilão em ordem decrescente"){
    //Arrange - Given
    Lance primeiroLance(Usuario("Thaynara"),2000);
    Lance segundoLance(Usuario("Patricia"),1000);
    Leilao leilao("Fiat 147 10KM");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    Avaliador leiloeiro;

    //Act - When
    leiloeiro.avalia(leilao);

    //Assert - Then
    REQUIRE(1000 == leiloeiro.recuperaMenorValor());
}

TEST_CASE("Deve recuperar os três maiores lances"){
    //Arrange - Given
    Lance primeiroLance(Usuario("Thaynara"),2000);
    Lance segundoLance(Usuario("Patricia"),1000);
    Lance terceiroLance(Usuario("Artur"),4000);
    Lance quartoLance(Usuario("Aika"),1500);
    Leilao leilao("Fiat 147 10KM");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    leilao.recebeLance(terceiroLance);
    leilao.recebeLance(quartoLance);

    Avaliador leiloeiro;

    //Act - When
    leiloeiro.avalia(leilao);

    //Assert - Then
    std::vector<Lance> maioresTresLances = leiloeiro.recuperaMaioresTresLances();
    REQUIRE(3 == maioresTresLances.size());
    REQUIRE(4000 == maioresTresLances[0].recuperaValor());
    REQUIRE(2000 == maioresTresLances[1].recuperaValor());
    REQUIRE(1500 == maioresTresLances[2].recuperaValor());
}
