#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/*
class Grill
{
  const int GRILLE_LARGEUR = 23;
  const int GRILLE_HAUTEUR = 21;
};

class Ship
{
    int a_longueur;
    int a_largeur;
    int a_rhum;
    int a_vitesse;
    int a_orientation; // 0-5

public:
    Ship()
    {
        a_longueur = 3;
        a_largeur = 1;
    }
};
*/
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
  int vx,vy;

    // game loop
    while (1)
    {
        int myShipCount; // the number of remaining ships
        cin >> myShipCount;
        cin.ignore();
        int entityCount; // the number of entities (e.g. ships, mines or cannonballs)
        cin >> entityCount;
        cin.ignore();
        for (int i = 0; i < entityCount; i++)
        {
            int entityId;
            string entityType;
            int x,y;
            int arg1;
            int arg2;
            int arg3;
            int arg4;
            cin >> entityId >> entityType >> x >> y >> arg1 >> arg2 >> arg3 >> arg4;
            cin.ignore();

            if(entityType == "BARREL")
            {
              vx = x;
              vy = y;
              cerr << "Du rhum" << endl;
            }

        }

        for (int i = 0; i < myShipCount; i++)
        {
            cout << "MOVE " << vx << " " << vy << endl;
        }
    }
}
