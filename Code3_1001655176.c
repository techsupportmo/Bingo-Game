//Mohammed Ahmed 1001655176
//This program includes the bonus that checks for the diagonal bingo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototypes
void FillBingoCard(int bingoCard[5][5]);
void PrintBingoCard(int bingoCard[5][5]);
int rowFilled(int bingoCard[5][5]);
int colFilled(int bingoCard[5][5]);
int outputNumber(int nextNumber);
int pickNumbers(int usedNumbers[75]);
int checkArray(int bingoCard[][5], int nextNumber);

void FillBingoCard(int bingoCard[5][5])
{
    
   
    int num;
    
    srand(time(NULL));
    
    
    int i;
    for(i = 0; i < 5; i++)
    {

        
        int j;
        for(j = 0; j < 5; j++)
        {
            num = (rand() % 15 + 1) + (j * 15);
            
            //checks if number repeats on the bingo card
            while(num == bingoCard[0][j] ||num == bingoCard[1][j] ||num == bingoCard[2][j] ||num == bingoCard[3][j] ||num == bingoCard[4][j])
            {
                num = (rand() % 15 + 1) + (j * 15);
            }
            
            bingoCard[i][j] = num;
        }
        
    }
    
    bingoCard[2][2] = 0;
    
}

void PrintBingoCard(int bingoCard[5][5])
{
     
    char mark = 'X';
    //print BINGO title
    printf("\n     B      I        N      G       O \n");
    
    //print line
    int i;
    for(i = 0; i < 41; i++)
    {
        printf("-");
    }
    printf("\n");
    
    for(i = 0; i < 5; i++)
    {
        printf("|");
        
        
        int j;
        for (j = 0; j < 5; j++)
        {
            if(bingoCard[i][j] == 0)
            {
                
                printf("%5c  |",mark);
                
            }
            else
            {
                printf("%5d  |",bingoCard[i][j]);
            }
            
        }

        printf("\n");
        //print line
        int i;
        for(i = 0; i < 41; i++)
        {
            printf("-");
        }
        printf("\n");
        
    }
    
}

int rowFilled(int bingoCard[5][5])
{
    int count = 0;
    int bingo = 0;
    
    //checks each row
    int i;
    for(i = 0; i < 5; i++)
    {
        
        //checks each value in row
        int j;
        for(j = 0; j < 5; j++)
        {
           
            //checks if value is marked
            if(bingoCard[i][j] == 0)
            {
              
                count++;
                
            }
            
            //check if all the values in the row are marked
            if(count == 5)
            {
                bingo = 1;
            }
            
            
        }
        
        count = 0;
        
    }
    
    return bingo;
}

int colFilled(int bingoCard[5][5])
{
    
    int count = 0;
    int bingo = 0;
    
    //checks each column
    int i;
    for(i = 0; i < 5; i++)
    {
        //checks each value in column
        int j;
        for(j = 0; j < 5; j++)
        {
            
            //checks if value in column is marked
            if(bingoCard[j][i] == 0)
            {
                count++;
            }
            
            //check if all the values in the row are marked
            if(count == 5)
            {
                bingo = 1;
            }
            
            
        }
        
        count = 0;
        
        
        
    }
    
    
    return bingo;
}

int diagonal (int bingoCard[5][5])
{
    int check = 0;
    
    
    if(bingoCard[0][0] == 0 &&bingoCard[1][1] == 0 && bingoCard[2][2] == 0 &&bingoCard[3][3] == 0 &&bingoCard[4][4] == 0)
    {
        check = 1;
    }
    
    if(bingoCard[0][4] == 0 &&bingoCard[1][3] == 0 && bingoCard[2][2] == 0 && bingoCard[3][1] == 0 &&bingoCard[4][0] == 0)
    {
        check = 1;
    }
    
    return check;
    
}



int outputNumber(int nextNumber)
{
    //outputs the next number
    if(nextNumber <= 15 && nextNumber >= 1)
    {
       printf("\nThe next number is B%d\n", nextNumber);
    }
    
    if(nextNumber <= 30 && nextNumber > 15)
    {
       printf("\nThe next number is : I%d\n", nextNumber);
    }
    
    if(nextNumber <= 45 && nextNumber > 30)
    {
       printf("\nThe next number is : N%d\n", nextNumber);
    }
    
    if(nextNumber <= 60 && nextNumber > 45)
    {
       printf("\nThe next number is : G%d\n", nextNumber);
    }
    
    if(nextNumber <= 75 && nextNumber > 60)
    {
       printf("\nThe next number is : O%d\n", nextNumber);
    }
    
    return nextNumber;
}

int pickNumbers(int usedNumbers[75])
{
    //creates next number

    
    int nextNumber = rand() % 75 + 1;
    
    if(usedNumbers[nextNumber-1] == 0)
    {
        usedNumbers[nextNumber-1] = 1;
        
        
    }
    else
    {
        while(usedNumbers[nextNumber-1] == 1)
        {
           nextNumber = rand() % 75 + 1;
        }
        usedNumbers[nextNumber-1] = 1;
    }
    
    
    
    
    return nextNumber;
    
    
    
    
}

int checkArray(int bingoCard[][5], int nextNumber)
{
    int check = 0;
    
    //checks rows
    int i;
    for(i = 0; i < 5; i++)
    {
        //checks each value in the row
        int j;
        for(j = 0; j < 5; j++)
        {
           
            //marking value if it finds it on the bingo card
            if(bingoCard[i][j] == nextNumber)
            {
                bingoCard[i][j] = 0;
                check = 1;
            }
            
        }
    }
    
    //returns 1 if it found value or else it returns 0
    return check;
    
}

int main(void)
{
    
    int bingoCard[5][5];
    int usedNumbers[75] = {};
    char choice;
    int number;
    int win = 0;
    int count = 0;
    
    

    
    
    FillBingoCard(bingoCard);
    PrintBingoCard(bingoCard);
    
    number = outputNumber(pickNumbers(usedNumbers));
    //usedNumbers[count] = number;
    count++;
    printf("Do you have it (Y/N): ");
    scanf("%s", &choice );
    
    
    if(choice == 'Y')
    {
        //checks for cheating on the first try
        if(!checkArray(bingoCard, number))
        {
            
            
           printf("\nThat value is not on your BINGO card - are you trying to cheat??\n");
            
            
        }
        
        
    }
    
    
    while(count < 75 && win == 0)
    {
        //prints card again
        PrintBingoCard(bingoCard);
        number = outputNumber(pickNumbers(usedNumbers));
        
        count++;
        printf("\nDo you have it (Y/N): ");
        scanf("%s", &choice );
        
        if(choice == 'Y')
        {
            if(checkArray(bingoCard, number))
            {
                

                
                win = colFilled(bingoCard);
                
                //if you didn't fill your column then it checks if you filled a row
                if(win != 1)
                {
                   win = rowFilled(bingoCard);
                }
                
                
                if(rowFilled(bingoCard))
                {
                    
                    //checks if row AND column both filled at same time or else you just filled a row
                    if(colFilled(bingoCard))
                    {
                        PrintBingoCard(bingoCard);
                        printf("\nYou filled out a row and a column - BINGO!!!");
                    }
                    else //outputs if you just filled a row
                    {
                        PrintBingoCard(bingoCard);
                        printf("\nYou filled out a row - BINGO!!!!\n\n\n");
                    }
                    
                    
                }
                
                //outputs if you filled just a column
                if(colFilled(bingoCard))
                {
                    PrintBingoCard(bingoCard);
                    printf("\nYou filled out a column - BINGO!!!!\n\n\n");
                }
                
                //checks diagonal
                if(diagonal(bingoCard))
                {
                    PrintBingoCard(bingoCard);
                    printf("\nYou filled out a diagonal - BINGO!!!\n\n");
                    win = diagonal(bingoCard);
                }
                
            }
            else
            {
                printf("\nThat value is not on your BINGO card - are you trying to cheat??\n");
            }
            
            
        }
    }
    

    
    return 0;
}
