#include<iostream>
#include<cstdlib>
using namespace std;

void matrixMenu(){
    int choice;

    cout<<"\n=========== Matrix Multiplication File ==========\n";
    cout<<"1. Compile the code\n";
    cout<<"2. Run Test_01\n";
    cout<<"3. Run Test_02\n";
    cout<<"4. Run Test_03\n";
    cout<<"5. Run Test_04\n";
    // cout<<"6. Run All Tests\n";
    cout<<"Enter Choice : ";
    cin >> choice;

    switch(choice){
        case 1:
        {
            int status = system("g++ Assignment_01/driver/main.cpp Assignment_01/src/matrix.cpp -o Assignment_01/driver/matrix");
            
            if(status == 0){
                cout << "Compilation successful...";
            }else{
                cout << "Compilation Unsuccessful...";
            }
            break;
        }

        case 2:{
            int status = system("Assignment_01/driver/matrix Assignment_01/tests/Test_01.txt Assignment_01/outputs/Output_01.txt");
            if(status == 0){
                cout << "Output 1 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }

        case 3:{
            int status = system("Assignment_01\\driver\\matrix.exe Assignment_01\\tests\\Test_02.txt Assignment_01\\outputs\\Output_02.txt");
            if(status == 0){
                cout << "Output 2 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }

        case 4:{
            int status = system("Assignment_01\\driver\\matrix.exe Assignment_01\\tests\\Test_03.txt Assignment_01\\outputs\\Output_03.txt");
            if(status == 0){
                cout << "Output 3 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }

        case 5:
        {
            int status = system("Assignment_01\\driver\\matrix.exe Assignment_01\\tests\\Test_04.txt Assignment_01\\outputs\\Output_04.txt");
            if(status == 0){
                cout << "Output 4 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }
        
        default: cout<<"Invalid Choice...";
    }
}

void blockingMatrixMenu(){
    int choice;
    cout<<"\n=========== Blocking Matrix Multiplication File ==========\n";
    cout<<"1. Compile the code\n";
    cout<<"2. Run Test_01\n";
    cout<<"3. Run Test_02\n";
    cout<<"4. Run Test_03\n";
    cout<<"5. Run Test_04\n";
    // cout<<"6. Run All Tests\n";
    cout<<"Enter choice : ";
    cin>>choice;

    switch(choice){
        case 1:
        {
            int status = system("g++ Assignment_02/driver/blockingMain.cpp Assignment_02/src/blockMatrix.cpp -o Assignment_02/driver/block");
            if(status == 0){
                cout << "Compilation successful...";
            }else{
                cout << "Compilation Unsuccessful...";
            }
            break;
        }
        
        case 2:
        {
            int status = system("Assignment_02/driver/block Assignment_02/tests/Test_01.txt Assignment_02/outputs/Output_01.txt");
            if(status == 0){
                cout << "Output 1 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }

        case 3:
        {
            int status = system("Assignment_02\\driver\\block.exe Assignment_02\\tests\\Test_02.txt Assignment_02\\outputs\\Output_02.txt");
            if(status == 0){
                cout << "Output 2 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }
        case 4:
        {
            int status = system("Assignment_02\\driver\\block.exe Assignment_02\\tests\\Test_03.txt Assignment_01\\outputs\\Output_03.txt");
            if(status == 0){
                cout << "Output 3 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }

        case 5:{
            int status = system("Assignment_02\\driver\\block.exe Assignment_02\\tests\\Test_04.txt Assignment_01\\outputs\\Output_04.txt");
            if(status == 0){
                cout << "Output 3 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }
        
//         // case 6:
//         //     system("Assignment_02\\driver\\matrix.exe ALL");
//         //     break;
        
        default:
            cout<<"Invalid Choice...";
    }
}

void csrMenu(){
    int choice;
    cout<<"\n=========== CSR File ==========\n";
    cout<<"1. Compile the code\n";
    cout<<"2. Run Test_01\n";
    cout<<"3. Run Test_02\n";
    cout<<"4. Run Test_03\n";
    cout<<"5. Run Test_04\n";
    // cout<<"6. Run All Tests\n";
    cout<<"Enter choice : ";
    cin>>choice;

    switch(choice){
        case 1:
        {
            int status = system("g++ Assignment_03/driver/csrGraph.cpp Assignment_03/src/CSR.cpp -o Assignment_03/driver/csr");
            if(status == 0){
                cout << "Compilation successful...";
            }else{
                cout << "Compilation Unsuccessful...";
            }
            break;
        }
        
        case 2:{
            int status = system("Assignment_03/driver/csr Assignment_03/tests/Test_01.txt Assignment_03/outputs/Output_01.txt");
            if(status == 0){
                cout << "Output 1 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }

        case 3:{
            int status = system("Assignment_03\\driver\\csr.exe Assignment_03\\tests\\Test_02.txt Assignment_03\\outputs\\Output_02.txt");
            if(status == 0){
                cout << "Output 2 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }

        case 4:{
            int status = system("Assignment_03\\driver\\csr.exe Assignment_03\\tests\\Test_03.txt Assignment_03\\outputs\\Output_03.txt");
            if(status == 0){
                cout << "Output 3 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }

        case 5:{
            int status = system("Assignment_03\\driver\\csr.exe Assignment_03\\tests\\Test_04.txt Assignment_03\\outputs\\Output_04.txt");
            if(status == 0){
                cout << "Output 4 Generated...";
            }else{
                cout << "Output not generated...";
            }
            break;
        }
        
        // case 6:
        //     system("Assignment_03\\driver\\matrix.exe ALL");
        //     break;
        
        default:
            cout<<"Invalid Choice...";
    }
}

int main(){
    int choice;

    while(true){
        cout << "\n==============================\n";
        cout << "        CS509 Lab Wrapper\n";
        cout << "==============================\n";

        cout<<"1. Assignment_01 : Matrix Multiplication\n";
        cout<<"2. Assignment_02 : Blocking Matrix Multiplication\n";
        cout<<"3. Assignment_03 : CSR\n";
        cout<<"4. Exit\n";

        cout<<"\nEnter choice : ";
        cin >> choice;

        switch(choice){

            case 1:
                matrixMenu();
                break;

            case 2:
                blockingMatrixMenu();
                break;

            case 3:
                csrMenu();
                break;

            case 4:
                cout<<"Exiting code...\n";
                return 0;
            
            default:
                cout<<"Invalid choice\n";
        }
    }
    return 0;
}