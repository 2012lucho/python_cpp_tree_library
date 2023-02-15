g++ -c -fPIC my_tree.cpp -o my_tree.o
g++ -shared -Wl,-soname,my_tree.so -o my_tree.so  my_tree.o
#python3 setup.py bdist_wheel
