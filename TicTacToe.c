#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char player1[80], player2[80];
char choice;
char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int flag = 1;

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}
void board()
{
    printf("\n\nTic Tac Toe\n\n");

    printf("\n%s (X) - %s (O)\n\n\n", player1, player2);

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("     |     |     \n\n");
}
void naming()
{
    printf("Enter name of Player 1:\n");
    scanf(" %[^\n]%*c", player1);
    printf("Enter name of Player 2:\n");
    scanf(" %[^\n]%*c", player2);
}

int menu()
{
    printf("\n===================================");
    printf("\n\tTic-Tac-Toe Menu");
    printf("\n===================================\n");
    printf("\nEnter '1' for Instructions\nEnter '2' to start game\nEnter '3' to exit \n\n");
    return 0;
}
int main()
{
start:
    choice = '1';
    while (choice != '3')
    {
        menu();
        scanf(" %c", &choice);
        switch (choice)
        {
        case '1':
            printf("\nInstructions\nEnter slot position to mark your symbol ('O' or 'X')\n");
            break;
        case '2':
            naming();
            while (flag == 1)
            {
                int player = 1, i, choice;
                char mark;
                while (1)
                {
                    board();
                    player = (player % 2) ? 1 : 2;
                    if (player % 2 == 0)
                        printf("%s enter a number: ", player2);
                    else
                        printf("%s enter a number: ", player1);
                    scanf("%d", &choice);
                    mark = (player == 1) ? 'X' : 'O';
                    if (choice == 1 && square[1] == '1')
                        square[1] = mark;
                    else if (choice == 2 && square[2] == '2')
                        square[2] = mark;
                    else if (choice == 3 && square[3] == '3')
                        square[3] = mark;
                    else if (choice == 4 && square[4] == '4')
                        square[4] = mark;
                    else if (choice == 5 && square[5] == '5')
                        square[5] = mark;
                    else if (choice == 6 && square[6] == '6')
                        square[6] = mark;
                    else if (choice == 7 && square[7] == '7')
                        square[7] = mark;
                    else if (choice == 8 && square[8] == '8')
                        square[8] = mark;
                    else if (choice == 9 && square[9] == '9')
                        square[9] = mark;
                    else
                    {
                        printf("Invalid move ");
                        player--;
                    }
                    i = checkwin();
                    player++;
                    if (i == 1)
                    {
                        board();
                        {
                            if (player % 2 == 0)
                                printf("==> %s won ", player1);
                            else
                                printf("==> %s won ", player2);
                        }
                        break;
                    }
                    else if (i == 0)
                    {
                        board();
                        printf("==>Game draw");
                        break;
                    }
                }
                char ch;
            here:
                printf("\nDo you wanna play again (Y/N) : ");
                scanf(" %c", &ch);
                if (ch == 'N' || ch == 'n')
                {
                    goto start;
                }
                else if (ch != 'Y' && ch != 'y')
                {
                    printf("Enter a valid choice!!");
                    goto here;
                }
                else
                {
                    for (int i = 1; i <= 9; i++)
                        square[i] = i + 48;
                }
            }
        case '3':
            exit(0);
        default:
            printf("\n~Invalid Choice~");
        }
    }
    return 0;
}
