#include "GameManager.h"

/*
Bonjour, bienvenue dans le merveilleux monde cach� de Squadron24, bonne lecture !
*/

int main()
{
    GameManager* GameManagerSquadron24 = new GameManager();
    GameManagerSquadron24->GetInstance();
    return GameManagerSquadron24->GameLoop();
}