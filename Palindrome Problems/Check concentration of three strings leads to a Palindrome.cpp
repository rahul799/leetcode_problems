Check concentration of three sub strings leads to a Palindrome


https://www.interviewbit.com/test/b9a83d79a8/?signature=BAhpA9DEBA%3D%3D--cc3ecbca3524bd1ae4a240efdbac377e17d155dc#/problem_2



https://www.youtube.com/watch?v=7GOxmuRKHS0




int Solution::solve(string A, string B, string C) {
    
    int maska = 0, maskc = 0;
    
    for(char i : A){
        maska |= (1 << (i - 'a'));
       
    }
    
    for(char i : C){
        maskc |= (1 << (i - 'a'));
    }
    
    return (maska & maskc) > 0 ;
    
    
    
    
    
}
