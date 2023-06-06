#include <stdio.h>
struct process
{
    int id, at, bt, ct, tat, wt, status;
};
void main()
{
    struct process p[100];
    float tot_tat = 0, avg_tat, tot_wt = 0, avg_wt;
    int current_time = 0, min_bt, completed = 0, index, n, i;
    printf("enter the no of process\n");
    scanf("%d", &n);
    printf("enter the process details\n");
    for (i = 0; i < n; i++)
    {
        printf("enter the id,at,bt");
        scanf("%d%d%d", &p[i].id, &p[i].at, &p[i].bt);
        p[i].status = 0;
    }
    while (completed != n)
    {
        min_bt = 32765;
        index = -1;
        for (i = 0; i < n; i++)
        {
            if ((p[i].at <= current_time) && (p[i].status == 0))
            {
                if (min_bt > p[i].bt)
                {
                    min_bt = p[i].bt;
                    index = i;
                }
            }
        }
        if (index == -1)
        {
            current_time++;
        }
        else
        {
            p[index].ct = current_time + p[index].bt;
            current_time = current_time + p[index].bt;
            p[index].status = 1;
            completed++;
        }
    }
    for (i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        tot_tat = tot_tat + p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        tot_wt = tot_wt + p[i].wt;
    }
    avg_tat = tot_tat / n;
    avg_wt = tot_wt / n;
    printf("pid \t at\t bt \t ct \t tat \t wt \n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\naverage turn around time=%f\naverage waiting time=%f\n", avg_tat, avg_wt);
}
#include <stdio.h>
struct process
{
    int id, at, bt, ct, tat, wt, status;
};
void main()
{
    struct process p[100];
    float tot_tat = 0, avg_tat, tot_wt = 0, avg_wt;
    int current_time = 0, min_bt, completed = 0, index, n, i;
    printf("enter the no of process\n");
    scanf("%d", &n);
    printf("enter the process details\n");
    for (i = 0; i < n; i++)
    {
        printf("enter the id,at,bt");
        scanf("%d%d%d", &p[i].id, &p[i].at, &p[i].bt);
        p[i].status = 0;
    }
    while (completed != n)
    {
        min_bt = 32765;
        index = -1;
        for (i = 0; i < n; i++)
        {
            if ((p[i].at <= current_time) && (p[i].status == 0))
            {
                if (min_bt > p[i].bt)
                {
                    min_bt = p[i].bt;
                    index = i;
                }
            }
        }
        if (index == -1)
        {
            current_time++;
        }
        else
        {
            p[index].ct = current_time + p[index].bt;
            current_time = current_time + p[index].bt;
            p[index].status = 1;
            completed++;
        }
    }
    for (i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        tot_tat = tot_tat + p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        tot_wt = tot_wt + p[i].wt;
    }
    avg_tat = tot_tat / n;
    avg_wt = tot_wt / n;
    printf("pid \t at\t bt \t ct \t tat \t wt \n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\naverage turn around time=%f\naverage waiting time=%f\n", avg_tat, avg_wt);
}
