#include "alpha_beta.h"

void print_usage(void){
    cout << "Usage of alpha_beta to tic tac toe\nALPHA_BETA <state> <player>" << endl;
    cout << "Example: MINIMAX .X.O..... ONE" << endl;
    cout << "ONE -- player X" << endl;
    cout << "TWO -- player O" << endl;
    exit(-1);
}

ivec_t parse_state(char const *argv){
    ivec_t s;
    int c = 0;
    int p = 0;
    if ((int)strlen(argv) != BAORD_SIZE)
        print_usage();
    for (c = 0; c < BAORD_SIZE; ++c){
        p = ((argv[c] == '.') ? 0 : ((argv[c] != 'X') ? -1 : 1));
        s.push_back(p);
        
    }
    return s;
}


int parse_player(char const *argv){
    if (strncmp(argv,"ONE",3) == 0)
        return 1;
    else if (strncmp(argv,"TWO",3) == 0)
    {
        return -1;
    }
    print_usage(); 
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc < 2){
        print_usage();
    }
    srand(time(NULL));
    board_t b = {};
    b.state = parse_state(argv[1]);
    b.next_player = parse_player(argv[2]);
    b.winner = 0;
    b.full = false;
    board_t result = beta_p(b,-1000,1000,0);
    printf("The best move is: %d\n",result.move);

    return 0;
}


