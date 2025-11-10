#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <network.h>

#define OK 1
#define ERR 0

int checkPuerto(int argc, char **argv, int *puerto)
{
    if (argc != 2)
    {
        printf("Missing Args\n");
        return ERR;
    }

    int auxPuerto = atoi(argv[1]);

    if ((auxPuerto <= 1024) && (auxPuerto >= 49152))
    {
        printf("Puerto ocupado, utilizar otro\n");
        *puerto = 0;
        return ERR;
    }

    *puerto = auxPuerto;

    return OK;
}

void* hiloEscuchador(void *args)
{
    int littleSk = *(int *)args;

    while (1)
    {
        int nRead;
        char msgRx[1024];

        nRead = recv(littleSk, msgRx, 1024, 0);
        printf("Cliente: %s", msgRx);
        msgRx[nRead] = '\0';

        printf("Cliente: %s", msgRx);
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    int puerto = 0;
    if (!checkPuerto(argc, argv, &puerto))
    {
        return ERR;
    }

    int mainSk = OpenServer(puerto);
    if (mainSk < 0)
    {
        printf("Error iniciando servidor\n");
        perror("Motivo de error:");
        return ERR;
    }

    pthread_t hiloListen;
    int littleSk = WaitConnect(mainSk);

    printf("Se ha conectado un cliente\n");

    pthread_create(&hiloListen, NULL, hiloEscuchador, &littleSk);

    while (1)
    {
        char msgTx[1024];
        fgets(msgTx, 1024, stdin);
        send(littleSk, msgTx, strlen(msgTx), 0);
    }

    CloseServer(mainSk);
}