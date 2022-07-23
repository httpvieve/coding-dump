

int reverse(int x){
    int leftmost, inverse = 0;
    x *= 10;
    while (x /= 10){
        leftmost = x%10;
        inverse = inverse*10 + leftmost;
    }
    return inverse;
}