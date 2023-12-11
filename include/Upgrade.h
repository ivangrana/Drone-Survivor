#ifndef UPGRADE_H
#define UPGRADE_H
#include <string>
using std::string;

class Upgrade
{
public:
    Upgrade();
    Upgrade(int, double);
    Upgrade(const Upgrade&);

    inline double getIntegridade() const { return integridade; }
    inline int getQuantidade() const { return quantidade; }

    void setIntegridade(double);
    void setQuantidade(int);
    

private:
    double integridade;
    int quantidade;
};

class Scanner : public Upgrade
{
public:
    Scanner();
    Scanner(int,double);
    Scanner(const Scanner &);
    void usarScanner();
};

// class Turret : public Upgrade{
//     public: 
//     Turret();
//     Turret(int,double);
//     Turret(const Turret &);
//     void usarTurret();
// };


#endif