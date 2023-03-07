class TrieImplement{

TrieNode root = new TrieNode('\0');

static class TrieNode {

    char data;
    TrieNode children[];
    boolean isTerminal;

    public TrieNode(char ch){
        this.data = ch;

        children = new TrieNode[26];

        for(int i=0; i<26; i++){
            children[i] = null;
        }

        this.isTerminal = false;
    }
}

void insertWord(String word){

    TrieNode ptr = root;

    while(word.length() != 0){

        char ch = word.charAt(0);

        if(ptr.children[ch - 'a'] == null){

            ptr.children[ch - 'a'] = new TrieNode(ch);
        
        }
        
        ptr = ptr.children[ch - 'a'];
        word = word.substring(1);
    }

    ptr.isTerminal = true;
}


boolean searchWord(String word){

    TrieNode ptr = root;

    while(word.length() != 0){

        char ch  = word.charAt(0);

        System.out.println(ptr.data);
        if(ptr.children[ch - 'a'] == null) return false;
        else {
            ptr = ptr.children[ch - 'a'];
        }

        word = word.substring(1);
    }

    System.out.println(ptr.data);
    return ptr.isTerminal;

}
    
}
class Trie {
    public static void main(String [] args){

        TrieImplement trie = new TrieImplement();
        trie.insertWord("ram");
        System.out.println(trie.searchWord("ram"));
    }
}