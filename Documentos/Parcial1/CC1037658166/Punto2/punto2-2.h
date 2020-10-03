class CrapsGame
{
public:

    CrapsGame(int);
    
    void play();
    void determine_bet();
    int Throw_two_dices();
    void triumph_state();
    void no_triumph_state();
    
private:
    
    int SaldoenBanco;
    int val;
    int bet_val;
    int triumph_val;
    bool B;
    int are_ya_winning; 
    
};
