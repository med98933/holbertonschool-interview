#include "sandpiles.h"
#include <stdlib.h>
#include <stdio.h>



/**
*check_grid - checks the elts of a grid for 3
*@sandpiles: grid to check it
*
* Return: 0 or 1
*/

int check_grid(int sandpiles[3][3])
{
int i, j;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (sandpiles[i][j] > 3)
return (0);
}
}
return (1);
}


/**
 * prin_t - print a grid
 * @sandpiles: sandpile
 *
 * Return: nothing
 */
void prin_t(int sandpiles[3][3])
{
int i, j;
printf("=\n");
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
printf("%d", sandpiles[i][j]);
if (j < 2)
printf(" ");
}
printf("\n");
}
}

/**
*stable - stablize the sum of two grid
*@sandpiles: grid1 to change
*@tmp: grid2 to compaire with it
*Return:void
*/
void stable(int sandpiles[3][3], int tmp[3][3])
{
int i, j;
for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
tmp[i][j] = sandpiles[i][j];

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{

if (tmp[i][j] >= 4)
{
sandpiles[i][j] = sandpiles[i][j] - 4;
if (i >= 1)
sandpiles[i - 1][j] += 1;
if (i <= 1)
sandpiles[i + 1][j] += 1;
if (j >= 1)
sandpiles[i][j - 1] += 1;
if (j <= 1)
sandpiles[i][j + 1] += 1;
}
}
}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 *
 * Return: nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
int tmp[3][3];
int i, j;
for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
grid1[i][j] += grid2[i][j];

while (!check_grid(grid1))
{
prin_t(grid1);
stable(grid1, tmp);
}
}
