#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
struct paper
{
    int number;
    char ans1[101];
    char ans2[101];
    char ans3[101];
};
int compare_paper(struct paper (*studen1), struct paper (*studen2))
{
    int len1 = strlen((*studen1).ans1), len2 = strlen((*studen2).ans1);
    int bok = 0;
    for(int i = 0;i < fmin(len1, len2);i++)
    {
        if ((*studen1).ans1[i] == (*studen2).ans1[i])
        {
            bok++;
        }
        if (bok >= fmin(len1, len2) * 0.9)
        {
            return 1;
        }
    }
    bok = 0;
    len1 = strlen((*studen1).ans2), len2 = strlen((*studen2).ans2);
    for(int i = 0;i < fmin(len1, len2);i++)
    {
        if ((*studen1).ans2[i] == (*studen2).ans2[i])
        {
            bok++;
        }
        if (bok >= fmin(len1, len2) * 0.9)
        {
            return 2;
        }
    }
    bok = 0;
    len1 = strlen((*studen1).ans3), len2 = strlen((*studen2).ans3);
    for(int i = 0;i < fmin(len1, len2);i++)
    {
        if ((*studen1).ans3[i] == (*studen2).ans3[i])
        {
            bok++;
        }
        if (bok >= fmin(len1, len2) * 0.9)
        {
            return 3;
        }
    }
    return 0;
}
int main()
{
    char tem;
    struct paper student[21];
    int t;
    scanf("%d", &t);
    scanf("%c", &tem);
    for(int i = 1;i <= t;i++)
    {
        scanf("%d%c%s%c%s%c%s%c", &student[i].number, &tem, student[i].ans1, &tem, student[i].ans2, &tem, student[i].ans3, &tem);
    }
    for(int i = 1;i < t;i++)
    {
        for(int j = i + 1;j <= t;j++)
        {
            if (j == i)
            {
                continue;
            }
            int number = compare_paper(&student[i], &student[j]);
            if (number != 0)
            {
                printf("%d %d %d\n", student[i].number, student[j].number, number);
            }
            
        }
    }
    return 0;
}