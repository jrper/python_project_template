"""Example module in template package."""

import numpy

__all__ = ['cross_2d']

def cross_2d(a, b):
    """Return the z coordinate of a cross product for 2D vectors.
    
    >>> cross_2d((1, 0), (1, 0))
    0
    >>> cross_2d((1, 0), (0, 1))
    1
    """
    return a[0]*b[1]-a[1]*b[0]