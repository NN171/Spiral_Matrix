#include "class.h"

spiral_matrix::spiral_matrix()
    {
        std::cin >> size_of_matrix;
        matrix = new int* [size_of_matrix];
        for (int i = 0; i < size_of_matrix; i++)
        {
            matrix[i] = new int [size_of_matrix];
            for (int j = 0; j < size_of_matrix; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void spiral_matrix::spiral()
    {
        int value = 1, cur_str = 0, cur_col = 0;
        for (int border = 0; 2 * border < size_of_matrix; border++)
        {
            cur_str = border;
            cur_col = border;
            for ( ;cur_col < size_of_matrix - border; cur_col++)
            {
                matrix[cur_str][cur_col] = value++;
            }
            for (cur_col--, cur_str++; cur_str < size_of_matrix - border; cur_str++)
            {
                matrix[cur_str][cur_col] = value++;
            }
            for (cur_str--, cur_col--; cur_col >= border; cur_col--)
            {
                matrix[cur_str][cur_col] = value++;
            }
            for (cur_col++, cur_str--; cur_str > border; cur_str--)
            {
                matrix[cur_str][cur_col] = value++;
            }
        }
    }

    void spiral_matrix::print_matrix()
    {
        for (int i = 0; i < size_of_matrix; i++)
        {
            for (int j = 0; j < size_of_matrix; j++)
            {
                std::cout.width(3);
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    spiral_matrix::~spiral_matrix()
    {
        for(int q = 0; q < size_of_matrix; q++)
            delete [] matrix[q];
        delete [] matrix;
        matrix = NULL;
    }