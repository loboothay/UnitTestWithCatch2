#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Avaliador.hpp"

Leilao emOrdemCrescente()
{
    Lance primeiroLance(Usuario("Thaynara"), 1000);
    Lance segundoLance(Usuario("Patricia"), 2000);
    Leilao leilao("Fiat 147 0Km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    
    return leilao;
}

Leilao emOrdemDecrescente()
{
    Lance primeiroLance(Usuario("Thaynara"), 2000);
    Lance segundoLance(Usuario("Patricia"), 1000);
    Leilao leilao("Fiat 147 0Km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    
    return leilao;
}

TEST_CASE("Avaliador") {
    // Arrange - Given
    Avaliador leiloeiro;
    
    SECTION("Leilões ordenados") {
        Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());

        SECTION("Deve recuperar maior lance de leilão") {
            // Act - When
            leiloeiro.avalia(leilao);

            // Assert - Then
            REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
        }

        SECTION("Deve recuperar menor lance de leilão") {
            // Act - When
            leiloeiro.avalia(leilao);

            // Assert - Then
            REQUIRE(1000 == leiloeiro.recuperaMenorValor());
        }
    }

    SECTION("Deve recuperar os 3 maiores lances") {
        // Arrange - Given
        Lance primeiroLance(Usuario("Thaynara"), 1000);
        Lance segundoLance(Usuario("Patricia"), 2000);
        Lance terceiroLance(Usuario("Artur"), 1500);
        Lance quartoLance(Usuario("Anonimo"), 2500);
        
        Leilao leilao("Fiat 147 0Km");
        leilao.recebeLance(primeiroLance);
        leilao.recebeLance(segundoLance);
        leilao.recebeLance(terceiroLance);
        leilao.recebeLance(quartoLance);

        // Act - When
        leiloeiro.avalia(leilao);

        // Assert - Then
        auto maiores3Lances = leiloeiro.recuperaMaioresTresLances();
        REQUIRE(3 == maiores3Lances.size());
        REQUIRE(2500 == maiores3Lances[0].recuperaValor());
        REQUIRE(2000 == maiores3Lances[1].recuperaValor());
        REQUIRE(1500 == maiores3Lances[2].recuperaValor());
    }
}