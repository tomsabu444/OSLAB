#include <stdio.h>
struct process
{
    int id, at, bt, ct, tat, wt;
};
void main()
{
    struct process p[100];
    int n, i, j, t;
    float tot_tat = 0, avg_tat, tot_wt = 0, avg_wt;
    printf("enter no. of processes:\n");
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
        printf("enter details of process - id,arrival time,burst time :\n");
        scanf("%d%d%d", &p[i].id, &p[i].at, &p[i].bt);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                t = p[j].id;
                p[j].id = p[j + 1].id;
                p[j + 1].id = t;

                t = p[j].at;
                p[j].at = p[j + 1].at;
                p[j + 1].at = t;

                t = p[j].bt;
                p[j].bt = p[j + 1].bt;
                p[j + 1].bt = t;
            }
        }
    }
    p[0].ct = p[0].at + p[0].bt;
    for (i = 1; i <= n - 1; i++)
    {
        if (p[i].at <= p[i - 1].ct)
        {
            p[i].ct = p[i - 1].ct + p[i].bt;
        }
        else
        {
            p[i].ct = p[i].at + p[i].bt;
        }
    }
    for (i = 0; i <= n - 1; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        tot_tat = tot_tat + p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        tot_wt = tot_wt + p[i].wt;
    }
    avg_tat = tot_tat / n;
    avg_wt = tot_wt / n;
    printf("pid \t at \t bt \t ct \t tat \t wt\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d \t %d \t %d \t %d \t %d \t %d \t\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Average Turn Around Time=%f\nAverage Waiting Time=%f", avg_tat, avg_wt);
}
    #include <stdio.h>
struct process
{
    int id, at, bt, ct, tat, wt;
};
void main()
{
    struct process p[100];
    int n, i, j, t;
    float tot_tat = 0, avg_tat, tot_wt = 0, avg_wt;
    printf("enter no. of processes:\n");
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
        printf("enter details of process - id,arrival time,burst time :\n");
        scanf("%d%d%d", &p[i].id, &p[i].at, &p[i].bt);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                t = p[j].id;
                p[j].id = p[j + 1].id;
                p[j + 1].id = t;

                t = p[j].at;
                p[j].at = p[j + 1].at;
                p[j + 1].at = t;

                t = p[j].bt;
                p[j].bt = p[j + 1].bt;
                p[j + 1].bt = t;
            }
        }
    }
    p[0].ct = p[0].at + p[0].bt;
    for (i = 1; i <= n - 1; i++)
    {
        if (p[i].at <= p[i - 1].ct)
        {
            p[i].ct = p[i - 1].ct + p[i].bt;
        }
        else
        {
            p[i].ct = p[i].at + p[i].bt;
        }
    }
    for (i = 0; i <= n - 1; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        tot_tat = tot_tat + p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        tot_wt = tot_wt + p[i].wt;
    }
    avg_tat = tot_tat / n;
    avg_wt = tot_wt / n;
    printf("pid \t at \t bt \t ct \t tat \t wt\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d \t %d \t %d \t %d \t %d \t %d \t\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Average Turn Around Time=%f\nAverage Waiting Time=%f", avg_tat, avg_wt);
}
