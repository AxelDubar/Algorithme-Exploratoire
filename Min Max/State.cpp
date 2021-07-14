#include "State.h"


int State::utility(){
    int res=isTerminal();
    return res*(-1);
}



int State::terminalValue(int joueur){
    int gagnant=0;
    if(grille[0][0]!=0 && grille[0][0]==grille[0][1] && grille[0][1]==grille[0][2])//ligne 0 
        gagnant=grille[0][0];
    else if (grille[0][0]!=0 && grille[0][0]==grille[1][0] && grille[1][0]==grille[2][0])//colonne 0
        gagnant= grille[0][0];
    else if (grille[0][0]!=0 && grille[0][0]==grille[1][1] && grille[1][1]==grille[2][2])//diag gauche droite
        gagnant= grille[0][0];
    else if (grille[1][0]!=0 && grille[1][0]==grille[1][1] && grille[1][0]==grille[1][2])//ligne 1
        gagnant= grille[1][0];
    else if (grille[0][1]!=0 && grille[0][1]==grille[1][1] && grille[0][1]==grille[2][1])//colonne 1
        gagnant= grille[0][1];
    else if (grille[0][2]!=0 && grille[0][2]==grille[1][1] && grille[0][2]==grille[2][0])//diag droite gauche
        gagnant= grille[0][2];
    else if (grille[2][0]!=0 && grille[2][0]==grille[2][1] && grille[2][0]==grille[2][2])//ligne 2
        gagnant= grille[2][0];
    else if (grille[0][2]!=0 && grille[0][2]==grille[1][2] && grille[0][2]==grille[2][2])//colonne 2
        gagnant= grille[0][2];
    

    if(gagnant==joueur){
        return 1*10;
    }
    else if(gagnant==joueur*(-1))
    {
        return (-1)*10;
    }
    else return 0;
}

int State::tourRestant(){
    int res=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grille[i][j]==0){
                res++;
            }
        }
    }
    return res;
}

bool State::isTerminal(){
    if(terminalValue(currentPlayer)!=0){
        return true;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grille[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

std::vector<State> State::actions(){
    vector<State> statesresult;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grille[i][j]==0){
                grille[i][j]=currentPlayer;
                statesresult.push_back(State(grille,currentPlayer*(-1)));
                grille[i][j]=0;
            }
        }
    }
    return statesresult;
}
string State::toString(){
    string res="";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            switch(grille[i][j]){
                case 1:
                    res+="O";
                    break;
                case -1:
                    res+="X";
                    break;
                default:
                    res+="_";
            }
//            res+=to_string(grille[i][j]);
            res+=" ";
        }
        res+="\n";
    }
    res+=std::to_string(currentPlayer);
    return res;
}


State State::result(State action){
    State newState=State();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            newState.grille[i][j]=action.grille[i][j];
        }
    }
    newState.currentPlayer=action.currentPlayer;
    return newState;
}

