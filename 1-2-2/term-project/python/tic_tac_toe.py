board = ['-', '-', '-',
         '-', '-', '-',
         '-', '-', '-']

gameplay = [1, 0, 1, 0, 1, 0, 1, 0, 1]

def print_board():
    print(board[0] + '|' + board[1] + '|' + board[2])
    print(board[3] + '|' + board[4] + '|' + board[5])
    print(board[6] + '|' + board[7] + '|' + board[8])
    
def playagain():
    checking_play_again = input('Do you want to play again? (Y/N)?')
    if checking_play_again == 'y' or checking_play_again == 'Y':
        return True
    else:
        return False
    #else:
    #   go back to main menu   

def win_check():
    if board[0] is board[1] is board[2] == 'X':
        print('\'X\' win')
        return True
    elif board[3] is board[4] is board[5] == 'X':
        print('\'X\' win')
        return True
    elif board[6] is board[7] is board[8] == 'X':
        print('\'X\' win')
        return True
    elif board[0] is board[3] is board[6] == 'X':
        print('\'X\' win')
        return True
    elif board[1] is board[4] is board[7] == 'X':
        print('\'X\' win')
        return True
    elif board[2] is board[5] is board[8] == 'X':
        print('\'X\' win')
        return True
    elif board[0] is board[4] is board[8] == 'X':
        print('\'X\' win')
        return True
    elif board[2] is board[4] is board[6] == 'X':
        print('\'X\' win')
        return True
        
    if board[0] is board[1] is board[2] == 'O':
        print('\'O\' win')
        return True
    elif board[3] is board[4] is board[5] == 'O':
        print('\'O\' win')
        return True
    elif board[6] is board[7] is board[8] == 'O':
        print('\'O\' win')
        return True
    elif board[0] is board[3] is board[6] == 'O':
        print('\'O\' win')
        return True
    elif board[1] is board[4] is board[7] == 'O':
        print('\'O\' win')
        return True
    elif board[2] is board[5] is board[8] == 'O':
        print('\'O\' win')
        return True
    elif board[0] is board[4] is board[8] == 'O':
        print('\'O\' win')
        return True
    elif board[2] is board[4] is board[6] == 'O':
        print('\'O\' win')
        return True
    
def play_game(val):
    if gameplay[0] == 1:
        board[val] = 'X'
        gameplay.pop(0)
        res = win_check()
        if res is True:
            return True
        else:
            print_board()
            inval()
    else:
        board[val] = 'O'
        gameplay.pop(0)
        res = win_check()
        if res is True:
            return True
        else:
            print_board()
            inval()


def inval():
    val = int(input('Choose the values from 0 to 8'))
    try:
        if val<=8 and val>=0:
            res = play_game(val)
            if res is True:
                checks_play_again = playagain()
                if checks_play_again == True:
                    return True
                else:
                    return False

                    
        else:
            print('Enter Valid Input')
            inval()

    except TypeError:
        print('Enter Valid Input')
        inval()

def main():
    board = ['-', '-', '-',
         '-', '-', '-',
         '-', '-', '-']

    gameplay = [1, 0, 1, 0, 1, 0, 1, 0, 1]
    print('Welcome to tic Tac Toe game!')
    print_board()
    inval()
while(1):
    main()
    plays_again = inval()
    if plays_again==False:
        break  

