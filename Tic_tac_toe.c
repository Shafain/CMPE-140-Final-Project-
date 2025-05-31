#include <stdio.h>

#define MAX 100
#define MIN 5

int get_size()
{
    int n;
    do
    {
        printf("Enter the size of the matrix: ");
        scanf("%d", &n);
    } while (n < MIN || n > MAX);
    return n;
}

void print_matrix(int n, int arr[][n])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 'x')
                printf(" x ");
            else if (arr[i][j] == 'o')
                printf(" o ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

void player_x(int n, int arr[][n])
{
    int i, j;
    while (1)
    {
        printf("Player X - Enter row from 0 to %d: ", n - 1);
        scanf("%d", &i);
        printf("Player X - Enter column from 0 to %d: ", n - 1);
        scanf("%d", &j);

        if (i < 0 || i >= n || j < 0 || j >= n)
        {
            printf("Invalid coordinates! Try again.\n");
            continue;
        }
        if (arr[i][j] != 0)
        {
            printf("Already used! Try again.\n");
            continue;
        }

        arr[i][j] = 'x';
        break;
    }
}

void player_o(int n, int arr[][n])
{
    int i, j;
    while (1)
    {
        printf("Player O - Enter row from 0 to %d: ", n - 1);
        scanf("%d", &i);
        printf("Player O - Enter column from 0 to %d: ", n - 1);
        scanf("%d", &j);

        if (i < 0 || i >= n || j < 0 || j >= n)
        {
            printf("Invalid coordinates! Try again.\n");
            continue;
        }
        if (arr[i][j] != 0)
        {
            printf("Already used! Try again.\n");
            continue;
        }

        arr[i][j] = 'o';
        break;
    }
}
char check(int n, int arr[][n])
{
    // check rows
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 'x')
            {
                count++;
                if (count == 3)
                    return 'x';
            }
            else if (arr[i][j] == 'o')
            {
                count = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 'o')
            {
                count++;
                if (count == 3)
                    return 'o';
            }
            else if (arr[i][j] == 'x')
            {
                count = 0; // o-streak broken
            }
        }
    }

    // check columns
    for (int j = 0; j < n; j++)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] == 'x')
            {
                count++;
                if (count == 3)
                    return 'x';
            }
            else if (arr[i][j] == 'o')
            {
                count = 0;
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] == 'o')
            {
                count++;
                if (count == 3)
                    return 'o';
            }
            else if (arr[i][j] == 'x')
            {
                count = 0;
            }
        }
    }

    // main diagonal
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][i] == 'x')
        {
            count++;
            if (count == 3)
                return 'x';
        }
        else if (arr[i][i] == 'o')
        {
            count = 0;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][i] == 'o')
        {
            count++;
            if (count == 3)
                return 'o';
        }
        else if (arr[i][i] == 'x')
        {
            count = 0;
        }
    }

    // sub-diagonal
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][n - 1 - i] == 'x')
        {
            count++;
            if (count == 3)
                return 'x';
        }
        else if (arr[i][n - 1 - i] == 'o')
        {
            count = 0;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][n - 1 - i] == 'o')
        {
            count++;
            if (count == 3)
                return 'o';
        }
        else if (arr[i][n - 1 - i] == 'x')
        {
            count = 0;
        }
    }

    return 0; // No winner
}

int main()
{
    int n = get_size();
    int arr[n][n];

    // Initialize matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;

    char winner = 0;
    for (int count = 1; count <= 10; count++)
    {
        print_matrix(n, arr);
        player_x(n, arr);
        winner = check(n, arr);
        print_matrix(n, arr);
        if (winner != 0)
            break;
        player_o(n, arr);

        winner = check(n, arr);
        if (winner != 0)
            break;
    }

    if (winner == 'x')
        printf("\n Player X wins!\n");
    else if (winner == 'o')
        printf("\n Player O wins!\n");
    else
        printf("\n No one wins.\n");

    return 0;
}
