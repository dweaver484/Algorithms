#!/usr/bin/python

class TrieNode:
    def __init__(self):
        self.look_up = {}
        self.val = 0

class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, key, val=0):
        node = self.root
        for c in key:
            if node.look_up.get(c):
                node = node.look_up[c]
            else:
                node.look_up[c] = TrieNode()
                node = node.look_up[c]
        node.val += 1
        
    def find(self, key):
        node = self.root
        for c in key:
            if node.look_up.get(c):
                print('Found {}'.format(c))
                node = node.look_up[c]
            else:
                print('Not Found {}'.format(c))
                return False
        return node.val > 0
             
if __name__ == 'main':
    trie = Trie()
    trie.insert('testa')
    trie.insert('testb')
    if trie.find('testa') and trie.find('testb') and not trie.find('testc'):
        print('PASS')
    else:
        print('FAIL')
