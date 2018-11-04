#include "alpha_beta.h"

int MAX_DEPTH = 10;


board_t alpha_p(board_t board, int alpha, int beta, int _depth){
    ivec_t nexts = {0};
    int mv,v;
    board_t next_board = {}, mini_board = {}, best = {};
    if (_depth == MAX_DEPTH || board.winner != 0 || board.full == true)
        return board;
    nexts = get_next_moves(board.state);
    if ((int)nexts.size() == 0){
        return board;
    }
    mv = -1.0;
    ivec_t::iterator i;
    for(i = nexts.begin(); i != nexts.end(); ++i){
        next_board = get_next_board(board,(*i));
        mini_board = beta_p(next_board,alpha, beta,_depth+1);
        v = mini_board.winner;
        if (alpha < v){
            alpha = v;
        }
        if (alpha >= beta)return next_board;
        if (v > mv){
            mv = v;
            best = next_board;
        }
    }
    return best;
}

board_t beta_p(board_t board, int alpha, int beta, int _depth){    
    ivec_t nexts = {0};
    int mv,v;
    board_t next_board = {}, maxi_board = {}, best = {};
    if (_depth == MAX_DEPTH || board.winner != 0 || board.full == true)
        return board;
    nexts = get_next_moves(board.state);
    if ((int)nexts.size() == 0){
        return board;
    }
    mv = 1.0;
    ivec_t::iterator i;
    for(i = nexts.begin(); i != nexts.end(); ++i){
        next_board = get_next_board(board,(*i));
        maxi_board = alpha_p(next_board,alpha, beta,_depth+1);
        v = maxi_board.winner;
        if (beta > v){
            beta = v;
        }
        if (alpha >= beta)return next_board;
        if (v < mv){
            mv = v;
            best = next_board;
        }
    }
    return best;
}

