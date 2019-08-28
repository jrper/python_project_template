#!/usr/bin/env python

from distutils.core import setup, Extension

from numpy import get_include

mod1 = Extension('example._example',
      include_dirs=["source", get_include()], 
      sources=["src/example.c", "src/example_object.c"], )

setup(name='Example',
      version='1.0',
      description='An example template',
      author='James Percival',
      author_email='j.percival@imperial.ac.uk',
      packages=['example'],
      ext_modules=[mod1]
     )