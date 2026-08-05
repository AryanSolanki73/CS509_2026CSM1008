#include<iostream>
#include<cstdlib>
using namespace std;

void matrixMenu(){
    int choice;

    cout<<"\n=========== Matrix Multiplication File ==========\n";
    cout<<"\n1. Compile the code\n";
    cout<<"2. Run Test_01_2×2\n";
    cout<<"3. Run Test_02_10×10\n";
    cout<<"4. Run Task_03_100×100\n";
    cout<<"5. Run Test_04_250×250\n";
    cout<<"6. Run Test_05_500×500\n";
    cout<<"7. Run Test_06_1000×1000\n";
    cout<<"8. Run All Tests\n";
    cout<<"\nEnter Choice : ";
    cin >> choice;

    switch(choice){
        case 1:
        {
            int status = system("g++ Assignment_01/Task_01/driver/main.cpp Assignment_01/Task_01/src/matrix.cpp -o Assignment_01/Task_01/driver/matrix");
            
            if(status == 0){
                cout << "\nCompilation successful\n";
            }else{
                cout << "\nCompilation Unsuccessful\n";
            }
            break;
        }

        case 2:{
            int status = system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_01.txt Assignment_01/Task_01/outputs/Output_01.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 3:{
            int status = system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_02.txt Assignment_01/Task_01/outputs/Output_02.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 4:{
            int status = system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_03.txt Assignment_01/Task_01/outputs/Output_03.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 5:
        {
            int status = system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_04.txt Assignment_01/Task_01/outputs/Output_04.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }
     
        case 6:
        {
            int status = system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_05.txt Assignment_01/Task_01/outputs/Output_05.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 7:
        {
            int status = system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_06.txt Assignment_01/Task_01/outputs/Output_06.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 8:
        {
            system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_01.txt Assignment_01/Task_01/outputs/Output_01.txt");
            system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_02.txt Assignment_01/Task_01/outputs/Output_02.txt");
            system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_03.txt Assignment_01/Task_01/outputs/Output_03.txt");
            system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_04.txt Assignment_01/Task_01/outputs/Output_04.txt");
            system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_05.txt Assignment_01/Task_01/outputs/Output_05.txt");
            system("Assignment_01/Task_01/driver/matrix Assignment_01/Task_01/tests/Test_06.txt Assignment_01/Task_01/outputs/Output_06.txt");
            cout<<"\nAll Output Generated.\n";
            break;
        }
        default: cout<<"Invalid Choice...";
    }
}

void blockingMatrixMenu(){
    int choice;
    cout<<"\n=========== Blocking Matrix Multiplication File ==========\n";
    cout<<"\n1. Compile the code\n";
    cout<<"2. Run Test_01_4×4\n";
    cout<<"3. Run Test_02_10×10\n";
    cout<<"4. Run Task_03_100×100\n";
    cout<<"5. Run Test_04_250×250\n";
    cout<<"6. Run Test_05_500×500\n";
    cout<<"7. Run Test_06_1000×1000\n";
    cout<<"8. Run All Tests\n";
    cout<<"\nEnter choice : ";
    cin>>choice;

    switch(choice){
        case 1:
        {
            int status = system("g++ Assignment_01/Task_02/driver/blockingMain.cpp Assignment_01/Task_02/src/blockMatrix.cpp -o Assignment_01/Task_02/driver/block");
            if(status == 0){
                cout << "\nCompilation successful\n";
            }else{
                cout << "\nCompilation Unsuccessful\n";
            }
            break;
        }
        
        case 2:
        {
            int status = system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_01.txt Assignment_01/Task_02/outputs/Output_01.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 3:
        {
            int status = system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_02.txt Assignment_01/Task_02/outputs/Output_02.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }
        case 4:
        {
            int status = system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_03.txt Assignment_01/Task_02/outputs/Output_03.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 5:{
            int status = system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_04.txt Assignment_01/Task_02/outputs/Output_04.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }
        
        case 6:{
            int status = system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_05.txt Assignment_01/Task_02/outputs/Output_05.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 7:
        {
            int status = system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_06.txt Assignment_01/Task_02/outputs/Output_06.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 8:
        {
            system("g++ Assignment_01/Task_02/driver/blockingMain.cpp Assignment_01/Task_02/src/blockMatrix.cpp -o Assignment_01/Task_02/driver/block");
            system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_01.txt Assignment_01/Task_02/outputs/Output_01.txt");
            system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_02.txt Assignment_01/Task_02/outputs/Output_02.txt");
            system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_03.txt Assignment_01/Task_02/outputs/Output_03.txt");
            system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_04.txt Assignment_01/Task_02/outputs/Output_04.txt");
            system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_05.txt Assignment_01/Task_02/outputs/Output_05.txt");
            system("Assignment_01/Task_02/driver/block Assignment_01/Task_02/tests/Test_06.txt Assignment_01/Task_02/outputs/Output_06.txt");
            cout<<"\nAll Outputs Generated successfully.\n";
            break;
        }
        
        default:
            cout<<"Invalid Choice...";
    }
}

void csrMenu(){
    int choice;
    cout<<"\n=========== CSR File ==========\n";
    cout<<"\n1. Compile the code\n";
    cout<<"2. Run Test_01\n";
    cout<<"3. Run Test_02\n";
    cout<<"4. Run Task_03\n";
    cout<<"5. Run Test_04\n";
    cout<<"6. Run Test_05\n";
    cout<<"7. Run all Testcases\n";
    cout<<"\nEnter choice : ";
    cin>>choice;

    switch(choice){
        case 1:
        {
            int status = system("g++ Assignment_01/Task_03/driver/csrGraph.cpp Assignment_01/Task_03/src/CSR.cpp -o Assignment_01/Task_03/driver/csr");
            if(status == 0){
                cout << "\nCompilation successful\n";
            }else{
                cout << "\nCompilation Unsuccessful\n";
            }
            break;
        }
        
        case 2:{
            int status = system("Assignment_01/Task_03/driver/csr Assignment_01/Task_03/tests/Test_01.txt Assignment_01/Task_03/outputs/Output_01.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 3:{
            int status = system("Assignment_01/Task_03/driver/csr Assignment_01/Task_03/tests/Test_02.txt Assignment_01/Task_03/outputs/Output_02.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 4:{
            int status = system("Assignment_01/Task_03/driver/csr Assignment_01/Task_03/tests/Test_03.txt Assignment_01/Task_03/outputs/Output_03.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 5:{
            int status = system("Assignment_01/Task_03/driver/csr Assignment_01/Task_03/tests/Test_04.txt Assignment_01/Task_03/outputs/Output_04.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }
        
        case 6:{
            int status = system("Assignment_01/Task_03/driver/csr Assignment_01/Task_03/tests/Test_05.txt Assignment_01/Task_03/outputs/Output_05.txt");
            if(status == 0){
                cout << "\nOutput Generated\n";
            }else{
                cout << "\nOutput not generated\n";
            }
            break;
        }

        case 7:
        {
            system("Assignment_01/Task_03/driver/csr Assignment_01/Task_03/tests/Test_01.txt Assignment_01/Task_03/outputs/Output_01.txt");
            system("Assignment_01/Task_03/driver/csr Assignment_01/Task_03/tests/Test_02.txt Assignment_01/Task_03/outputs/Output_02.txt");
            system("Assignment_01/Task_03/driver/csr Assignment_01/Task_03/tests/Test_03.txt Assignment_01/Task_03/outputs/Output_03.txt");
            system("Assignment_01/Task_03/driver/csr Assignment_01/Task_03/tests/Test_04.txt Assignment_01/Task_03/outputs/Output_04.txt");
            system("Assignment_01/Task_03/driver/csr Assignment_01/Task_03/tests/Test_05.txt Assignment_01/Task_03/outputs/Output_05.txt");
            cout<<"\nAll Output Generated.\n";
            break;
        }
        
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

        cout<<"\n1. Task_01 : Matrix Multiplication\n";
        cout<<"2. Task_02 : Blocking Matrix Multiplication\n";
        cout<<"3. Task_03 : CSR\n";
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
                cout<<"\nExiting code...\n";
                return 0;
            
            default:
                cout<<"\nInvalid choice\n";
        }
    }
    return 0;
}