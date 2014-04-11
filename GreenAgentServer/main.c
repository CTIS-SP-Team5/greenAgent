/*

Created by A.Cemil SABIR
acsabir@gmail.com
2 April 2014 14:00

This is the main server file that reads the output of
Arduino sketch running on Arduino DUE on UDOO via serial,
and puts the related lines into the database. Other than
that, this program has no functionality, and should NOT
have any. The purpose behind this structuring is to isolate
the sensors subsystem from the other subsystems, increasing
stability, security, and persistence.

Losely described, this program has two main goals. First is
to connect and read data from the serial line that the
Arduino DUE talks to, and second is to store whatever
"meaningful" thing it heards from the serial line.

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>

/*

Set the buffer size. The buffer is simply a character array
that holds the last line read from the serial. Default size
is 256 characters long, meaning that the actual string that
could fit in should be 255 characters long(last character is
always '\0').

*/

#define BUFFER_SIZE 256

/*

A temproary buffer to store serial line input is needed.
Until the raw output is processed and stored into the database,
buffer should not be overwritten. 256 characters should be
sufficient, since there is not any line that Arduino writes
into the serial line exceeding 256 characters.

*/

char BUFFER[BUFFER_SIZE];

/*

The Arduino serial line is fixed in UDOO, however, this may
be manupilated on Linux side. Therefore, a variable to hold
the port address is needed. Default value is "/dev/ttymxc3"
but it can, and will be overriden. To manipulate this value
change the SERIAL_LINE line in the settings file.

*/

char *SERIAL_LINE = "/dev/ttymxc3";

/*

Arduino DUE takes its sweet time initializing and getting
ready to put data into serial line, therefore, we need to
wait for her magesty to get ready. This delay may fluctuate
from system to system, therefore we declare a variable to
hold the waiting time, which can be manipulated by changing
the WAIT_ARDUE_INIT line.

*/

int WAIT_ARDUINO_INIT = 1000 * 1000;        // Default value.

/*

Set how many bytes to be read from the serial line. To manipulate
this value, change the READ_BYTE_LIM line in the settings file.

 */

 int READ_BYTE_LIM = 128;                   // Default value.




/* Done with the declerations. */

void  readline(int file_descriptor, char buffer[])
{
    /*int pos = 0,
        count = -1;

    while (pos < READ_BYTE_LIM - 1)
    {
        count = read(file_descriptor, buffer, 1);

        if (buffer[pos] = '\n') break;

        pos++;
    }

    return count;*/

    while(read(file_descriptor, &buffer[0], sizeof(char)))
    {
        if (buffer[0] != '\0')
            printf("%02x", buffer[0]);

        buffer[0] = '\0';
    }
}

int main(int argc, char *argv[])
{

    /*

    We need a file descriptor to access, control, and listen to
    the serial line. Remember that anything that does I/O can be
    treated as a file.

    */

    int file_descriptor;

    /*

    Now we need to open the serial line in non-blocking mode. There
    may be others that can be listening, or may listen to the
    serial line while the program is in operation, thus the line is
    opened in non-blocking mode.

    */

    file_descriptor = open(SERIAL_LINE, O_RDWR | O_NOCTTY);

    /*

    Set up the control structure.

    */

    struct termios toptions;

    /*

    Now get the currently set options for the tty and put them into
    the control structure.

    */

    tcgetattr(file_descriptor, & toptions);



    /*

    Now it's time to set some options for the serial line. This is
    done by setting the corresponding bits of c_cflag/c_iflag/c_oflag
    1 or 0. This is all technical details on how the serial line
    operates, there is nothing related to the intended functionality
    of the program. But for the code to work, we need to set the
    serial line parameters properly, therefore; if it confuses you,
    just scroll down this part. Lots and lots of bitwise operations,
    nothing fancy.

    */



    // ----------------- SERIAL LINE OPTIONS START ----------------- //



    /* Always set the baud rate first. */

    cfsetispeed(&toptions, B9600);      // Input BR set.
    cfsetospeed(&toptions, B9600);      // Output BR set.

    /* 8 bit, no parity, no stop bits. Good old default serial settings. */

    toptions.c_cflag &= ~PARENB;
    toptions.c_cflag &= ~CSTOPB;
    toptions.c_cflag &= ~CSIZE;
    toptions.c_cflag |= CS8;

    /* No hardware flow control. */

    toptions.c_cflag &= ~CRTSCTS;

    /* Enable receiver, and ignore status lines. */

    toptions.c_cflag |= CREAD | CLOCAL;

    /* Disable I/O flow control and restart chars. */

    toptions.c_iflag &= ~(IXON | IXOFF | IXANY);

    /*

    Disable canonical input, echo, visually erase chars,
    terminal-generated signals.

    */

    toptions.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);


    /* Diasable output processing. */

    toptions.c_oflag &= ~OPOST;




    /* Waiting options for read(). */



    /* Wait for 10 characters to come in before read() returns. */

    toptions.c_cc[VMIN] = 1;

    /* No minimum time to wait before read() returns. Why wait? */

    toptions.c_cc[VTIME] = 0;





    /* Options are set. Time to commit them. */

    tcsetattr(file_descriptor, TCSANOW, &toptions);





    // ----------------- SERIAL LINE OPTIONS END ----------------- //





    /* Wait for Arduino DUE to finish initializing. */

    //usleep(WAIT_ARDUINO_INIT);

    /* Flush anything in the serial line. Let's keep it clean. */

    tcflush(file_descriptor, TCIFLUSH);

    /* Read READ_BYTE_LIM bytes from the serial line into the BUFFER. */

    /* while (1)
    {
        // Print to the console.
        readline(file_descriptor, BUFFER);
        printf("Buffered:\n%s\n", BUFFER);
    }
    */
int count = 0 ;
while(1)
{
    int n = read(file_descriptor, &BUFFER[count], 1);
    count++ ;

    if (count == 128)
    count = 0;
    BUFFER[count] = '\0';



    //printf("\nRead %d bytes.\n", n);
    printf("Read: %s\n", BUFFER);
}



    /* End of code. Tada! */

    return 0;           // Ever faithfully.

}
