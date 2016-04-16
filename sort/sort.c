#include <stdio.h>
#include <stdlib.h>

void bubble_1(int *in,int start,int end,int mode);
void bubble(int *in,int amount);
void quick_in(int *in,int start,int end);
void quick_de(int *in,int end,int start);
void merge_1_in(int *in,int start,int end);                                //separate to two parts and sort
void merge_2_in(int *in,int start_1,int end_1,int start_2,int end_2);      //sort the two parts together
void merge_1_de(int *in,int start,int end);                                //separate to two parts and sort
void merge_2_de(int *in,int start_1,int end_1,int start_2,int end_2);      //sort the two parts together
void print(int *in,int amount,int mode);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int amount,mode;
    int a;

    printf("Given N number:");
    scanf("%d",&amount);

    int in[amount];
    printf("Input: ");
    for(a=0;a<amount;a++)scanf("%d",&in[a]);

    printf("0: bubble, 1: quick, 2: merge :");
    scanf("%d",&mode);

    switch(mode){
        case 0:
            printf("Bubble sort:\n");
            //bubble(in,amount);
            bubble_1(in,0,amount-1,1);
            print(in,amount,1);
            bubble_1(in,0,amount-1,2);
            print(in,amount,2);
            break;
        case 1:
            printf("Quick sort:\n");
            quick_in(in,0,amount-1);
            print(in,amount,1);
            quick_de(in,0,amount-1);
            print(in,amount,2);
            break;
        case 2:
            printf("Merge sort:\n");
            merge_1_in(in,0,amount-1);
            print(in,amount,1);
            merge_1_de(in,0,amount-1);
            print(in,amount,2);
            break;
    }

    return 0;
}
void bubble_1(int *in,int start,int end,int mode){
    int tra,a;
    switch(mode){
        case 1:
            for(a=start;a<=end;a++){
                if(in[end]<in[a]){
                    tra=in[a];
                    in[a]=in[end];
                    in[end]=tra;
                }
            }
            if(start!=end-1)bubble_1(in,start,end-1,1);
            break;
        case 2:
            for(a=start;a<=end;a++){
                if(in[end]>in[a]){
                    tra=in[a];
                    in[a]=in[end];
                    in[end]=tra;
                }
            }
            if(start!=end-1)bubble_1(in,start,end-1,2);
            break;
    }
}

void bubble(int *in,int amount){
    int a,b,tra;
    for(b=amount-1;b>0;b--){
        for(a=0;a<b;a++){
            if(in[a]>in[a+1]){
                tra=in[a];
                in[a]=in[a+1];
                in[a+1]=tra;
            }
        }
    }
    print(in,amount,1);

    for(b=amount-1;b>0;b--){
        for(a=0;a<b;a++){
            if(in[a]<in[a+1]){
                tra=in[a];
                in[a]=in[a+1];
                in[a+1]=tra;
            }
        }
    }
    print(in,amount,2);
}

void quick_in(int *in,int start,int end){
    int origin,small,big,tra;
    origin=start;
    small=start+1;
    big=end;
    while(big>=small){
        if(in[small]<=in[origin]){
            small++;
        }else{
            if(in[big]>=in[origin]){
                big--;
            }else{
                //printf("cha\n");
                tra=in[small];
                in[small]=in[big];
                in[big]=tra;
            }
        }
    }
    //printf("%d %d",big,small);
    tra=in[big];
    in[big]=in[origin];
    in[origin]=tra;
    //print(in,5,1);
    //printf("big:%d start:%d end:%d\n",big,start,end);
    if(big-1>=0&&big-start>1)quick_in(in,start,big-1);
    if(big+1<=end&&end-big>1)quick_in(in,big+1,end);
}

void quick_de(int *in,int end,int start){
    int origin,small,big,tra;
    origin=start;
    small=start-1;
    big=end;
    while(big<=small){
        if(in[small]<=in[origin]){
            small--;
        }else{
            if(in[big]>=in[origin]){
                big++;
            }else{
                //printf("cha\n");
                tra=in[small];
                in[small]=in[big];
                in[big]=tra;
            }
        }
    }
    //printf("%d %d",big,small);
    tra=in[big];
    in[big]=in[origin];
    in[origin]=tra;
    //print(in,5,2);
    //printf("big:%d start:%d end:%d\n",big,start,end);
    if(big-1>=0&&big-end>1)quick_de(in,end,big-1);
    if(big+1<=start&&start-big>1)quick_de(in,big+1,start);
}

void merge_1_in(int *in,int start,int end){
    int tra;
    if(end-start>1){
        //if((end+start)%2==0){
            merge_1_in(in,start,(end+start)/2);
            merge_1_in(in,(end+start)/2+1,end);
            merge_2_in(in,start,(end+start)/2,(end+start)/2+1,end);
        /*}else{
            merge_1_in(in,start,(end+start)/2);
            merge_1_in(in,(end+start)/2+1,end);
            merge_2_in(in,start,(end+start)/2,(end+start)/2+1,end);
        }*/
    }else{
        if(in[start]>in[end]){
            tra=in[start];
            in[start]=in[end];
            in[end]=tra;
        }
    }
}

void merge_2_in(int *in,int start_1,int end_1,int start_2,int end_2){
    int answer[end_2-start_1+1];
    int forth,back,answer_num=0;
    for(forth=start_1,back=start_2;forth<=end_1||back<=end_2;answer_num++){
        if(forth>end_1){
            answer[answer_num]=in[back];
            back++;
            continue;
        }else if(back>end_2){
            answer[answer_num]=in[forth];
            forth++;
            continue;
        }
        if(in[forth]>in[back]){
            answer[answer_num]=in[back];
            back++;
        }else{
            answer[answer_num]=in[forth];
            forth++;
        }
    }
    int a;
    for(a=0;a<answer_num;a++){
        in[start_1]=answer[a];
        start_1++;
    }
}

void merge_1_de(int *in,int start,int end){
    int tra;
    if(end-start>1){
        /*if((end+start)%2==0){
            merge_1_de(in,start,(end+start)/2+1);
            merge_1_de(in,(end+start)/2+2,end);
            merge_2_de(in,start,(end+start)/2+1,(end+start)/2+2,end);
        }else{*/
            merge_1_de(in,start,(end+start)/2);
            merge_1_de(in,(end+start)/2+1,end);
            merge_2_de(in,start,(end+start)/2,(end+start)/2+1,end);
        //}
    }else{
        if(in[start]<in[end]){
            tra=in[start];
            in[start]=in[end];
            in[end]=tra;
        }
    }
}

void merge_2_de(int *in,int start_1,int end_1,int start_2,int end_2){
    int answer[end_2-start_1+1];
    int forth,back,answer_num=0;
    for(forth=start_1,back=start_2;forth<=end_1||back<=end_2;answer_num++){
        if(forth>end_1){
            answer[answer_num]=in[back];
            back++;
            continue;
        }else if(back>end_2){
            answer[answer_num]=in[forth];
            forth++;
            continue;
        }
        if(in[forth]<in[back]){
            answer[answer_num]=in[back];
            back++;
        }else{
            answer[answer_num]=in[forth];
            forth++;
        }
    }
    int a;
    for(a=0;a<answer_num;a++){
        in[start_1]=answer[a];
        start_1++;
    }
}

void print(int *in,int amount,int mode){
    int a;
    switch (mode){
        case 1:
            printf("(1)Increasing:\n");
            for(a=0;a<amount;a++){
                printf("%d ",in[a]);
            }
            printf("\n");
            break;
        case 2:
            printf("(2)Decreasing:\n");
            for(a=0;a<amount;a++){
                printf("%d ",in[a]);
            }
            printf("\n");
            break;
    }
}
