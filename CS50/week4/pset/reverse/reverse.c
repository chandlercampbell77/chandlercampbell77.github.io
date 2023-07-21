#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Read header into buffer
    WAVHEADER buffer;
    int headersize = 44;

    fread(&buffer, sizeof(BYTE), headersize, infile);

    // Use check_format to ensure WAV format
    if (check_format(buffer) == 0) // 0 means false, not a WAV file
    {
        printf("Only WAV files supported.\n");
        return 1;
    }

    // Open output file for writing
    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL)
    {
        printf("Could not open %s.\n", argv[2]);
        return 1;
    }

    // Write header to output file
    fwrite(&buffer, sizeof(BYTE), headersize, outfile);

    // Use get_block_size to calculate size of block
    int blocksize = get_block_size(buffer);

    // Creating a buffer
    BYTE block[blocksize];

    // setting file pointer position to the end
    fseek(infile, blocksize, SEEK_END);

    // continue reversing audio as long as file pointer does not reach the header
    while (ftell(infile) - blocksize > headersize)
    {
        // moving file pointer 2 blocks backwards
        fseek(infile, -2 * blocksize, SEEK_CUR);

        // reading 1 block at a time
        fread(block, blocksize, 1, infile);

        // writing 1 block at a time
        fwrite(block, blocksize, 1, outfile);
    }

    // ensuring no memory leak
    fclose(infile);
    fclose(outfile);

}


int check_format(WAVHEADER header)
{
    // check for WAV file signature
    char format[4] = "WAVE";
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != format[i])
        {
            return 0;
        }
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    int blocksize = 0;

    // to get number of byes per sample, divide by 8 since there are 8 bits in a byte
    int bytesPerSample = header.bitsPerSample / 8;

    // forumula to get blocksize
    blocksize = header.numChannels * bytesPerSample;

    return blocksize;
}