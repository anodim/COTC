#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

class Coordonnee3d
{
public:
    int x;
    int y;
    int z;
};

class Coordonnee2d
{
public:

    int x;
    int y;

    Coordonnee2d()
    {
        x = 0;
        y = 0;
    }

    Coordonnee2d(int mx,int my)
    {
        x = mx;
        y = my;
    }

    Coordonnee2d(int mx,int my,int mz)
    {
        x = mz;
        y = mx+(mz-(mz&1))/2;
    }

    Coordonnee3d get3DCoord()
    {
        Coordonnee3d c3;
        c3.x = y - (x-(x&1))/2;
        c3.z = x;
        c3.y = -c3.x-c3.z;

        return c3;
    }
};

int distanceHex3D(Coordonnee2d c1,Coordonnee2d c2)
{
    Coordonnee3d a = c1.get3DCoord();
    Coordonnee3d b = c2.get3DCoord();
    return (abs(a.x-b.x) + abs(a.y-b.y) + abs(a.z - b.z)) / 2;
}

/*
class Grill
{
  const int GRILLE_LARGEUR = 23;
  const int GRILLE_HAUTEUR = 21;
};
*/

class Ship
{
    int a_longueur;
    int a_largeur;
    int a_rhum;
    int a_vitesse;
    int a_orientation; // 0-5
    int a_x,a_y;
    int a_xDir,a_yDir;
public:
    Ship()
    {
        a_longueur = 3;
        a_largeur = 1;
    }

    void setCoord(int x, int y)
    {
        a_x = x;
        a_y = y;
    }
    void setCoordDir(int x, int y)
    {
        a_xDir = x;
        a_yDir = y;
    }
    Coordonnee2d getCoord()
    {
        return Coordonnee2d(a_x,a_y);
    }
    Coordonnee2d getCoordDir()
    {
        return Coordonnee2d(a_xDir,a_yDir);
    }
    void setInfo(int rhum,int vitesse,int orientation)
    {
        a_rhum = rhum;
        a_vitesse = vitesse;
        a_orientation=orientation;
    }
};

class Barrels
{
    Coordonnee2d c[26];
    int taille[26];
    int nbBarrel;
public:
    Barrels()
    {
        nbBarrel = 0;
    }

    void add(int x,int y,int taille)
    {
        nbBarrel++;
        c[nbBarrel-1].x = x;
        c[nbBarrel-1].y = y;
    }

    void reset()
    {
        nbBarrel = 0;
    }

    int getNbBarrel()
    {
        return nbBarrel;
    }
};

using namespace std;

int main()
{
    Ship player;
    Ship player2;

    Barrels bar;

    // game loop
    while (1)
    {
        player.setCoordDir(999,999);
        bar.reset();

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

            if(entityType == "SHIP")
            {
                if(arg4 == 1)
                {
                    player.setCoord(x,y);
                    player.setInfo(arg3,arg2,arg1);
                }
                else
                {
                    player2.setCoord(x,y);
                    player2.setInfo(arg3,arg2,arg1);
                }
            }

            if(entityType == "BARREL")
            {
                bar.add(x,y,arg1);
            }
        }

        for (int i = 0; i < myShipCount; i++)
        {
            if(bar.getNbBarrel() > 0)
                cout << "MOVE " << player.getCoordDir().x << " " << player.getCoordDir().y << endl;
            else
            {
                if(distanceHex3D(player.getCoord(),player2.getCoord()) <= 10) // distance de tir (10 de memoire)
                {
                    cout << "FIRE " << player2.getCoord().x << " " << player2.getCoord().y << endl;
                }
                else
                {
                    // deplacement vers l'autre joueur
                    cout << "MOVE " << player2.getCoord().x << " " << player2.getCoord().y << endl;
                }
            }
        }
    }
}
