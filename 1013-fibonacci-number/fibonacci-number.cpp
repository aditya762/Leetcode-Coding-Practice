class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }else{
        int a = 0;
        int b = 1;
        for(int i = 0;i<n-1;i++){
            int temp = b;
            b=a+b;
            a=temp;
        }
        return b;
    }
}
};