#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    // make sure user only types in one command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // open forensic image
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // set outfile pointer to NULL
    FILE *outfile = NULL;

    // define uint8_t as byte of memory
    typedef uint8_t BYTE;

    // define number of bytes to read at a time
    int BLOCK_SIZE = 512;

    // create an array to hold 512 bytes from the forensic image
    BYTE buffer[512];

    //count amount of jpeg files found
    int jpeg_count = 0;

    // string to hold a filename (###.jpg + NUL character = 8)
    char filename[8] = {0};

    // creating variable to check if we found a jpeg
    bool jpegfound = false;

    // read memory card untill the end of file
    while (fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        // check if jpeg is found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            jpegfound = true;

            // if first jpeg
            if (jpeg_count == 0)
            {
                // create a first jpg image to write to
                sprintf(filename, "%03i.jpg", jpeg_count++);

                // open first outfile for writing first jpeg
                outfile = fopen(filename, "w");

                // write 512 bytes to jpeg
                fwrite(buffer, 1, BLOCK_SIZE, outfile);
            }
            // not first jpeg
            else if (jpeg_count > 0)
            {
                // close last jpeg
                fclose(outfile);

                // create a new jpg image to write to
                sprintf(filename, "%03i.jpg", jpeg_count++);

                // open a new outfile for writing a new found jpeg
                outfile = fopen(filename, "w");

                // write 512 bytes to jpeg
                fwrite(buffer, 1, BLOCK_SIZE, outfile);

            }
        }
        // keep writing to jpeg file if new jpeg is not found
        else if (jpegfound == true)
        {
            fwrite(buffer, 1, BLOCK_SIZE, outfile);
        }
    }


    // close last opened outfile
    fclose(outfile);

    // close forensic image
    fclose(infile);

    // end program
    return 0;

}