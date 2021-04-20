


https://github.com/jolly-fellow/microsoft/tree/master/min_moves_to_make_string_without_3_identical_consecutive_letters


Min Moves to Make String Without 3 Identical Consecutive Letters

int solution(string s){
	int res = 0;
	for(int i = 0 ; i < s.length() ;){
		int next = i+1;
		while(next < s.length() && s[i] == s[next]) next++;
		res += (next - i)/3;
		i = next;
	}
	return res;
}
