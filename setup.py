import setuptools

#Si tienes un readme
with open("README.md", "r") as fh:
  long_description = fh.read()


setuptools.setup(
  name='my_tree',  #nombre del paquete
  version='0.1',   #versión
  scripts=['my_tree.py'] , #nombre del ejecutable
  author="Luciano Vega", #autor
  author_email="lucho.2012.tandil@gmail.com", #email
  description="Librería para python de manejo de árboles, programada en C++", #Breve descripción
  long_description=long_description,
  long_description_content_type="text/markdown", #Incluir el README.md si lo has creado
  url="https://github.com/2012lucho/python_cpp_tree_library", #url donde se encuentra tu paquete en Github
  packages=setuptools.find_packages(), #buscamos todas las dependecias necesarias para que tu paquete funcione 
  classifiers=[
    "Programming Language :: Python :: 3",
    "License :: OSI Approved :: MIT License",
    "Operating System :: OS Independent",
  ],
)
