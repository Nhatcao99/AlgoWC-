//concept: making most profit from n job with deadline
//Solution: Greedy
//sort all deadline in descreasing order of profit
//get all that is possible to get
#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;
struct Job{
    int id;
    int deadline;
    int profit;
};

bool comparision(Job a, Job b){
    return(a.profit > b.profit);
}

void getDeadLineAndProfit(Job arr[], int n){
    int count = 0, sum = 0;
    sort(arr,arr + n, comparision);
    bool slot[10] = {0};
    for(int i = 0; i < n; i ++){
        slot[i] = false;
    }
    for(int i = 0; i < n ; i ++){
        int tmp = min(n,arr[i].deadline) - 1;
        for(int j = tmp; j >= 0; j --){ // we take the slot from highest index of dead line
            // so if happen to have an index smaller the the current index , it can be filled
            if(slot[j] == false){
                slot[j] = true;//fill the slot
                count ++;
                sum += arr[i].profit;
                break; // stop running array upon finding slot for job
            }
        }
    }
    printf("%d %d\n", count,sum);
}

int main()
{
    int T , n;
    scanf("%d",&T);
    for(int c = 0; c < T; c ++) {
        scanf("%d",&n);
        Job arr[n];
        for(int i = 0; i < n; i ++){
            scanf("%d %d %d", &arr[i].id , &arr[i].deadline, &arr[i].profit);
        }
        getDeadLineAndProfit(arr,n);
    }
    return 0;
}
