#ifndef ALPHA_BETA_H
#define ALPHA_BETA_H

#include <iostream>
#include <ostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>
#include <string>

using namespace std;


#define BAORD_SIZE 9
#define PLAYER_ONE 1
#define PLAYER_TWO -1
#define NO_PLAYER 0
#define NBL 3
#define NBC 3


typedef struct board_t board_t;
typedef struct node_t node_t;
typedef std::vector<int> ivec_t;
typedef std::vector<node_t> nvec_t;

struct board_t{
    ivec_t state;
    int next_player;
    int move;
    int winner;
    bool full;
};


ivec_t get_next_moves(ivec_t state);
board_t get_next_board(board_t b, int m);
void print_board(board_t board);
board_t beta_p(board_t board, int alpha, int beta, int _depth);
board_t alpha_p(board_t board, int alpha, int beta, int _depth);
#endif 
