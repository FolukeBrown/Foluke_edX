#include <stdio.h>
/**
 *  program should first read an integer indicating the number of members per team
 * program should read the player weights (integers representing kilograms) alternating by team
 * Return: ALways 0 (Success)
*/
int main (void)
{
    int teamMember;
    int weight;
    int totalTeamWeight1 = 0;
    int totalTeamWeight2 = 0;
    int i;
    printf("How many players are there in each team?\n");
    scanf("%d", &teamMember);

    for(i=0; i < (2*teamMember); ++i)
    {
        scanf("%d", &weight);
        if(i % 2 == 0){
        totalTeamWeight1 += weight;
        } 
        else
        {
        totalTeamWeight2 += weight;
        }
    }
    if(totalTeamWeight1 > totalTeamWeight2)
    {
        printf("Team 1 has an advantage\n");
    }
    else
    {
        printf("Team 2 has an advantage\n");  
    }
    printf("Total weight for team 1: %d\n", totalTeamWeight1);
    printf("Total weight for team 2: %d\n", totalTeamWeight2);
    return (0);
}