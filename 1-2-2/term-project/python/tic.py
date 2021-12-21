import random

def show_tic_tac_toe_board(index):
    print("┌────┬────┬────┐")
    print("│ ¹{} │ ²{} │ ³{} │".format(index[0],index[1],index[2]))
    print("├────┼────┼────┤")
    print("│ ⁴{} │ ⁵{} │ ⁶{} │".format(index[3],index[4],index[5]))
    print("├────┼────┼────┤")
    print("│ ⁷{} │ ⁸{} │ ⁹{} │".format(index[6],index[7],index[8]))
    print("└────┴────┴────┘")


def checking_the_winner(index, size):
    if(((index[0] == 'O')and(index[0]==index[1])and(index[1]==index[2]))
    or((index[3] == 'O')and(index[3]==index[4])and(index[4]==index[5]))
    or((index[6] == 'O')and(index[6]==index[7])and(index[7]==index[8]))     #가로
    or((index[0] == 'O')and(index[0]==index[3])and(index[3]==index[6]))
    or((index[1] == 'O')and(index[1]==index[4])and(index[4]==index[7]))
    or((index[2] == 'O')and(index[2]==index[5])and(index[5]==index[8]))     #세로
    or((index[0] == 'O')and(index[0]==index[4])and(index[4]==index[8]))
    or((index[2] == 'O')and(index[2]==index[4])and(index[4]==index[6]))):   #대각선
        return 1
    
    if(((index[0] == 'X')and(index[0]==index[1])and(index[1]==index[2]))
    or((index[3] == 'X')and(index[3]==index[4])and(index[4]==index[5]))
    or((index[6] == 'X')and(index[6]==index[7])and(index[7]==index[8]))
    or((index[0] == 'X')and(index[0]==index[3])and(index[3]==index[6]))
    or((index[1] == 'X')and(index[1]==index[4])and(index[4]==index[7]))
    or((index[2] == 'X')and(index[2]==index[5])and(index[5]==index[8]))
    or((index[0] == 'X')and(index[0]==index[4])and(index[4]==index[8]))
    or((index[2] == 'X')and(index[2]==index[4])and(index[4]==index[6]))):
        return 2
    
    count = 0
    for i in range(9):
        if (index[i]!=' '):
            count+=1
        
    if (count == 9):
        return 3 # no one won yet
    return 0

def checking_duplicated(index, size, num):
    #num == my_turn[m]
    if (index[num]==' '):
        return 1
    return 0


def tic_tac_toe():
    
    index = [' ', ' ', ' ',
         ' ', ' ', ' ',
         ' ', ' ', ' ']
    
    my_turn = [0, 0, 0, 0, 0]
    the_opponent = [0, 0, 0, 0, 0]
    a = 'O'
    O = 'O' #my turn
    X = 'X' # the opponet's
    m = 0   # my turn
    n = 0   # the opponent's turn
    size = 9 # size of the board
    win = 0  # who's winning

    show_tic_tac_toe_board(index)
    start = int(input('1 is for starting first, 2 is for starting second\n'))
    if (start == 1 ):
        my_turn[m] = int(input('you\'re starting first! input a number 1-9 '))
        index[my_turn[m]-1] = 'O'
        show_tic_tac_toe_board(index)
        m += 1
    
    else :
        print("you're starting second!\n")
    
    while(1):
        while(1):
            the_opponent[n] = random.randint(1,9)
            if (index[the_opponent[n]-1]==' '):
                break
            
        index[the_opponent[n]] = 'X'
        print("The opponent : ", the_opponent[n]+1)
        show_tic_tac_toe_board(index)
        win = checking_the_winner(index, size)
        if (win != 0):
            show_tic_tac_toe_board(index)
            
            if(win==1):
                print("★★★★ You win! ★★★★")
            elif(win==2):
                print("You lose Try again!")
            elif(win==3):
                print("It's a tie! Try again")
            
            break
        
        n += 1
        while(1):
            my_turn[m] = int(input(('It\'s your turn!')))
            if (checking_duplicated(index, size, my_turn[m]-1) == 1):   # the index doesn't exist
                break
            print("input the number again\n")
        
        index[my_turn[m]-1] = 'O'
        win = checking_the_winner(index, size)
        if (win != 0):
            show_tic_tac_toe_board(index)
            if(win==1):
                print("★★★★ You win! ★★★★")
            elif(win==2):
                print("You lose Try again!")
            elif(win==3):
                print("It's a tie! Try again")
            break
    return 0

while(True):
    tic_tac_toe()
    playing_again = input('Do you want to play again?(Y/N)')
    if playing_again=='y' or playing_again=='Y':
        continue
    else:
        break