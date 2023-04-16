#include <stdio.h>

void runTimeSort(int start, int end);
void arriveTimeSort(int head, int tail);
void merge(int head, int mid, int tail);

int id[1000];
int arriveTime[1000];
int runningTime[1000];
int idIndex[1000];
int waiting[1000];
int result[1000];

int main()
{
    int i;
    int index, temp, end;
    int timeNow, newArrive;
    int processNow, nextIndex;
    int resultIndex;

    index = 1;
    while(scanf("%d", &temp) != EOF)
    {
        id[index] = temp;

        scanf("%d", &temp);
        arriveTime[index] = temp;

        scanf("%d", &temp);
        runningTime[index] = temp;

        idIndex[index] = index;

        index++;
    }

    arriveTimeSort(1, index-1);

    end = index;
    index = 1;
    timeNow = 0;
    newArrive = 0;
    processNow = 0;
    nextIndex = 1;
    resultIndex = 0;

/*printf("\n");
for(i=1; i<end; i++)
{
    printf("%d %d %d\n", id[i], arriveTime[i], runningTime[i]);
}
printf("\n\n");*/

    while(1)
    {
//printf("\n\ttimeNow: %d\n", timeNow);

        if(index==end && newArrive==0)
        {
            for(i=nextIndex; i<end; i++)
            {
                temp = waiting[i];
                result[resultIndex] = id[temp];
                resultIndex++;
            }

            break;
        }

        if(arriveTime[index] == timeNow)
        {
            waiting[index] = idIndex[index];

            index++;

            newArrive = 1;

            runTimeSort(nextIndex, index-1);

/*printf("\t");
for(i=nextIndex; i<index; i++)
{
    printf("%d, ", waiting[i]);
}
printf("\n");*/

            continue;
        }

        if(newArrive == 1)
        {
            temp = waiting[nextIndex];

            if(processNow == 0)
            {
                processNow = temp;
                nextIndex++;

                result[resultIndex] = id[processNow];
                resultIndex++;
                //printf("%d\n", id[processNow]);

//printf("\t\tprocessNow: %d\n", processNow);
            }else
            {
                if(runningTime[temp] < runningTime[processNow])
                {
                    waiting[nextIndex] = processNow;
                    processNow = temp;

                    result[resultIndex] = id[processNow];
                    resultIndex++;
                    //printf("%d\n", id[processNow]);

//printf("\t\tprocessNow: %d\n", processNow);
                }
            }
        }

        if(processNow == 0)
        {
            timeNow++;
            continue;
        }

        if(runningTime[processNow] > 0)
        {
            runningTime[processNow]--;
        }else if(nextIndex < index)
        {
            processNow = waiting[nextIndex];
            runningTime[processNow]--;
            nextIndex++;

            result[resultIndex] = id[processNow];
            resultIndex++;
            //printf("%d\n", id[processNow]);

//printf("\t\tprocessNow: %d\n", processNow);
        }

        newArrive = 0;
        timeNow++;
    }

    for(i=0; i<resultIndex; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}

void runTimeSort(int start, int end)
{
    int i, one, two, temp;

    two = waiting[end];

    for(i=end-1; i>=start; i--)
    {
        one = waiting[i];

        if(runningTime[one] > runningTime[two])
        {
            temp = waiting[i];
            waiting[i] = waiting[i+1];
            waiting[i+1] = temp;
        }else
        {
            return;
        }
    }
}

void arriveTimeSort(int head, int tail)
{
    int mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        arriveTimeSort(head, mid);
        arriveTimeSort(mid+1, tail);
        merge(head, mid, tail);
    }
}

int leftSubId[500];
int leftSubArriveTime[500];
int leftSubRunningTime[500];
int leftSubIdIndex[500];
int rightSubId[500];
int rightSubArriveTime[500];
int rightSubRunningTime[500];
int rightSubIdIndex[500];

void merge(int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;

    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSubId[leftIndex] = id[head + leftIndex];
        leftSubArriveTime[leftIndex] = arriveTime[head + leftIndex];
        leftSubRunningTime[leftIndex] = runningTime[head + leftIndex];
        leftSubIdIndex[leftIndex] = idIndex[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSubId[rightIndex] = id[mid + 1 + rightIndex];
        rightSubArriveTime[rightIndex] = arriveTime[mid + 1 + rightIndex];
        rightSubRunningTime[rightIndex] = runningTime[mid + 1 + rightIndex];
        rightSubIdIndex[rightIndex] = idIndex[mid + 1 + rightIndex];
    }

    leftSubArriveTime[lenA] = 2147483647;
    rightSubArriveTime[lenB] = 2147483647;

    leftIndex = 0;
    rightIndex = 0;

    int writePointer=0;
    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if (leftSubArriveTime[leftIndex] <= rightSubArriveTime[rightIndex])
        {
            id[writePointer] = leftSubId[leftIndex];
            arriveTime[writePointer] = leftSubArriveTime[leftIndex];
            runningTime[writePointer] = leftSubRunningTime[leftIndex];
            leftSubIdIndex[writePointer] = leftSubArriveTime[leftIndex++];
        }else
        {
            id[writePointer] = rightSubId[rightIndex];
            arriveTime[writePointer] = rightSubArriveTime[rightIndex];
            runningTime[writePointer] = rightSubRunningTime[rightIndex];
            rightSubIdIndex[writePointer] = rightSubArriveTime[rightIndex++];
        }
    }
}
