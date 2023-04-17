/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : Cheung Lok Yiu
 * Student ID    : 1155175425
 * Class/Section : ENGG1110-D
 * Date          : 27/11/2021
 */

#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */

/* Macros used to represent the state of each square */
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2



/* Initialize the game board by setting all squares to EMPTY */
void initGameBoard(int gameBoard[6][7]) {
    int i,j;
    for (i=0;i<6;i++) {
        for (j=0;j<7;j++) {
            gameBoard[i][j] = EMPTY;
        }
    }

    // TODO : Complete this part

}



/* Display the game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[6][7]) {
    int i,j;
    for(i=0;i<6;i++) {
        for (j=0;j<7;j++) {
            printf("|");
            if (gameBoard[i][j] == EMPTY){
                printf(" ");
            }
            else if (gameBoard[i][j] == CROSS) {
                printf("X");

            }
            else printf("O");
        }
        printf("|");
        printf("\n");
    }
    printf(" 1 2 3 4 5 6 7");
    printf("\n");
    // TODO : Complete this part

}



/* Ask the human player to place the mark.
   You can assume that the user input must be an integer. */
void placeMarkByHumanPlayer(int gameBoard[6][7], int mark) {
    int col;
    int i;
    scanf("%d", &col);
    if (col < 1 || col > 7) {
        printf("Input out of range. Please input again: \n");
        placeMarkByHumanPlayer(gameBoard, mark);

    }

      else {for (i=5;i>=0;i--) {
            if (gameBoard[i][col-1] == EMPTY) {
                gameBoard[i][col-1] = mark;
                return;
            }

        }
         printf("Column is full. Please input again: \n");
        placeMarkByHumanPlayer(gameBoard, mark);}
        }




    // TODO : Complete this part






/* Return 1 if there is a winner in the game, otherwise return 0.
   Note: the winner is the current player indicated in main(). */
int hasWinner(int gameBoard[6][7]){
    int i,j;
    for (i=0;i<6;i++) {
        for (j=0;j<4;j++) {
            if (gameBoard[i][j] != EMPTY) {
                if (gameBoard[i][j]==gameBoard[i][j+1]&&gameBoard[i][j+1]==gameBoard[i][j+2]&&gameBoard[i][j+2]==gameBoard[i][j+3]) {
                    return 1;
                }

                }

            }


    }
    for (j=0;j<7;j++) {
        for (i=0;i<3;i++) {
                 // if (j == 2) printf("test %d", gameBoard[i][j]);
                 if(gameBoard[i][j] != EMPTY) {
                    if (gameBoard[i][j]==gameBoard[i+1][j]&&gameBoard[i+1][j]==gameBoard[i+2][j]&&gameBoard[i+2][j]==gameBoard[i+3][j]) {
                        // printf("Get in");
                        return 1;
                    }

                 //       break;
                }

    }
    }
    for (j=0;j<4;j++) {
        for (i=0;i<3;i++) {
                if (gameBoard[i][j] != EMPTY) {
                    if (gameBoard[i][j]==gameBoard[i+1][j+1]&&gameBoard[i+1][j+1]==gameBoard[i+2][j+2]&&gameBoard[i+2][j+2]==gameBoard[i+3][j+3]) {
                        return 1;
                    }


                    }

    }
}    // TODO : Complete this part
    for (i=5;i>=3;i--) {
        for (j=0;j<4;j++) {
                if (gameBoard[i][j] != EMPTY) {
                    if (gameBoard[i][j]==gameBoard[i-1][j+1]&&gameBoard[i-1][j+1]==gameBoard[i-2][j+2]&&gameBoard[i-2][j+2]==gameBoard[i-3][j+3]) {
                        return 1;
                    }


                    }

    }
}

return 0;


}

/* Return 1 if the game board is full, otherwise return 0. */
int isFull(int gameBoard[6][7]) {
    //return 0;
    int i,j;
    int k = 1;
    for (i=0;i<6;i++) {
        for (j=0;j<7;j++) {
            if (gameBoard[i][j] == EMPTY) {
                k = 0;
            }
        }
    }
 return k;
    // TODO : Complete this part

}





/* Determine the next move of the computer player.
   You are required to exactly follow the strategy mentioned in the project specification.
   Using other strategies will result in mark deduction. */

// TODO : Write the placeMarkByComputerPlayer(...) function here
void placeMarkByComputerPlayer(int gameBoard[6][7], int mark) {
    int col;
    int i;
    while (isFull(gameBoard)==0) {

        for (col=0;col<7;col++) {
            for (i=5;i>=0;i--) {
            if (gameBoard[i][col] == EMPTY) {
                gameBoard[i][col] = CROSS;

                break;
            }

            }
             if (hasWinner(gameBoard)==1) {

                    return ;
                }
                else {
                    gameBoard[i][col] = EMPTY;



                }
        }




for (col=0;col<7;col++) {
            for (i=5;i>=0;i--) {
            if (gameBoard[i][col] == EMPTY) {
                gameBoard[i][col] = CIRCLE;

                break;
            }
        }
          if (hasWinner(gameBoard)==1) {
                    gameBoard[i][col] = CROSS;

                    return ;
                }
                else {
                    gameBoard[i][col] = EMPTY;

                }

        }


        for (i=5;i>=0;i--) {
            for (col=6;col>=0;col--) {
                if(gameBoard[i][col]== EMPTY) {
                    gameBoard[i][col] = CROSS;

                    return;
                }

            }
        }



}
    }




/* The main function */
int main()
{
    /* Local variables */
    int gameBoard[6][7];    // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
    int currentPlayer;      // 1: Player 1             2: Player 2
    int gameContinue;       // 1: The game continues   0: The game ends
    int numOfHumanPlayers;  // 1 or 2

    /* Initialize the local variables */
    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameContinue = 1;
    printf("Enter the number of human players [1-2]:\n");
    scanf("%d", &numOfHumanPlayers);  // You can assume that the user input must be valid

    /* Uncomment the following statements to test whether the printGameBoard() and the placeMarkByHumanPlayer() functions
       are implemented correctly.
       You can add more if you wish.
       After testing, you can delete them or move them elsewhere. */
    printGameBoard(gameBoard);
    while (isFull(gameBoard)==0) {
    printf("Player 1's turn:\n");
    placeMarkByHumanPlayer(gameBoard, CIRCLE);
    printGameBoard(gameBoard);
    if (hasWinner(gameBoard)) {
        printf("Congratulations! Player 1 wins!");
        return 0;
    }

if (numOfHumanPlayers==2) {
     printf("Player 2's turn:\n");
    placeMarkByHumanPlayer(gameBoard, CROSS);
       printGameBoard(gameBoard);


     if (hasWinner(gameBoard)) {
        printf("Congratulations! Player 2 wins!");
        return 0;


    }

}

    else {
        printf("Computer's turn:\n");
        placeMarkByComputerPlayer(gameBoard, CROSS);
           printGameBoard(gameBoard);


     if (hasWinner(gameBoard)) {
        printf("Computer wins!");
        return 0;
     }

    }
    }

printf("Draw game.");



    /* Game start
       If there are two human players, they are Player 1 and Player 2
       If there is only one human player, he/she is Player 1 and another player is the computer player
       For both cases, Player 1 moves first and places the CIRCLE mark; while Player 2 (or the computer player) places the CROSS mark
       Hint: use a while loop */

    // TODO : Complete this part

        return 0;
        }

