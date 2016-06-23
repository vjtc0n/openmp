#include <stdio.h> 
#include <mpi.h> 
#include <unistd.h>


int main(int argc, char** argv){ 
    int id, sz;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&id);
    MPI_Comm_size(MPI_COMM_WORLD,&sz);
    int root = 1;
    int n = 2, S[n], S1[n];
    for(int i = 0; i < n; i++){ 
        S[i] = 0; 
        S1[i] = i∗100+id;
        }
    MPI_Reduce(&S1,&S,2,MPI_INT,MPI_SUM,root,MPI_COMM_WORLD); 
    printf(”Process id = %d has S = ”,id);
    for(int i=0; i<n; i++)
        printf(”%d ”,S[i]);
    printf(”\n”);
    MPI_Finalize () ;
    }

