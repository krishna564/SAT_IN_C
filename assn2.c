#include <stdio.h>
int var;
int cal;
int count =0;
void change (int arr[][var],int cal,int var,int t,int mo[],int ver){
    if(t>0){
        mo[t-1]=t;
    }
    else{
        mo[-t-1]=t;
    }
    for(int i=0;i<cal;i++){
        int j=0;
        while(arr[i][j]!=0){
            if(arr[i][j]==t){
                int k=0;
                while(arr[i][k]!=0){
                    arr[i][k]=var+1;
                    k++;
                }
                break;
            }
            if(arr[i][j]==-t){
                arr[i][j]=var+2;
            }
        j++;
        }
    }
   /* for(int i=0;i<cal;i++){
        for(int j=0;j<var;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }*/
}
int search(int arr[][var],int cal,int var){
    int a = var+1;
    int b = var+2;
    int j,q=0;
    for(int i=0;i<cal;i++){
        int k=0;
        int l=0;
        while(arr[i][l]!=0){
            if(arr[i][l]==b){
                k++;
            }
            l++;
        }
        if(k==l)
            return 0;
    }
   /* for(int i=0;i<cal;i++){
        int k=0;
        while(arr[i][k]!=0){
            if(arr[i][k]==a){
                j++;
            }
            k++;
            }
            q=q+k;
        }
        if(j==q)
            return 1; */
    for(int i=0;i<cal;i++){
        if(arr[i][0]!=var+1) return 2; 
    }
    return 1;    
    }

int solve(int arr[][var],int cal,int var,int mo[],int ver){
    int z = search(arr,cal,var);
   // printf("In SOlve\n");
    /*for(int i=0;i<cal;i++){
        for(int j=0;j<var;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",z);*/
    count++;
    if(z==0){
        
        return 0;
    }
    if(z==1)
        for(int k=0;k<ver;k++){
            if(mo[k]==0){
                mo[k]=k+1;
            }
            printf("%d\t",mo[k]);
        }
        return 1;
    int t;
    for (int i=0;i<cal;i++){
        int j=0;
        t=arr[i][j];
        int x=0;
        while(t!=0){
            if(t==var+2){
                j++;
                t=arr[i][j];
            }
            else if(t==var+1)
            {
                i++;
                j=0;
                if(i!=cal) t=arr[i][j];
            }
            else{
                x=1;
                break;
            }
            
        }
        if(x) break;
    }
    int arr1[cal][var];
    int arr2[cal][var];
    for(int i=0;i<cal;i++){
       for(int j=0;j<var;j++){
           arr1[i][j]=arr[i][j];
           arr2[i][j]=arr[i][j];
       }
    }
    int a,b;
    change(arr1,cal,var,t,mo,ver);
    change(arr2,cal,var,-t,mo,ver);
    a=solve(arr1,cal,var,mo,ver);
    b=solve(arr2,cal,var,mo,ver);

    return(a+b); 
}

int main(){
    char a,b,c,d;
    int ver;
    scanf("%c %c%c%c",&a,&b,&c,&d);
    scanf("%d %d",&ver,&cal);
    var=2*ver+1;
    int arr[cal][var];
    int mo[ver];
    for(int y=0;y<ver;y++){
        mo[y]=0;
    }
     for(int i=0;i<cal;i++){
        int k=0;
        scanf("%d ",&arr[i][0]);
        while(arr[i][k]!=0){
            k++;
            scanf ("%d ",&arr[i][k]);
        
        }
        for(int t=k;t<var;t++){
            arr[i][t]=0;
        }
     }
 int p=solve(arr,cal,var,mo,ver);
 printf("%d\n",count);
 if(p==0){
    printf("\nUNSATISFIABLE\n");
 } 
 else
    printf("\nSATISFIABLE\n");
return 0;
}
