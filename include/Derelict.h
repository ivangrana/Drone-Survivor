#ifndef DERELICT_H
#define DERELICT_H

#include <string>
#include <vector>
using std::string;

struct Room
{
    Room(int id_Room, int scrap) : id(id_Room), scrap(scrap) {}
    int id;
    int scrap;
    std::vector<Room *> connected_rooms;
};

class Derelict
{
    friend std::ostream &operator<<(std::ostream &os, const Derelict &nave);

public:
    // Constructor
    Derelict(int);
    Derelict(const string &, int);
    Derelict(const Derelict &);
    // Destructor


    void setIntegrity(int);
    void setEnergia(double);
    void setName(const string &);
    void setisVisited();

    int gethull_integrity() const;
    double getEnergia() const;

    const string &getname() const;
    void printStatus() const;
    bool getisVisited() const;

    // sobrecarga dos operadores
    Derelict &operator=(const Derelict &);
    bool operator==(const Derelict &) const;
    bool operator!=(const Derelict &) const;
    bool operator!() const;

    void addRoom(int, int);
    void connectRooms(int, int);
    void showRooms() const;
    bool checkConnection(int, int) const;

private:
    int hull_integrity;
    bool isVisited;
    string name;
    std::vector<Room *> Rooms;
};

#endif // DERELICT_H