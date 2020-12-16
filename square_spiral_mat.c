#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    scanf("%d",&n);
    int mat[n][n];
    int left = 0, right = n-1, top = 0, bottom = n-1;
    int num = 1, target = n*n, i;
    
    while(1){
        //filling matrix in -----> order(i.e from left->right)
        for(int i=left; i<=right; ++i){
            mat[top][i] = num;
            num += 1;
        }
        if(num > target)
            break;
        else
            ++top;
        
        /*filling matrix in |
                            |
                            |
                            |
                            \/ order(i.e top to bottom)*/
        for(int i=top; i<=bottom; ++i){
            mat[i][right] = num;
            ++num;
        }
        if(num > target)
            break;
        else
            --right;
        
        /*filling matrix in <---- order(i.e right to left)*/
        for(int i=right; i>=left; --i){
            mat[bottom][i] = num;
            ++num;
        }
        if(num > target)
            break;
        else
            --bottom;
        
        /*filling matrix in ^
                            |
                            |
                            | order(i.e bottom to top)*/
        for(int i=bottom; i>=top; --i){
            mat[i][left] = num;
            ++num;
        }
        if(num > target)
            break;
        else
            ++left;
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
