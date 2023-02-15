from ctypes import *
lib = cdll.LoadLibrary('./my_tree.so')

class TreeNode(object):
    def __init__(self):
        self.obj = lib.Tree_node_new()

class Tree(object):
    def __init__(self):
        self.obj = lib.Tree_new()

    def add(self, test):
        test = create_string_buffer(test)
        lib.Tree_add.restype = c_char_p
        s = lib.Tree_add(self.obj, test)
        print (s)

f = Tree()
f.add(b"Prueba")

