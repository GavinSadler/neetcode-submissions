
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class PrefixTree:

    def __init__(self):
        self.root = None

    def insert(self, word: str) -> None:

        if not self.root:
            self.root = Node(word)
            return

        curr = self.root

        while curr:
            if curr.value == word:
                return
            elif curr.value < word:
                if curr.left:
                    curr = curr.left
                else:
                    curr.left = Node(word)
                    return                   
            elif curr.value > word:
                if curr.right:
                    curr = curr.right
                else:
                    curr.right = Node(word)
                    return

    def search(self, word: str) -> bool:

        n = self.root

        while n:
            if n.value == word:
                return True
            elif n.value < word:
                n = n.left
            elif n.value > word:
                n = n.right
        
        return False

    def startsWith(self, prefix: str) -> bool:

        n = self.root

        while n:
            if n.value.startswith(prefix):
                return True
            elif n.value < prefix:
                n = n.left
            elif n.value > prefix:
                n = n.right
        
        return False
        