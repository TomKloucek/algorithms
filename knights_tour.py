from copy import deepcopy

# function finds where is starting position on board
def find_start(board):
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 0:
                return [j, i]

# main function which moves with knight - backtracking
def move_knight(board,move,position=[]):
    if position == []:
        position = find_start(board)
    counter = 0
    dimension = len(board)
    if move == (dimension*dimension):
        #print_board(board)
        return 1
    eligible = valid_positions(position,dimension)
    for y in range(5):
        for x in range(5):
            if move_valid(board,eligible,x,y):
                board[y][x] = move
                # if move is elligible go deeper in next move
                count = move_knight(board,move+1,[x,y])
                if count is not None: counter+=count
                board[y][x] = -1
    return counter

# return if move is valid
def move_valid(board,eligible,col,row): 
    if [col,row] in eligible and board[row][col] == -1:
        return True
    else:
        return False

# returns list of possible moves from actual position
def valid_positions(position,dimension):
    x_pos = position[0]
    y_pos = position[1]
    eligible = []
    moves = [-2,-1,1,2]
    for x in moves:
        for y in moves:
            if x_pos+x<dimension and x_pos+x>=0 and y_pos+y>=0 and y_pos+y<dimension and (abs(x)+abs(y))==3:
                eligible.append([x_pos+x,y_pos+y])
    return eligible

# solves all possible combinations and returns sum of all possible tours in n*n board
def solve(dimension):
    boards = make_boards(dimension)
    soucet = 0
    result_board = [['' for x in range(dimension)] for y in range(dimension)]
    for board in boards:
        [x,y] = find_start(board)
        vysledek = move_knight(board,1)
        result_board[y][x] = vysledek
        soucet += vysledek
    print_board(result_board)
    return soucet

# makes all possible starts for knight in n*n dimensional board
def make_boards(n):
    empty = -1
    board = [[empty for i in range(n)] for j in range(n)]
    boards = []
    for x in range(n):
        for y in range(n):
            board_ = deepcopy(board)
            board_[y][x] = 0
            boards.append(board_)
    return boards

# prints board in readable way
def print_board(board):
    n = len(board)
    print(n*'-----')
    for i in range(n):
        for j in range(n):
            if board[i][j] != -1:
                if board[i][j] < 10:
                    print_mov = ' '+str(board[i][j])
                    print(f' {print_mov} |',end='')
                else:
                    print(f' {board[i][j]} |',end='')
            else:
                print('    |',end='')
        print('\n'+n*'-----')

def main():
    print(solve(5))
    
if __name__ == "__main__":
    main()