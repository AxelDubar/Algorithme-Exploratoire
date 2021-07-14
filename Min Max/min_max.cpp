
#include "State.h"
#include <ctime>
#include <limits>
int maxValue(State currentState,int joueur,int prof);
int minValue(State currentState,int joueur,int prof);

int nbEtat=0;

class Probleme{
    public:
    State initialState;
    State currentState;
    State finalState;
    
    vector<State> assignement;
    int cost;

    Probleme(State init){
        initialState=init;
        cost=0;
    }
};

void deep_first_search(Probleme prob){
    if(prob.currentState.isTerminal())
        return;
    vector<State> actions=prob.currentState.actions();
    //for(int i=0;i<actions.size;i++){
        prob.currentState=actions.at(0);

        std::cout<<prob.currentState.toString()<<"\n"<<std::endl;
        prob.assignement.push_back(prob.currentState);
        deep_first_search(prob);

   // }
}  

int maxValue(State currentState,int joueur,int prof){
    if(currentState.isTerminal())
        return currentState.terminalValue(joueur)-prof;
    vector<State> nextStates=currentState.actions();
    int valCoup=numeric_limits<int>::min();
    for(int i=0;i<nextStates.size();i++){
            valCoup=max(valCoup,minValue(currentState.result(nextStates.at(i)),joueur,prof+1));
    }
    //std::cout<<valCoup<<endl;
    return valCoup;
}

int minValue(State currentState,int joueur,int prof){
    if(currentState.isTerminal())
        return currentState.terminalValue(joueur)+prof;
    vector<State> nextStates=currentState.actions();
    int valCoup=numeric_limits<int>::max();
    for(int i=0;i<nextStates.size();i++){
        valCoup=min(valCoup,maxValue(currentState.result(nextStates.at(i)),joueur,prof+1));
        
    }
    return valCoup;
}


State miniMax_Decision(State currentState){//numJoueur est le joueur que l'ordi joue
    State nextState,possibleState;
    vector<State> actions=currentState.actions();
    int valCoup=std::numeric_limits<int>::min(), possibleVal;
    for(int i=0;i<actions.size();i++){
        possibleState=currentState.result(actions.at(i));
        possibleVal=minValue(possibleState,currentState.currentPlayer,0);

        std::cout<<possibleVal<<endl;
        if(valCoup<possibleVal){
            nextState=possibleState;
            valCoup=possibleVal;
        }
    }
    return nextState;
}


int main(void){
    std::srand(std::time(nullptr));
    State initial=State();
    string res=initial.toString();
    std::cout<<res<<std::endl;
    Probleme prob=Probleme(initial);
    //deep_first_search(prob);
    while(!initial.isTerminal()){
        if(initial.currentPlayer == 1)
            initial=miniMax_Decision(initial);
        else
            initial=initial.result(initial.actions()[std::rand()%initial.actions().size()]);

        std::cout<<initial.toString()<<std::endl;
    }
    //std::cout<<initial.toString()<<"  "<<nbEtat<<std::endl;
}

