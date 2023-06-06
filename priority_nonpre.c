#include <stdio.h>
struct process
{
    int id, at, bt, pr, ct, tat, wt, status;
};
void main()
{
    struct process p[100], temp;
    int n, i, j, completed = 0, current_time = 0, index, max_pr;
    float tot_tat = 0, avg_tat, tot_wt = 0, avg_wt;
    printf("Enter the no. of processes : ");
    scanf("%d", &n);
    printf("Enter the process Details : \n");
    for (i = 0; i < n; i++)
    {
        printf("Enter the %dth Process ID, Arrival Time, Burst Time, Priority: ", i + 1);
        scanf("%d%d%d%d", &p[i].id, &p[i].at, &p[i].bt, &p[i].pr);
        p[i].status = 0;
    }
    while (completed != n)
    {
        max_pr = 32765;
        index = -1;
        for (i = 0; i < n; i++)
        {
            if (p[i].at <= current_time && p[i].status == 0)
            {
                if (p[i].pr < max_pr)
                {
                    max_pr = p[i].pr;
                    index = i;
                }
            }
        }
        if (index == -1)
            current_time++;
        else
        {
            current_time += p[index].bt;
            p[index].ct = current_time;
            p[index].status = 1;
            completed++;
        }
    }
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        tot_wt = tot_wt + p[i].wt;
        tot_tat = avg_tat + p[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].pr, p[i].ct, p[i].tat, p[i].wt);
    }
    avg_wt = tot_wt / n;
    avg_tat = tot_tat / n;
    printf("Average TAT : %f\n", avg_tat);
    printf("Average WT : %f\n", avg_wt);
}
