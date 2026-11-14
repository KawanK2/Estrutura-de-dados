int fatorial (int n){
    if(n == 0){
        return 1;
    }else{
        return n * fatorial(n - 1);
    }
};

int main(){
    printf("Fatorial de 5 = %d\n", fatorial(5));
};
