#include<stdio.h>
int brust_time[20], process[20],arrival_time[20], priority[20];
int waiting_time(int i){
 
            int k= 0;
            for(int j = 0; j < i; j++)
            {
                  k = k + brust_time[j];
            }
        return k;    
     
}
int max_array(int arr[],int size){
	int max=arr[0];
	int j=0;
	for(int i=1; i<size; i++)
    	{
        	if(arr[i] > max)
        	{
            		max = arr[i];
	    		j=i;
        	}
    	}
	
	return j;
	

}
 
int main()
{
      
      int i, j, limit, sum = 0, position, temp;
      float average_wait_time, average_turnaround_time;
      printf("Enter Total Number of Processes:\t");
      scanf("%d", &limit);
      printf("\nEnter Burst Time, Priority and Arival time For %d Processes\n", limit);
      for(int i = 0; i < limit; i++)
      {
            printf("\nProcess[%d]\n", i);
            printf("Process Burst Time:\t");
            scanf("%d", &brust_time[i]);
	    printf("Process Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            process[i] = i;
      }
	printf("Process        Brust time             Arrival Time");
	for(int i=0;i<limit;i++){
		printf("\n%d              %d              %d\n",process[i],brust_time[i],arrival_time[i]);
	}
	

     for(int i=0;i<limit;i++){
        for(int j=i+1;j<limit;j++){
            if(arrival_time[i]>arrival_time[j]){
                            temp=arrival_time[i];
                            arrival_time[i]=arrival_time[j];
                            arrival_time[j]=temp;

                            temp=brust_time[i];
                            brust_time[i]=brust_time[j];
                            brust_time[j]=temp;

                            temp=process[i];
                            process[i]=process[j];
                            process[j]=temp;
            }
        }
     }
  


  
  int t=0;
  printf("Process        Brust time           Time");

    for(int i=0;i<limit;i++){
		int k[10];
		for(int i=0;i<10;i++)
			k[i]=0;
		
		
		
		
    		if(i==0){
			t=t+brust_time[i];
          		printf("\n%d              %d                %d\n",process[i],brust_time[i],t);
			
		
   		 }
   		 else{
			for(int j=i;j<limit;j++){
				if(arrival_time[j]<t){
					int u=waiting_time(i);
					k[j]=1+((u-arrival_time[j])/brust_time[j]);
	
				}

			}
			int m=max_array(k,10);
			if(m!=i){
				temp=arrival_time[i];
                                arrival_time[i]=arrival_time[m];
                                arrival_time[m]=temp;

                                temp=brust_time[i];
                                brust_time[i]=brust_time[m];
                                brust_time[m]=temp;

                                temp=process[i];
                                process[i]=process[m];
                                process[m]=temp;



			}
			t=t+brust_time[i];
			printf("\n%d              %d                %d\n",process[i],brust_time[i],t);
			

   		}
   }
 }
