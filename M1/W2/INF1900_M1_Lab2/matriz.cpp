
/**
 * @file matriz.cpp
 *
 * @brief Programa que utilize uma matriz de caracteres
 * para simular uma tela de arte ASCII com uma dimensão inicial de 20x40.

 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>

class Matrix
{
private:
    char **_matrix;
    int _rows;
    int _columns;

public:
    // Function to copy values from old matrix to new matrix
    void CopyValuesTo(Matrix dest)
    {
        for (int i = 0; i < std::min(this->_rows, dest._rows); i++)
        {
            for (int j = 0; j < std::min(this->_columns, dest._columns); j++)
            {
                dest._matrix[i][j] = this->_matrix[i][j];
            }
        }
    }

    // Function to insert value in global matrix
    void InsertValue(int row, int column, char value)
    {
        if (row >= 0 && row < this->_rows && column >= 0 && column < this->_columns)
        {
            this->_matrix[row][column] = value;
        }
        else
        {
            std::cout << "Invalid position!" << std::endl;
        }
    }

    // Function to define size of global matrix
    void DefineMatrixSize(int rows, int columns)
    {
        this->_rows = rows;
        this->_columns = columns;
    }

    // Function to initialize global matrix
    void Initialize()
    {
        // Initialize Matrix
        this->_matrix = new char *[this->_rows];
        for (int i = 0; i < this->_rows; i++)
        {
            this->_matrix[i] = new char[this->_columns];
        }
    }

    // Function to fill global matrix with dots
    void FillWithBlankSpaces()
    {
        // populate Matrix
        std::fill(this->_matrix[0], this->_matrix[this->_rows - 1] + this->_columns, '.');
    }

    // Function to print global matrix
    void PrintMatrix()
    {
        // print Matrix
        for (int i = 0; i < this->_rows; i++)
        {
            for (int j = 0; j < this->_columns; j++)
            {
                std::cout << this->_matrix[i][j];
            }
            std::cout << std::endl;
        }
    }

    // Function to change size of global matrix
    void ChangeSize(int rows, int columns)
    {
        // 1. Create a new matrix
        Matrix newMatrix;
        newMatrix.DefineMatrixSize(rows, columns);
        newMatrix.Initialize();

        // 2. Copy values from old matrix to new matrix
        this->CopyValuesTo(newMatrix);

        // 3. Release memory from global matrix
        this->ReleaseMemory();

        // 4. Change size references
        this->DefineMatrixSize(rows, columns);

        // 5. Allocate memory for global matrix
        this->Initialize();

        // 6. Delegate newMatrix to global matrix
        newMatrix.CopyValuesTo(*this);

        // 7. Release memory from newMatrix
        newMatrix.ReleaseMemory();
    }

    // Function to release memory from global matrix
    void ReleaseMemory()
    {
        // release memory from global matrix
        for (int i = 0; i < this->_rows; i++)
        {
            delete[] this->_matrix[i];
        }
        delete[] this->_matrix;
    }
};

int main()
{

    Matrix matrix;
    matrix.DefineMatrixSize(20, 40);
    matrix.Initialize();
    matrix.FillWithBlankSpaces();
    bool exit = true;

    int row;
    int column;

    while (exit)
    {
        std::cout << "### ASCII Screen 1.0 ###" << std::endl;
        std::cout << "## Choose an option ##" << std::endl;
        std::cout << "#1 Show screen" << std::endl;
        std::cout << "#2 Change size" << std::endl;
        std::cout << "#3 Put value" << std::endl;
        std::cout << "#4 Exit" << std::endl;
        int *option;
        std::cin >> *option;

        switch (*option)
        {
        case 1:
            matrix.PrintMatrix();
            break;

        case 2:
            std::cout << "Enter the number of rows" << std::endl;
            std::cin >> row;
            std::cout << "Enter the numbers of columns" << std::endl;
            std::cin >> column;
            matrix.ChangeSize(row, column);
            break;

        case 3:
            char value;
            std::cout << "Type in the desired row" << std::endl;
            std::cin >> row;
            std::cout << "Type in the desired column" << std::endl;
            std::cin >> column;
            std::cout << "Type in the desired value" << std::endl;
            std::cin >> value;
            matrix.InsertValue(row, column, value);
            break;

        case 4:
            exit = false;
            break;

        default:
            std::cout << "Invalid Option, try again." << std::endl;
            break;
        }
    }

    matrix.PrintMatrix();

    matrix.ChangeSize(10, 10);
    std::cout << "---------------------------------------" << std::endl;
    matrix.PrintMatrix();
}
