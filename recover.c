#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recovery FILE\n");
        return 1;
    }
    //  open the memory card
    FILE *card = fopen(argv[1], "rb");
    if (card == NULL)
    {
        printf("File can not be opened.\n");
        return 1;
    }

    // While there's still data left to read from the memory card
    uint8_t buffer[512];
    FILE *img = NULL;
    int file_count = 0;
    char filename[8]; // "ooo.jpg" + \NULL
    while (fread(buffer, 512, 1, card) == 1)
    {
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
    {
      if (img != NULL) // means is there a file already opened? if there is nothing , it is false we weiil skip fclose and start writing first file.
            {
            // for the next  GPEG gile we found condition if is true. we need to close the file to start next one
            fclose(img);
            }
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "wb");
            file_count++;
            fwrite(buffer, 512, 1, img);
        }
         else if (img != NULL) // middle of the file
        {
            // continue to write
            fwrite(buffer, 512, 1, img);
        }

    }
        if (img != NULL) // if the last file still opened
        {
            fclose(img); // close last file
        }
    fclose(card);
    return 0;
}
