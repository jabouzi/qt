/*
 * File:   main.cpp
 * Author: Gabriele Baldoni
 *
 * Created on 13 ottobre 2013, 11.07
 */

#ifdef __APPLE__ && __MACH__
#include <libssh2.h>
#else //non ho la possibilita' di provare come farlo funzionare su Win
#include <libssh2.h>
#endif




#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
//per i socket
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;

/*
 *
 */
char* psw;

//callback per il keyboard-interactive
static void kbd_callback(const char *name, int name_len,
                         const char *instruction, int instruction_len,
                         int num_prompts,
                         const LIBSSH2_USERAUTH_KBDINT_PROMPT *prompts,
                         LIBSSH2_USERAUTH_KBDINT_RESPONSE *responses,
                         void **abstract)
{
    (void)name;
    (void)name_len;
    (void)instruction;
    (void)instruction_len;
    if (num_prompts == 1) {
        responses[0].text = strdup(psw);
        responses[0].length = strlen(psw);
    }
    (void)prompts;
    (void)abstract;
} /* kbd_callback */

int main(int argc, char** argv) {


    int rc;
    const char* fingerprint;


    //parametri di prova
    char* hostname = "184.172.55.146";
    const char *commandline = "cd www/cms.skanderjabouzi.com && svn up";
    const char *username    = "jabouzic";
    const char *password    = "7024043";
    int port=22;
    char* usr = (char*)malloc(sizeof(char)*255);
    psw=(char*)malloc(sizeof(char)*255);

    //oggetti per la connessione
    int sock;
    LIBSSH2_CHANNEL *channel; //canale
    LIBSSH2_SESSION *session; //sessione
    struct sockaddr_in sin;



    //cout<<"Nome utente: ";
    //fscanf(stdin,"%[^\n]s",usr);
    //getchar();
    //cout<<"pass: ";
    //fscanf(stdin,"%[^\n]s",psw);
    //getchar();

    //richiesta socket
    sock=socket(AF_INET,SOCK_STREAM,0);
    fcntl(sock, F_SETFL, 0);
    //impostazione parametri connessione
    sin.sin_family=AF_INET;
    sin.sin_port=htons(port);
    sin.sin_addr.s_addr=inet_addr(hostname);
    printf("conessione a %s:%d\nCon user %s e pass %s\n",hostname,port,username,password);

    //connessione al socket
    if(connect(sock,(struct sockaddr*)(&sin),sizeof(struct sockaddr_in))!=0) {
        perror("Connessione Socket Fallita");
        return EXIT_FAILURE;
    }

    //inizializzazione della sessione
    session=libssh2_session_init();



    if (libssh2_session_handshake(session, sock)) {

        fprintf(stderr, "Connessione SSH fallita\n");
        return EXIT_FAILURE;
    }

    //leggo il fingerprint dell'host
    fingerprint = libssh2_hostkey_hash(session, LIBSSH2_HOSTKEY_HASH_SHA1);

    fprintf(stderr, "Fingerprint: ");
    int i;
    for(i = 0; i < 20; i++) {
        fprintf(stderr, "%02X ", (unsigned char)fingerprint[i]);
    }
    fprintf(stderr, "\n");

    /* controllo i metodi di autenticazione */
    char *userauthlist;
    userauthlist = libssh2_userauth_list(session, username, strlen(username));

    fprintf(stderr, "Metodi di autenticazione supportati: %s\n", userauthlist);

    if (libssh2_userauth_password(session, username, password)) {
        fprintf(stderr,"\tAutenticazione interattiva fallita\n");
        return EXIT_FAILURE;
    }

    //apro canale per la lettura/scrittura
    if(!(channel=libssh2_channel_open_session(session))) {
        cout<<"Errore apertura canale di comunicazione\n";
        return EXIT_FAILURE;
    }
    else
        cout<<"Canale di comunicazione aperto\n";


    //invio comando
    while( (rc = libssh2_channel_exec(channel, commandline)) == LIBSSH2_ERROR_EAGAIN );
    if( rc != 0 )
    {
        fprintf(stderr,"Error\n");
        return EXIT_FAILURE;
    }


    /*
     * Faccio tutto quello che devo fare con la shell ssh
     * e poi chiudo e libero la memoria
     */

    libssh2_channel_close(channel);
    libssh2_channel_free(channel);

    libssh2_session_disconnect(session,"Bye");
    libssh2_session_free(session);

    return EXIT_SUCCESS;
}
