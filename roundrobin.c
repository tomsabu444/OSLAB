#include <stdio.h>
struct process
{
    int id, at, bt, ct, tat, wt, status, rt, qstatus;
};
int q[100], front = -1, rear = -1;
void enqueue(int item)
{
    if ((front == -1) && (rear == -1))
    {
        front = 0;
        rear = 0;
        q[rear] = item;
    }
    else
    {
        rear++;
        q[rear] = item;
    }
}
int dequeue()
{
    int item;
    if (front == rear)
    {
        item = q[front];
        front = -1;
        rear = -1;
    }
    else
    {
        item = q[front];
        front++;
    }
    return (item);
}
void main()
{
    struct process p[100];
    float tot_tat = 0, avg_tat, tot_wt = 0, avg_wt;
    int i, j, n, completed = 0, current_time = 0, time;
    printf("Enter the number of process\n");
    scanf("%d", &n);
    printf("Enter the process details \n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("Enter the id \t arrival time\t burst time \n");
        scanf("%d%d%d", &p[i].id, &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].status = 0;
        p[i].qstatus = 0;
    }
    printf("Enter the time quantum\n");
    scanf("%d", &time);
    for (i = 0; i <= n - 1; i++)
    {
        current_time = p[0].at;
        enqueue(0);
        p[0].qstatus = 1;
        while (completed != n)
        {
            i = dequeue();
            if (p[i].rt == time)
            {
                current_time = current_time + time;
                p[i].ct = current_time;
                p[i].rt = 0;
                p[i].status = 1;
                completed++;
            }
            else if (p[i].rt < time)
            {
                current_time = current_time + p[i].rt;
                p[i].ct = current_time;
                p[i].rt = 0;
                p[i].status = 1;
                completed++;
            }
            else
            {
                current_time = current_time + time;
                p[i].rt = p[i].rt - time;
            }
            for (j = i + 1; j < n; j++)
            {
                if ((p[j].at <= current_time) && (p[j].status == 0) && (p[j].qstatus == 0))
                {
                    enqueue(j);
                    p[j].qstatus = 1;
                }
            }
            if (p[i].rt != 0)
            {
                enqueue(i);
            }
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
    printf("id \t at \t bt \t ct \t tat \t wt \n");
    for (i = 0; i <= n - 1; i++)
        printf("%d \t %d \t %d \t %d \t %d \t %d \n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    printf("Average tat= %f \n Average wt= %f ", avg_tat, avg_wt);
}
