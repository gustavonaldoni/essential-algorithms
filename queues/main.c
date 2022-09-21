#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

main()
{
    int userNumber = 0;
    Queue queue;

    QueueCreate(&queue);

    while(userNumber != 666)
    {
        printf("Write a number: \n");
        scanf("%d", &userNumber);

        if (userNumber != 666)
            QueueInsert(&queue, userNumber);

        if (userNumber == 1000)
            QueueRemove(&queue);
        
    }

    printf("========================\n");
    QueueShow(queue);
}