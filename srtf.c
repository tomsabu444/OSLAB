#include <stdio.h>
struct process
{
    int id, at, bt, ct, tat, wt, rt, status;
};
void main()
{
    struct process p[100], temp;
    int n, i, j, completed = 0, current_time = 0, index, min_bt;
    float tot_tat = 0, avg_tat, tot_wt = 0, avg_wt;
    printf("Enter the no. of processes : ");
    scanf("%d", &n);
    printf("Enter the process Details : \n");
    for (i = 0; i < n; i++)
    {
        printf("Enter the %dth Process ID, Arrival Time, Burst Time : ", i + 1);
        scanf("%d%d%d", &p[i].id, &p[i].at, &p[i].bt);
        p[i].status = 0;
        p[i].rt = p[i].bt;
    }
    while (completed != n)
    {
        min_bt = 32765;
        index = -1;
        for (i = 0; i < n; i++)
        {
            if (p[i].at <= current_time && p[i].status == 0)
            {
                if (p[i].rt <= min_bt)
                {
                    if (p[i].rt == min_bt)
                    {
                        if (p[i].at <= p[index].at)
                        {
                            min_bt = p[i].rt;
                            index = i;
                        }
                        else
                        {
                            min_bt = p[index].rt;
                        }
                    }
                    else
                    {
                        min_bt = p[i].rt;
                        index = i;
                    }
                }
            }
        }
        if (index == -1)
            current_time++;
        else
        {
            current_time++;
            p[index].rt--;
            if (p[index].rt == 0)
            {
                p[index].ct = current_time;
                p[index].status = 1;
                completed++;
            }
        }
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        tot_wt = tot_wt + p[i].wt;
        tot_tat = tot_tat + p[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    avg_wt = tot_wt / n;
    avg_tat = tot_tat / n;
    printf("Average TAT : %f\n", avg_tat);
    printf("Average WT : %f\n", avg_wt);
}
