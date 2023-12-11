#include "include/Drone.h"
#include "Upgrade.h"
#include <iostream>

Drone::Drone(double energia, double hp)
    : hp(hp), ORIGEM("Andromeda"), isDestroyed(false)
{
  name = "Default Name";
  this->upgradePtr = nullptr;
}

Drone::Drone(bool condicao_drone, const string &name) : hp(50.0)
{
  this->name = name;
};

Drone::Drone(const Drone &other) : hp(other.hp), ORIGEM(other.ORIGEM)
{

  this->name = other.name;
  this->isDestroyed = other.isDestroyed;
  this->upgradePtr = nullptr;
}

void Drone::setName(const std::string &str)
{
  std::string novoname = str.substr(0, 15); // Limita o tamanho da string
  this->name = novoname;
}

void Drone::addUpgrade(Upgrade *i)
{
  this->upgradePtr = i;
}

void Drone::removeUpgrade()
{
  delete upgradePtr;    // Libera a memória do objeto Upgrade atual
  upgradePtr = nullptr; // Redefine o ponteiro para nullptr
}

void Drone::takeDamage(int dano)
{
  this->hp -= dano;
}

int Drone::configDrone()
{
  int escolha;
  std::cout << "1 - Renamear Drone" << std::endl;
  std::cout << "2 - Reparar Drone (custo = 10 sucatas)" << std::endl;
  std::cin >> escolha;
  switch (escolha)
  {
  case 1:
    std::cout << "Digite o novo name: ";
    std::cin >> this->name;
    return 1;
    break;
  case 2:
    this->hp = 100;
    return 2;
    break;
  }
  return 0;
}

// logica das sobrecargas de operadores
Drone &Drone::operator=(const Drone &outroDrone)
{
  if (this != &outroDrone) // Evita auto-atribuição
  {
    this->hp = outroDrone.hp;
    this->name = outroDrone.name;
    this->isDestroyed = outroDrone.isDestroyed;
    this->upgradePtr = outroDrone.upgradePtr;
  }
  return *this;
}

bool Drone::operator==(const Drone &outroDrone) const
{
  if (name != outroDrone.name && ORIGEM != outroDrone.ORIGEM)
    return 0;
  return 1;
}

bool Drone::operator!=(const Drone &outroDrone) const
{
  return !(*this == outroDrone);
}

bool Drone::operator!() const
{
  return isDestroyed;
}

std::ostream &operator<<(std::ostream &os, const Drone &drone)
{
  os << "name: " << drone.name << std::endl;
  os << "Origin: " << drone.ORIGEM << std::endl;
  if (drone.upgradePtr != nullptr)
  {
    os << "Upgrade info:\n";
    os << "quantity:" << drone.upgradePtr->getQuantidade() << "\n";
    os << "integrity:" << drone.upgradePtr->getIntegridade() << "\n";
  }
  if (drone.isDestroyed == 0)
    std::cout << "o drone está disponivel para usar !\n";
  else
    std::cout << "o drone está destruído !\n";
  return os;
}

// Implementação da classe Upgrade
Upgrade::Upgrade() : integridade(0.0), quantidade(0) {}

Upgrade::Upgrade(int quantidade, double integridade) : quantidade(quantidade), integridade(integridade) {}

Upgrade::Upgrade(const Upgrade &outroUpgrade) : integridade(outroUpgrade.integridade), quantidade(outroUpgrade.quantidade) {}

void Upgrade::setIntegridade(double novaIntegridade)
{
  this->integridade = novaIntegridade;
}

void Upgrade::setQuantidade(int novaQuantidade)
{
  this->quantidade = novaQuantidade;
}

// Construtor para a classe Scanner
Scanner::Scanner() : Upgrade(50, 95.0)
{
}

Scanner::Scanner(int quantidade, double integridade) : Upgrade(quantidade, integridade){};

Scanner::Scanner(const Scanner &outroScanner) : Upgrade(outroScanner)
{
}

Drone::~Drone() // destrutor
{
  if (upgradePtr != nullptr)
  {
    delete upgradePtr; // Deleta o objeto Upgrade apenas se ele existir
  }
}