#include "Derelict.h"
#include <iostream>

Derelict::Derelict(int integrity)
{
    setIntegrity(integrity);
    name = "Derelict";
}


void Derelict::setIntegrity(int integrity)
{
    this->hull_integrity = integrity;
}

std::ostream &operator<<(std::ostream &os, const Derelict &ship)
{

    std::string shipArt = R"(
        ____,----._
   ,--'| _|" o;.  `\____        ____  ,,=====._                     
 .=|.':| U| ;:;:  .- \,,`-.===='}.,'\//       "`====\_____________________
(]=|;: |o |  ,.  (  :;)::(----------|||----------):;::>}_________}========
 `=| :;|  | ,: o  `-_/``,-`====.}___/\\       _,====/                
   `--.|__|  .:  _,/ """              ``=====''
           `----'                                                              
)";
    os << "Nome: " << ship.name << "\n";
    os << "integridade: " << static_cast<int>(ship.hull_integrity) << "\n";
    os << shipArt << "\n";
    return os;
}
