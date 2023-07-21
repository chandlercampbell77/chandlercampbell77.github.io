#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over rows
    for (int i = 0; i < height; i++)
    {
        // iterate over columns
        for (int j = 0; j < width; j++)
        {
            // calculate gray value by adding up all values and averaging them out
            float gray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over each row
    for (int i = 0; i < height; i++)
    {
        // mirror column value
        int x = width - 1;

        // iterating over each column
        for (int j = 0; j < width / 2; j++)
        {
            // swapping earlier pixels with mirror pixels
            RGBTRIPLE swap = image[i][j];
            image[i][j] = image[i][x];
            image[i][x] = swap;
            // lowering mirror column value so that next iteration swaps with its mirror pixel
            x--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // creating a copy to work with
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // iterating over rows
    for (int i = 0; i < height; i++)
    {
        // iterating over columns
        for (int j = 0; j < width; j++)
        {
            // normal case
            if (i > 0 && i < height - 1 && j > 0 && j < width - 1)
            {
                image[i][j].rgbtRed = round((copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed
                                             + copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed
                                             + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 9.0);

                image[i][j].rgbtGreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen
                                               + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen
                                               + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 9.0);

                image[i][j].rgbtBlue = round((copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue
                                              + copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue
                                              + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 9.0);

            }

            // upper left corner case
            else if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed
                                             + copy[i + 1][j + 1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen
                                               + copy[i + 1][j + 1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue
                                              + copy[i + 1][j + 1].rgbtBlue) / 4.0);

            }
            // upper right corner case
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j].rgbtRed
                                             + copy[i + 1][j - 1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen
                                               + copy[i + 1][j - 1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue
                                              + copy[i + 1][j - 1].rgbtBlue) / 4.0);

            }
            // upper edge case
            else if (i == 0 && (j != 0 && j != width - 1))
            {
                image[i][j].rgbtRed = round((copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed
                                             + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen
                                               + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue
                                              + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0);

            }
            // bottom left corner case
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j].rgbtRed
                                             + copy[i - 1][j + 1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j].rgbtGreen
                                               + copy[i - 1][j + 1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j].rgbtBlue
                                              + copy[i - 1][j + 1].rgbtBlue) / 4.0);

            }
            // bottom right corner case
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j].rgbtRed
                                             + copy[i - 1][j - 1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen
                                               + copy[i - 1][j - 1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue
                                              + copy[i - 1][j - 1].rgbtBlue) / 4.0);

            }
            // bottom edge case
            else if (i == height - 1 && (j != 0 && j != width - 1))
            {
                image[i][j].rgbtRed = round((copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed
                                             + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen
                                               + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue
                                              + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / 6.0);

            }
            // left edge case
            else if ((i != 0 && i != height - 1) && j == 0)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed
                                             + copy[i + 1][j + 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen
                                               + copy[i + 1][j + 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue
                                              + copy[i + 1][j + 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / 6.0);

            }
            // right edge case
            else if ((i != 0 && i != height - 1) && j == width - 1)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j].rgbtRed
                                             + copy[i + 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen
                                               + copy[i + 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue
                                              + copy[i + 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue) / 6.0);

            }

        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // creating a copy to work with
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    // loop through each row
    for (int row = 0; row < height; row++)
    {
        // loop through each column
        for (int col = 0; col < width; col++)
        {
            int mrow[3] = {row-1, row, row+1};

            int mcol[3] = {col-1, col, col+1};

            int gxr, gxg, gxb;
            gxr = gxg = gxb = 0;

            int gyr, gyg, gyb;
            gyr = gyg = gyb = 0;

            for (int rowcount = 0; rowcount < 3; rowcount++)
            {
                for (int colcount = 0; colcount < 3; colcount++)
                {
                    int nrow = mrow[rowcount];
                    int ncol = mcol[colcount];
                    RGBTRIPLE pixel = copy[nrow][ncol];

                    if (nrow < height && nrow >= 0 && ncol < width && ncol >= 0)
                    {
                        gxr += pixel.rgbtRed * gx[rowcount][colcount];
                        gxg += pixel.rgbtGreen * gx[rowcount][colcount];
                        gxb += pixel.rgbtBlue * gx[rowcount][colcount];

                        gyr += pixel.rgbtRed * gy[rowcount][colcount];
                        gyg += pixel.rgbtGreen * gy[rowcount][colcount];
                        gyb += pixel.rgbtBlue * gy[rowcount][colcount];

                    }
                }
            }
            int newr = round(sqrt(gxr * gxr + gyr * gyr));
            if (newr > 255)
            {
                newr = 255;
            }
            int newg = round(sqrt(gxg * gxg + gyg * gyg));
            if (newg > 255)
            {
                newg = 255;
            }
            int newb = round(sqrt(gxb * gxb + gyb * gyb));
            if (newb > 255)
            {
                newb = 255;
            }

            image[row][col].rgbtRed = newr;
            image[row][col].rgbtGreen = newg;
            image[row][col].rgbtBlue = newb;
        }
    }
    return;

}
