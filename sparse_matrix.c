#include<stdio.h>
#include<stdlib.h>

void to_tuple(int a[][100],int tp[][3],int r, int c){
  int x=0,n=1;
  tp[0][0]=r;
  tp[0][1]=c;
  
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(a[i][j]!=0){
        tp[n][0]=i;
        tp[n][1]=j;
        tp[n][2]=a[i][j];
        x++;
        n++;
      }
  }
  tp[0][2]=x;
    
    

int main(void){
  int a[100][100], b[100][100];
  int tp1[100][3], tp2[100][3];
  int r1,c1,r2,c2;
  
  while(1){
    int op, element;
    printf("\n1. Read matrix\n2. Display matrix\n3. Matrix to tuple\n4. Display tuple\n5. Transpose of matrix in tuple form\n6. Display transpose\n7. Add matrices and display sum\n8. Exit");
    printf("\nEnter your choice:");
    scanf("%d",&op);
    switch(op){
      case 1:
        printf("Enter the order of the first matrix:\n");
        scanf("%d %d",&r1,&c1);
        printf("Enter the elements of the matrix:\n");
        read_matrix(a,r1,c1);
        
        printf("\n");
        
        printf("Enter the order of the second matrix:\n");
        scanf("%d %d",&r2,&c2);
        printf("Enter the elements of the matrix:\n");
        read_matrix(b,r2,c2);
        
        break;
        
      case 2:
        printf("\n\nMatrix 1:\n");
        disp_matrix(a,r1,c1);
        
        printf("\n\nMatrix 2:\n");
        disp_matrix(b,r2,c2);
        
        break;
        
      case 3:
        to_tuple(a,tp1,r1,c1);
        to_tuple(b,tp2,r2,c2);
        
        break;
        
      case 4:
        printf("\n\nTuple 1:\n");
        disp_tuple(tp1);
        
        printf("\n\nTuple 2:\n");
        disp_tuple(tp2);
        
        break;
        
      case 5:
        trans_tuple(tp1);
        trans_tuple(tp2);
        
        break;
        
      case 6:
        printf("\n\nTranspose 1:\n");
        disp_tuple(tp1);
        
        printf("\n\nTranspose 2:\n");
        disp_tuple(tp2);
        
        break;
        
      case 7:
        int sum[20][3];
        add(tp1,tp2,sum);
        printf("\n\nSum:\n");
        disp_tuple(sum);
        break;
        
      case 8:
        return 0;
        
      default:
        printf("Invalid choice:");
        break;
    }
    return 0;
}
  
void read_matrix(int a[][100], int r, int c){
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      scanf("%d",&a[i][j]);
    }
  }
}

void disp_matrix(int a[][100], int r, int c){
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      printf("%d\t",a[i][j]);
    }
    printf("\n");
  }
}
  

}
  
void disp_tuple(int tp[][3]){
  printf("Row\tColumn\tValue\n");
  for(int i=0;i<=tp[0][2];i++){
    printf("%d\t%d\t%d\t\n",tp[i][0],tp[i][1],tp[i][2] );
  }
}
  
void trans_tuple(int tp[][3]){
  int n=tp[0][2];
  for(int i;i<=n;i++){
    int temp=tp[i][0];
    tp[i][0]=tp[i][1];
    tp[i][1]=temp;
  }
  
  for(int i;i<=n;i++){
    for(int j;j<=n-i;j++){
      if(tp[j][0]>tp[j+1][0]){
        int temp=tp[j][0];
        tp[i][0]=tp[j+1][0];
        tp[j+1][0]=temp;
        
        temp=tp[j][1];
        tp[i][1]=tp[j+1][1];
        tp[j+1][1]=temp;
        
        temp=tp[j][2];
        tp[i][2]=tp[j+1][2];
        tp[j+1][2]=temp;
      }
    }
  }
}

  
void add(int a[][3], int b[][3], int sum[][3]){
  int x=1,y=1,z=1;
  if(a[0][0]!=b[a][0]||a[0][1]!=b[0][1]){
    printf("Matrices cannot be added:\n");
    return;
  }
  else{
    sum[0][0]=a[0][0];
    sum[0][1]=a[0][1];
    
    while((p<=a[0][2])&&(q<=b[0][2])){
      int x1=a[x][0];
      int x2=a[x][1];
      int y1=b[y][0];
      int y2=b[y][1];
      
      if((x1==y1)&&(x2==y2)){
        int s=a[x][2]+b[y][2];
        if(s!=0){
          sum[z][0]=a[x][0];
          sum[z][1]=a[x][1];
          sum[z][2]=sum;
          z++;
        }
        x++;
        y++;
      }
      else if((x1>y1)||((x1==y1)&&(x2>y2))){
        sum[z][0]=b[y][0];
        sum[z][1]=b[y][1];
        sum[z][2]=b[y][2];
        y++;
        z++;
        count++;
      }
      else if((x1<y1)||((x1==y1)&&(x2<y2))){
        sum[z][0]=a[x][0];
        sum[z][1]=a[x][1];
        sum[z][2]=a[x][2];
        x++;
        z++;
        count++;
      }
    }
  
    while(x<=a[0][2]){
      sum[z][0]=a[x][0];
      sum[z][1]=a[x][1];
      sum[z][2]=a[x][2];
      x++;
      z++;
      
    }
  
    while(y<=b[0][2]){
      sum[z][0]=b[y][0];
      sum[z][1]=b[y][1];
      sum[z][2]=b[y][2];
      y++;
      z++;
      
    }

    sum[0][2]=z-1;
  }
}
    
    

      
  
                   
               
        
