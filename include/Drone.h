#ifndef DRONE_H
#define DRONE_H

#include <vector>
#include <string>
#include "Upgrade.h"
using std::string;
using std::vector;

class Drone
{

    friend std::ostream &operator<<(std::ostream &os, const Drone &drone);

public:
    // construtores
    Drone(double, double);
    Drone(bool, const string &);
    Drone(const Drone &);
    // destrutor
    ~Drone();

    // Sobrecarga dos operadores
    Drone &operator=(const Drone &outroDrone);
    bool operator==(const Drone &outroDrone) const;
    bool operator!=(const Drone &outroDrone) const;
    bool operator!() const;

    void setName(const string &);
    // metodos Get
    inline double gethp() const { return hp; }
    inline string getName() const { return name; }
    void addUpgrade(Upgrade *);
    void removeUpgrade();

    int configDrone();
    void takeDamage(int);
private:
    double hp;
    bool isDestroyed;
    Upgrade *upgradePtr;
    string name;
    const string ORIGEM;
};

#endif