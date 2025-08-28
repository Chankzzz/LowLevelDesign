#include <bits/stdc++.h>
using namespace std;

bool pushtomatrix(int col,char colour,vector<vector<char>> &matrix){
    int row=matrix.size();
    //side push
    // if(matrix[row-1][col]!='-'){
//  }
    for(int i=row-1;i>=0;i--){
        if(matrix[i][col]=='-') break;
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]=='-'){
                matrix[i][j]=colour;
                return true;    
            } 
        }
    }
    //top check
    if(matrix[0][col]!='-'){
        cout<<"overflow\n";
        return false;
    }
    //up push
    for(int i=0;i<row-1;i++){
        matrix[i][col]=matrix[i+1][col];
    }
    matrix[row-1][col]=colour;
    return true;
}
void check(vector<vector<char>> &matrix){
    int value=-1;
    for(int j=0;j<matrix[0].size();j++){
        char a=matrix[0][j];
        int count=0;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][j]!=a) break;
            count++;
        }
        if(count==matrix.size()){
            value=j;
        }
    }
///
    int rowvalue=-1;
    for(int j=0;j<matrix.size();j++){
        char a=matrix[j][0];
        int count=0;
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[j][i]!=a) break;
            count++;
        }
        if(count==matrix.size()){
            rowvalue=j;
        }
        if(rowvalue!=-1){
        for(int i=0;i<matrix[0].size();i++){
            matrix[rowvalue][i]='-';
        }
    }
        
    }
/// 
    if(rowvalue!=-1){
        for(int i=0;i<matrix[0].size();i++){
            matrix[rowvalue][i]='-';
        }
    }
    if(value!=-1){
        for(int i=0;i<matrix.size();i++){
            matrix[i][value]='-';
        }
    }
}
void display(vector<vector<char>> matrix){
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}

int main(){
    int r,c;
    cout<<"Enter the Matrix size (m*n) : ";
    cin>>r;
    cin>>c;
    vector<vector<char>> matrix(r,vector<char>(c,'-'));
    char choice;
    bool of;
    do        
    {   
        int col;
        char color;
        cout<<"Enter the column number: ";
        cin>>col;
        cout<<"Enter the color of the balloon : ";
        cin>>color;
        of=pushtomatrix(col-1,color,matrix);
        if(!of) break;
        check(matrix);
        display(matrix);
        cout<<"Do you want to continue(y/n)";
        cin>>choice;
    }while (choice=='y');
    return 0;
}