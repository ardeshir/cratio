#include <stdio.h>     /* for fprintf(), strerr, BUFSIZE */
#include <errno.h>     /* declare errno                  */
#include <fcntl.h>     /* for flags for open()           */
#include <string.h>    /* declare strerror()             */   
#include <sys/types.h> /* for types                      */
#include <unistd.h>    /* for mode_t                     */

char *myname;
int process(char *file);

int main(int argc, char **argv) {
     
    int i;
    int errs = 0;
    
    myname = argv[0];
    
    if(argc == 1)
       errs = process("-");
    else 
        for( i = 1; i < argc; i++ )
             errs += process(argv[i]);

	return (errs != 0) ;
}

/* process -- do something with file, in this case
   send it to stdout (fd 1).
   Return 0 if OK, 1 otherwise
*/

int process(char *file) {
    
    int fd;
    ssize_t rcount, wcount;
    char buffer[BUFSIZ];
    int errors = 0;
    
    if( strcmp(file, "-") == 0)
       fd = 0;
    else if ((fd = open(file, O_RDONLY)) < 0 ) {
        fprintf(stderr, "%s: %s: cannot open for reading: %s\n", 
                myname, file, strerror(errno));
        return 1;
    }
    
    while ((rcount = read(fd, buffer, sizeof buffer)) > 0 ) {
        wcount = write(1, buffer, rcount);
        if(wcount != rcount) {
            fprintf(stderr, "%s: %s: write error: %s\n",
                    myname, file, strerror(errno));
            errors++;
            break;
        }
    }

    if(rcount < 0) {
        fprintf(stderr, "%s: %s: read error: %s\n",
                myname, file, strerror(errno));
        errors++;
    }
    
    if(fd != 0 ){
        if(close(fd) < 0 ) {
            fprintf(stderr, "%s: %s: close error: %s\n",
                    myname, file, strerror(errno));
            errors++;
        }
    }
    
    return (errors != 0);
} // end of process

