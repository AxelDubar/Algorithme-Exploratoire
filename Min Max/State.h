#ifndef __STATE_H__
#define __STATE_H__

#include <iostream> 
#include <vector> 
  
using namespace std; 

class State{
public:
    int grille[3][3];
    int currentPlayer;//1 player1, -1 player2

    State(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                grille[i][j]=0;
            }
        }
        currentPlayer=1;
    }

    State(State* copiedState){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                grille[i][j]=copiedState->grille[i][j];
            }
        }
        currentPlayer=copiedState->currentPlayer;
    }

    State(int newGrille[3][3],int numJoueur){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                grille[i][j]=newGrille[i][j];
            }
        }
        currentPlayer=numJoueur;
    }

    State result(State action);
    bool isTerminal();
    int terminalValue(int joueur);
    std::vector<State> actions();
    int utility();
    string toString();
    int tourRestant();
};
#endif /* defined(__STATE_H__) */
