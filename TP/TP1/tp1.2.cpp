#include <string>
#include <iostream>

int nbvoyelles (std::string s){
	int out(0);
	for(int i=0;i<s.length();i++){
		switch (s[i]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				out++;
				break;
			default:
				break;
		}
	}
}

bool palindrome (std::string s){
	for(int i=0, j=s.length()-1;i<j;i++, j--){
		if(s[i]==s[j]) continue;
		else return 0;
	}
	return 1;
}

std::string Cesar (std::string s, int d) {
	std::string out(s);
	for(int i=0;i<s.length();i++){
		if(s[i]<'a' or s[i]>'z') continue;
		
		int pos = (((s[i]-'a')+d)%26);
		if(pos<0) pos=26+pos; 
		out[i]= pos+'a';
	}
	return out;
}

std::string dechiffrer(std:: string s, int d){
	return Cesar(s,-d);
}

unsigned int str2int (std::string s) {
	if(s.length()==0) return 0;
	return (s[s.length()-1]-'0')+str2int(s.substr(0,s.length()-1))*10;
}

int main() {
	
	std::cout << palindrome("abba");
	std::cout << palindrome("aba");
	std::cout << dechiffrer(Cesar("hello, world",-3),-3)<<std::endl;
	std::cout << str2int("323")<<std::endl;

	return 0;
}