#include "map.h"

using namespace std;
Map::Map(int numMap)
{
    int i = 0;
    char buff[24];
    if(numMap == 1){
        ifstream in("Data/maps/map1.txt"); // окрываем файл для чтения
        if (in.is_open())
        {
            while (!in.eof() && i < HEIGHT_GAME_BOX_BY_64)
            {
                in.getline(buff, 24);
                mapLayout[i] = string(buff);
                i++;
            }
        }
        in.close();     // закрываем файл
    }
}

void Map::setElementsToVector(vector<vector<StationaryObj*>>* listOfWalls, vector<Enemy*>* vecOfEnemy){
    float X,Y = 3;

    for(int i=0; i < HEIGHT_GAME_BOX_BY_64; i++){
        X=3;
        vector<StationaryObj*> rowObjects;
        for(int j = 0; j < WIDTH_GAME_BOX_BY_64; j++){
            if(mapLayout[i][j] == '1')
                rowObjects.push_back(new BrickWall(X,Y));
            else if(mapLayout[i][j] == '0')
                rowObjects.push_back(new MetalWall(X,Y));
            else if(mapLayout[i][j] == '5')
                startPlayerPosition = Vector2f(X,Y);
            else if(mapLayout[i][j] == '4'){
                vecOfEnemy->push_back(new Enemy(Vector2f(X, Y)));
                spawnPoint = Vector2f(X, Y);
            }
            else if(mapLayout[i][j] == '#'){
                basePtr = new Base(X,Y);
                rowObjects.push_back(basePtr);
            }
            X += 64;
        }
        listOfWalls->push_back(rowObjects);
        Y += 64;
    }
}

Vector2f Map::getSpawnPoint(){
    return spawnPoint;
}

Vector2f Map::getStartPlayerPosition(){
    return startPlayerPosition;
}

Base* Map::getBasePtr(){
    return basePtr;
}
