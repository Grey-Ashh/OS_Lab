#include <stdio.h>

void implimentWorstFit(int blockSize[], int blocks, int processSize[], int processes)
{
	int allocation[processes];
	int occupied[blocks];
	int frag[processes];
	for(int i = 0; i < processes; i++)
	{
		allocation[i] = -1;
	}   
	for(int i = 0; i < blocks; i++)
	{
		occupied[i] = 0;
	}
	for (int i=0; i < processes; i++)
	{
		int indexPlaced = -1;
		for(int j = 0; j < blocks; j++)
		{
			if(blockSize[j] >= processSize[i] && !occupied[j])
			{
				if (indexPlaced == -1)
					indexPlaced = j;
				else if (blockSize[indexPlaced] < blockSize[j])
					indexPlaced = j;
			}
			frag[i]=blockSize[indexPlaced]-processSize[i];
		}
		if (indexPlaced != -1)
		{
			allocation[i] = indexPlaced;
			occupied[indexPlaced] = 1;
			blockSize[indexPlaced] -= processSize[i];
		}

	}
	printf("\nProcess No.\tProcess Size\tBlock no.\t\t\tFragment\n");
	for (int i = 0; i < processes; i++)
	{
		printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
		if (allocation[i] != -1)
			printf("%d\t\t\t%d\n",allocation[i] + 1,frag[i]);
		else
			printf("Not Allocated\tNot Allocated\n");
	}
}

int main()
{
	int bno,pno,i;
        printf("Enter no. of blocks: ");
        scanf("%d",&bno);
        printf("\nEnter no. of processes: ");
        scanf("%d",&pno);
        int bsize[bno],psize[pno];
        printf("\nEnter size of each block: ");
        for(i=0;i<bno;i++)
                scanf("%d",&bsize[i]);
        printf("Enter size of each process: ");
        for(i=0;i<pno;i++)
                scanf("%d",&psize[i]);
	implimentWorstFit(bsize, bno, psize, pno);
	return 0;
}
