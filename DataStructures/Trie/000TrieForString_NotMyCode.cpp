#include<bits/stdc++.h>
using namespace std;

struct trie{
  int words;
  int prefixes;
  char edges[26];
};

inint(trie vertex){
  vertex.words=0;
  vertex.prefixes=0;
  for(int i=0;i<26;i++)vertex.edges[i]=0;
}
addword(trie vertex,string word){
  if(word.empty()){
    vertex.words=vertex.words+1;
  }
  else{
    vertex.prefixes=vertex.prefixes+1;
    char k=word[0];
    if(!vertex.edges[k])inint(vertex.edges[k]);
  }
}

int main(int argc, char const *argv[]) {
  trie vertex;

  return 0;
}
