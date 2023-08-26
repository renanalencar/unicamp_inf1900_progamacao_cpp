
/**
 * @file matriz.cpp
 *
 * @brief Programa que utilize uma matriz de caracteres 
 * para simular uma tela de arte ASCII com uma dimensão inicial de 20x40.
 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include<iostream>
#include<algorithm>

class Matrix{
    private:
        char** _matrix;
        int _rows;
        int _columns;
    
    public:  

    void InsertValue(int row, int column, char value){
        _matrix[row][column] = value;
    }
    void DefineMatrixSize(int rows, int columns){
        _rows = rows;
        _columns = columns;
    }

    void Initialize(){        
        //Initialize Matrix
        _matrix = new char*[_rows];
        for (int i = 0; i < _rows; i++)
        {
            _matrix[i]= new char[_columns] ;
        }
    }

    void FillWithBlankSpaces(){
         //populate Matrix
        std::fill(_matrix[0], _matrix[_rows-1]+_columns, '.');
    }

    void PrintMatrix(){
        //print Matrix
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _columns; j++)
            {
                std::cout << _matrix[i][j] << "  ";
            }
              std::cout << "\n";
        }
    }

    void ChangeSize(int rows, int columns){
       //create a new matrix
        char** newMatrix = new char*[rows];
        for (int i = 0; i < rows; i++)
        {
            newMatrix[i]= new char[columns] ;
        }

        // copy values from old matrix
        for (int i = 0; i < std::min(_rows, rows); i++)
        {
            for (int j = 0; j < std::min(_columns,columns); j++)
            {
                newMatrix[i][j] = _matrix[i][j];
            }
        }
        
        ReleaseMemory();

        //delegate newMatrix to global matrix
        _matrix = newMatrix;

        //change size references
        DefineMatrixSize(rows,columns);
    }

    void ReleaseMemory(){
         //release memory from global matrix
        for(int i=0; i< _rows; i++){
            delete[] _matrix[i];
        }
        delete[] _matrix;
    }
};

int main()
{
    
    Matrix matrix;
    matrix.DefineMatrixSize(20,40);
    matrix.Initialize();
    matrix.FillWithBlankSpaces();
    bool exit = true;
   
    int row;
    int column;
    
    while(exit){        
        std::cout << "### ASCII Screen 1.0 ###" << std::endl;
        std::cout << "## Choose an option ##" << std::endl;
        std::cout << "#1 Show screen" << std::endl;
        std::cout << "#2 Change size" << std::endl;
        std::cout << "#3 Put value" << std::endl;
        std::cout << "#4 Exit" << std::endl;
        int* option;
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
                matrix.InsertValue(row,column,value);
                break;

            case 4:
                exit=false;
                break;

            default:
                std::cout << "Invalid Option, try again." << std::endl;
                break;
        }
    }
    
    
    matrix.PrintMatrix();

    matrix.ChangeSize(10,10);
    std::cout << "---------------------------------------" << std::endl;
    matrix.PrintMatrix();

}
