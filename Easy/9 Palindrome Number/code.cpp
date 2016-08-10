bool isPalindrome(int x) {
    if(x < 10)
        return x>=0;
    int y = 0;
    int h = x;
    while(x > 0){
        y *= 10;
        y += x % 10;
        x /= 10;
    }
    return y == h;
}