#include <stdio.h>
#include <stdlib.h> // for exit()
#include <errno.h>
#include <string.h>
#include <unistd.h> // sleep
#include <netdb.h>  // getservbyname() getservbyport()

// struct servent *getservbyname(const char *name, const char *proto); // get data from /etc/services by name and protocol
// struct servent *getservbyport(int port, const char *proto); // get data from /etc/services by port and protocol

// struct servent {
//     char  *s_name;       /* official service name */
//     char **s_aliases;    /* alias list */
//     int    s_port;       /* port number */
//     char  *s_proto;      /* protocol to use */
// }

int main()
{
    struct servent *se;

    se = getservbyname("iax", "tcp");
    if (!se)
    {
        fprintf(stderr, "getservbyname() error=%d (%s)\n", errno, strerror(errno));
        return 1;
    }
    printf("name=%s port=%d protocol=%s\n", se->s_name, se->s_port, se->s_proto);

    se = getservbyport(50195, "tcp");
    if (!se)
    {
        if (errno)
        {
            fprintf(stderr, "getservbyport() error=%d (%s)\n", errno, strerror(errno));
            return 1;
        }
        printf("port not found\n");
        return 0;
    }
    printf("name=%s port=%d protocol=%s\n", se->s_name, se->s_port, se->s_proto);

    return 0;
};
