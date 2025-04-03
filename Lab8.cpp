#include <iostream> //basic IO
#include <fstream> //used for fileio
#include <string> //used for strings
#include <vector> //used to hold vectors
using namespace std;
void matrix_adder(vector<vector<string>> m1, vector<vector<string>> m2,int n){ //matrix adder function
    vector<vector<string>> result(n, vector<string>(n,"0")); //create a result matrix
    for (int i = 0; i < n; ++i) { //iterate through rows
        for (int j = 0; j < n; ++j) { //Iterate through columns
            int sum = stoi(m1[i][j]) + stoi(m2[i][j]); //add the two values together to the matrix
            result[i][j] = to_string(sum); //add the sum to the result
        }
    }
    cout << "Result of adding matricies together:" << endl; //print out new matrix
    for (int i = 0; i < n; ++i) { //iterate through rows
        for (int j = 0; j < n; ++j) { //iterate through columns
            std::cout << result[i][j] << " "; //print the value out
        }
        std::cout << std::endl; //print a new line
    }
};
void matrix_multiplier(vector<vector<string>> m1, vector<vector<string>> m2,int n){
    vector<vector<string>> result(n, vector<string>(n,"0")); //create a result matrix
    for (int i = 0; i < n; ++i) { //Iterate through
        for (int j = 0; j < n; ++j) { //Iterate through
            int sum=0;// create temp sum value
            for(int k=0; k<n; k++){ //Iterate through
                sum += stoi(m1[i][k]) * stoi(m2[k][j]); //add the two values together to the matrix
            }
            result[i][j] = to_string(sum); //add the sum to the result
        }
    }
    cout << "Result of multiplying the matricies:" << endl; //print out new matrix
    for (int i = 0; i < n; ++i) { //iterate through rows
        for (int j = 0; j < n; ++j) { //iterate through columns
            std::cout << result[i][j] << " "; //print out the result
        }
        std::cout << std::endl; //print a new line
    }
};
void diag_sum(vector<vector<string>> m1,int n){
    vector<vector<string>> result1(n, vector<string>(n)); //create result 1 function
    vector<vector<string>> result2(n, vector<string>(n)); //create result 2 function
    int sum1=0; //create sum integers
    int sum2=0;
    for (int i = 0; i < n; ++i){ //iterate through
        for (int j = 0; j < n; ++j) { //iterate through
            if (i == j){ //if we are on the diagonal
                sum1 += stoi(m1[i][j]); //add the value to the result
            }
            if (i == n-j-1){ //if we are on the other diagonal
                sum2 += stoi(m1[i][j]); //add the value to the second result
            }
        }
    }
    cout << "Diagonal 1 sum: " << sum1 << endl; //print the sum
    cout << "Diagonal 2 sum: " << sum2 << endl; //print the sum
};
void swap_rows(vector<vector<string>> m1, int row1, int row2,int n){
    if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n){ //error checking
        cout<<"Invalid row"<<endl; //print error message
    }
    else{
        swap(m1[row1], m1[row2]); //swap the rows
    }
    cout << "Result from swapping row "<<row1+1<<" with "<<row2+1<<endl; //print out new matrix
    for (int i = 0; i < n; ++i) { //iterate through rows
        for (int j = 0; j < n; ++j) { //iterate through columns
            std::cout << m1[i][j] << " "; //print out the value
        }
        std::cout << std::endl; //print a new line
    }
};
void swap_cols(vector<vector<string>> m1, int col1, int col2,int n){
    if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n){ //error checking
        cout<<"Invalid column"<<endl; //print error message
    }
    else { //if all checks
        for(int i=0; i<n; i++){ //iterate through
            string temp= m1[i][col1]; //create a temp variable
            m1[i][col1] = m1[i][col2]; //swap the values
            m1[i][col2] = temp; //swap the values
        }
    }
    cout << "Result from swapping column "<<col1+1<<" with "<<col2+1<<endl; //print out new matrix
    for (int i = 0; i < n; ++i) { //iterate through rows
        for (int j = 0; j < n; ++j) { //iterate through columns
            std::cout << m1[i][j] << " "; //print out the value
        }
        std::cout << std::endl; //print a new line
    }
};
void matrix_updater(vector<vector<string>> m1, int row, int col, string value, int n){ //passing by reference so we update the original value
    vector<vector<string>> result(n, vector<string>(n)); //create a result matrix
    result=m1; //copy the original matrix to the result matrix
    for (int i = 0; i < n; ++i) { //Iterate through
        for (int j = 0; j < n; ++j) { //Iterate through
            if (i == row && j == col){ //if we are at the row and column we want to update
                result[i][j] = value; //update the value
            }
        }
    }
    cout << "Result from editing ("<<row+1<<","<<col+1<<")"<<endl; //print out new matrix
    for (int i = 0; i < n; ++i) { //iterate through rows
        for (int j = 0; j < n; ++j) { //iterate through columns
            std::cout << result[i][j] << " "; //print value
        }
        std::cout << std::endl; //print new line
    }
};

int main() {
    string name; //create a string to hold the name of the file
    cout <<"What is the name of the file containing the matricies?"<<endl;//tell user
    cin >> name; //take in a file name
    ifstream file(name); // Open file
    if (file.is_open()) { // Check if file is open
        int n; //create a integer for the size of the matrix
        file >> n; // Read the size of the matrices
        if (n<1){// error checking
            cout<<"Invalid matrix size"<<endl; //print error message
            return 0; //end program
        }
        file.ignore(); //skip the line after the n size
        vector<vector<string>> matrix1(n, vector<string>(n)); //create matrix 1
        vector<vector<string>> matrix2(n, vector<string>(n)); //create matrix 2
        //for matrix 1
        for (int i = 0; i < n; ++i) { //iterate through the rows
            for (int j = 0; j < n; ++j) { //iterate through columns
                file >> matrix1[i][j]; //take the value from the file at that index and add it to the index of the matrix
            }
        }
        //for matrix 2
        for (int i = 0; i < n; ++i) { //iterate through the rows
            for (int j = 0; j < n; ++j) { //iterate through the columns
                file >> matrix2[i][j]; //take the value from the file at that index and add it to the index of the matrix
            }
        }
        cout << "Matrix 1:" << endl; //print out matrix 1
        for (int i = 0; i < n; ++i) { //iterate through the rows
            for (int j = 0; j < n; ++j) { //iterate through the columns
                std::cout << matrix1[i][j] << " "; //print value from index
            }
            std::cout << std::endl; //make a new line
        }
        cout << "Matrix 2:" << endl; //print out matrix 2
        for (int i = 0; i < n; ++i) { //iterate through rows
            for (int j = 0; j < n; ++j) { //iterate through columns
                std::cout << matrix2[i][j] << " "; //print out the value at that index
            }
            cout << endl; //print a new line
        }
        while(1){ //infinite loop menu
            int choice; //main choice
            //below is the menu prompts
            cout<<"What would you like to do?"<<endl;
            cout<<"1. Add matricies together"<<endl;
            cout<<"2. Multiply the matricies"<<endl;
            cout<<"3. Get sum of diagonals"<<endl;
            cout<<"4. Swap rows"<<endl;
            cout<<"5. Swap columns"<<endl;
            cout<<"6. Update matrix value"<<endl;
            cout<<"7. Exit"<<endl;
            cin>>choice; //take in a choice
            if (choice == 1){ //Add matricies together
                matrix_adder(matrix1, matrix2,n); //run function
            }
            else if (choice == 2){ //multiply matricies together
                matrix_multiplier(matrix1, matrix2,n); //run function
            }
            else if (choice == 3){ //calculate diagonals
                int subchoice; //subchoice integer to choose which matrix
                cout<<"Which matrix do you want the diagonals from?"<<endl; //prompt user
                cin>>subchoice; //take in input
                if (subchoice == 1){ //if matrix 1
                    diag_sum(matrix1,n); //run function with matrix 1
                }
                else if (subchoice == 2){ //if matrix 2
                    diag_sum(matrix2,n); //run function with matrix 2
                }
                else{ //edge case checking
                    cout<<"Invalid choice"<<endl; //print error message
                }
            }
            else if (choice == 4){ //Swap rows
                cout<<"Which matrix do you want to swap rows in?"<<endl; //prompt user
                int subchoice; //subchoice integer to choose which matrix
                cin>>subchoice; //take in input
                if (subchoice == 1){ //if matrix 1
                    cout<<"Which rows do you want to swap? (Starting from row 1 to row "<<n<<")"<<endl; //prompt user
                    int row1, row2; //variables to hold row numbers
                    cout<<"First Row: "<<endl; //print
                    cin>>row1; //take in first column
                    cout<<"\nSecond Row: "<<endl; //print
                    cin>>row2; //take in column to swap with
                    if (row1 > n || row2 > n || row1<0 || row2<0){ //edge case checking
                        cout<<"Invalid column number"<<endl; //print error message
                    }
                    swap_rows(matrix1, row1-1, row2-1,n); //run function with matrix 1
                }
                else if (subchoice == 2){ //if matrix 2
                    cout<<"Which rows do you want to swap? (Starting from row 1 to row "<<n<<")"<<endl; //prompt user
                    int row1, row2; //variables to hold row numbers
                    cout<<"First Row: "<<endl; //print
                    cin>>row1; //take in first column
                    cout<<"\nSecond Row: "<<endl; //print
                    cin>>row2; //take in column to swap with
                    if (row1 > n || row2 > n || row1<0 || row2<0){ //edge case checking
                        cout<<"Invalid column number"<<endl; //print error message
                    }
                    swap_rows(matrix2, row1-1, row2-1,n); //run function with matrix 1
                }
                else{ //edge case checking
                    cout<<"Invalid choice"<<endl; //print error message
                }
            }
            else if (choice == 5){ //Swap columns
                cout<<"Which matrix do you want to swap columns in?"<<endl; //prompt user
                int subchoice; //subchoice integer to choose which matrix
                cin>>subchoice; //take in input
                if (subchoice == 1){ //if matrix 1
                    cout<<"Which columns do you want to swap?(Starting from column 1 to column "<<n<<")"<<endl; //prompt user
                    int col1, col2; //variables to hold row numbers
                    cout<<"First Column: "<<endl; //print
                    cin>>col1; //take in first column
                    cout<<"\nSecond Column: "<<endl; //print
                    cin>>col2; //take in column to swap with
                    if (col1 > n || col2 > n || col1<0 || col2<0){ //edge case checking
                        cout<<"Invalid column number"<<endl; //print error message
                    }
                    swap_cols(matrix1, col1-1, col2-1,n); //run function with matrix 1
                }
                else if (subchoice == 2){ //if matrix 2
                    cout<<"Which Columns do you want to swap?"<<endl; //prompt user
                    int col1, col2; //variables to hold row numbers
                    cout<<"First Column:"; //print
                    cin>>col1; //take in first column
                    cout<<"Second Column:"; //print
                    cin>>col2; //take in column to swap with
                    if (col1 > n || col2 > n || col1<0 || col2<0){ //edge case checking
                        cout<<"Invalid column number"<<endl; //print error message
                    }
                    swap_cols(matrix2, col1-1, col2-1,n); //run function with matrix 1
                }
                else{ //edge case checking
                    cout<<"Invalid choice"<<endl; //print error message
                }
            }
            else if (choice == 6){ //Update matrix value
                cout<<"Which matrix do you want to update a value in?"<<endl; //prompt user
                int subchoice,rowchoice,colchoice; //variables to hold matrix, row, and column numbers
                cin>>subchoice; //take in input
                if (subchoice >2 || subchoice < 1){ //edge case checking
                    cout<<"Invalid matrix choice"<<endl; //print error message
                    return 0; //end program
                }
                cout<<"Which row? (Starting from row 1 to row "<<n<<")"<<endl; //prompt user
                cin>>rowchoice; //take in input
                if (rowchoice > n || rowchoice < 0){ //edge case checking
                    cout<<"Invalid row number"<<endl; //print error message
                    return 0; //end program
                }
                cout<<"Which column? (Starting from row 1 to row "<<n<<")"<<endl; //prompt user
                cin>>colchoice; //take in input
                if (colchoice > n || colchoice < 0){ //edge case checking
                    cout<<"Invalid column number"<<endl; //print error message
                    return 0;
                }
                cout<<"What value do you want to update it to?"<<endl; //prompt user
                string value; //variable to hold value
                cin>>value; //take in input
                if (subchoice == 1){ //if matrix 1
                    matrix_updater(matrix1, rowchoice-1, colchoice-1, value,n); //run function with matrix 1
                }
                else if (subchoice == 2){ //if matrix 2
                    matrix_updater(matrix2, rowchoice-1, colchoice-1, value,n); //run function with matrix 2
                }
                else{ //edge case checking
                    cout<<"Invalid choice"<<endl; //print error message
                }
            }
            else if (choice == 7){ //end program
                return 0;
            }
            else{
                cout<<"Invalid choice"<<endl;
            }
    }
    return 0;
    }
}