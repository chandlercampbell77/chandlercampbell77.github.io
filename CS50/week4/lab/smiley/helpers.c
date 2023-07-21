#include "helpers.h"
#include <stdio.h>
#include <cs50.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // change smiley face picture

    // iterate over the first dimension of the array
    for (int i = 0; i < height; i++)
    {
        // iterate over second dimension of the array
        for (int j = 0; j < width; j++)
        {
            // image[i][j] is the location of a single pixel
            // 0x000000 = black
            // 0xffffff = white
            // 0x0000ff = blue
            // 0x00ff00 = green
            // 0xff0000 = red

            // if the pixel is black, convert to blue
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00)
            {
                image[i][j].rgbtBlue = 0xff;
                // this gives us the new pixel color of 0x0000ff, which is exactly blue
            }
        }
    }
}