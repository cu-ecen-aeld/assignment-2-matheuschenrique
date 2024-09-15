#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

    openlog("My incredible log", 0, LOG_USER);
    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
    
    if (argc != 3) {
        syslog(LOG_ERR, "Wrong number of arguments");
        closelog();
        return 1;
    }

    char *writefile = argv[1];
    char *writestr = argv[2];

    FILE *pFile = fopen(writefile, "w");
    if (pFile == NULL) {
        syslog(LOG_ERR, "Error to read file");
        closelog();
        return 1;
    }

    fputs(writestr, pFile);
    fclose(pFile);
    closelog();
    return 0;
}