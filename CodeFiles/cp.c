/* Implementation of cp command in xv6	*/
#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"

int main(int argc,char *argv[]) {
 int fd1, fd2;      /* File descriptors for read and write */
 int n;             /* Number of characters returned by read */
 char buf[1024]; /* Size of buffer used by read and write */
 if ((fd1 = open(argv[1], O_RDONLY)) == -1){
        printf(2,"error in open source file");
        exit();
}
 if ((fd2 = open(argv[2], O_CREATE| O_WRONLY))== -1){
         printf(2,"error in opening destination file");
        exit();
}
while ((n = read(fd1, buf, sizeof(buf))) > 0) {      /* Return value of read */
   if(write(fd2, buf, n)!=n) { /* used by write  */
      printf(1, "write error\n");
      exit();
    }
  }	
  close(fd1);/* This would have closed all file descriptors */
  close(fd2);
  exit();         
}

