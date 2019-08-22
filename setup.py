#!/usr/bin/env python

from distutils.core import setup, Extension

mod1 = Extension('example._example', sources=["src/example.c"], )

setup(name='Example',
      version='1.0',
      description='An example template',
      author='James Percival',
      author_email='j.percival@imperial.ac.uk',
      packages=['example'],
      ext_modules=[mod1]
     )