// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];// create a baffuer
      input = fopen(argv[1], "rb");
      output = fopen(argv[2], "wb");

    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    //create a buffer for a single sample
    int16_t buffer;

    //read single sample into buffer
    while(fread(&buffer, sizeof(int16_t), 1 , input))// we need & since we work with a single normal variable so we need an address of it.
    {
        //change volume of the sample
        buffer *= factor;// buffer = buffer * factor;

        //write updated sample to new file argv[2]
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }




    // Close files
    fclose(input);
    fclose(output);
}
